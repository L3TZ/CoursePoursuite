#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(Poursuivant& p, Fuyard& f,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    jeu(p,f)
{
    ui->setupUi(this);
    QObject::connect(ui->boutonTourSuiv,SIGNAL(clicked()),this,SLOT(tourSuivant()));
    QObject::connect(ui->boutonFinirPartie,SIGNAL(clicked()),this,SLOT(terminerPartie()));
    QObject::connect(ui->boutonQuitter,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->histoP,SIGNAL(clicked(QModelIndex)),this,SLOT(clickOnHistoP()));
    QObject::connect(ui->histoF,SIGNAL(clicked(QModelIndex)),this,SLOT(clickOnHistoF()));
    this->lancerJeu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lancerJeu()
{
    jeu.lancerJeu();
    majPositionGrille();
}

void MainWindow::tourSuivant(){
    majHisto();
    jeu.tourSuivant();
    majPositionGrille();
}

void MainWindow::terminerPartie(){
    majHisto();
    jeu.terminerPartie();
    majPositionGrille();
}

void MainWindow::majPositionGrille(){
    int xF=jeu.getFuyard().getPosActuelle().getX();
    int yF=jeu.getFuyard().getPosActuelle().getY();
    int xP=jeu.getPoursuivant().getPosActuelle().getX();
    int yP=jeu.getPoursuivant().getPosActuelle().getY();

    QString nTour = QString::number(jeu.getHistorique().getNbTours());

    QString positionF="X:"+QString::number(xF)+"  Y:"+ QString::number(yF);

    QString positionP="X:"+QString::number(xP)+"  Y:"+ QString::number(yP);


    ui->grille->clearContents();
    ui->labelNumTour->setText(nTour);

    ui->labelPosF->setText(positionF);
    ui->labelPosP->setText(positionP);

    if (xF != xP || yF != yP){

        ui->grille->setItem(xF,yF,new QTableWidgetItem);
        ui->grille->item(xF,yF)->setBackground(Qt::blue);

        ui->grille->setItem(xP,yP,new QTableWidgetItem);
        ui->grille->item(xP,yP)->setBackground(Qt::red);
    }
    else {
        ui->grille->setItem(xF,yF,new QTableWidgetItem);
        ui->grille->item(xF,yF)->setBackground(Qt::green);
    }
}

void MainWindow::majHisto(){
    Historique histo = jeu.getHistorique();
    Position lastPosP= histo.getDernierePositionPoursuivant();
    Position lastPosF=histo.getDernierePositionFuyard();

    int xP=lastPosP.getX(); int yP=lastPosP.getY();
    int xF=lastPosF.getX();int yF=lastPosF.getY();

    QString dernierePositionP="X:"+ QString::number(xP)+ ", Y:"+ QString::number(yP);
    ui->histoP->addItem(dernierePositionP);
    QString dernierePositionF="X:"+ QString::number(xF)+ ", Y:"+ QString::number(yF);
    ui->histoF->addItem(dernierePositionF);
}

void MainWindow::clickOnHistoP()
{
     //Récupération de l'index sur lequel l'utilisateur click
    int currentIndex=ui->histoP->currentRow();
    QString texte = ui->histoP->item(currentIndex)->text();
    //Appel de la méthode pour l'affichage avec le texte et une couleur
    affichePositionHisto(texte,(QColor(255, 0, 0, 100)));
}

void MainWindow::clickOnHistoF()
{
    //Récupération de l'index sur lequel l'utilisateur click
    int currentIndex=ui->histoF->currentRow();
    QString texte = ui->histoF->item(currentIndex)->text();
    //Appel de la méthode pour l'affichage avec le texte et une couleur
    affichePositionHisto(texte,QColor(0,0,255,100));
}

void MainWindow::affichePositionHisto(QString texte, QColor color){

    //Récupération du X
    QString x0=texte.section(':',1,1);
    QString x1=x0.section(",",0,0);

    //Récupération du Y
    QString y0=texte.section(':',2,2);
    QString y1=y0.section(",",0,0);

    //Affichage de la position demandé
    ui->grille->clearContents(); //On efface la grille
    majPositionGrille(); //On réaffiche les positions actuelles de P et F
    ui->grille->setItem(x1.toInt(),y1.toInt(),new QTableWidgetItem);
    ui->grille->item(x1.toInt(),y1.toInt())->setBackground(color);
}
