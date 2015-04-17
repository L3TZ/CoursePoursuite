#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(Poursuivant& p, Fuyard& f,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    jeu = new Jeu(p,f);
    this->initFenetre();
}

MainWindow::~MainWindow()
{
    delete jeu;
    delete ui;
}

void MainWindow::lancerJeu()
{
    jeu->lancerJeu();
    majPositionGrille();
}

void MainWindow::tourSuivant(){
    jeu->tourSuivant();
    majPositionGrille();
}

void MainWindow::terminerPartie(){
    jeu->terminerPartie();
    majPositionGrille();
}

void MainWindow::initFenetre(){
    ui->setupUi(this);
    QObject::connect(ui->boutonTourSuiv,SIGNAL(clicked()),this,SLOT(tourSuivant()));
    QObject::connect(ui->boutonFinirPartie,SIGNAL(clicked()),this,SLOT(terminerPartie()));
    QObject::connect(ui->boutonReinit,SIGNAL(clicked()),this,SLOT(initJeu()));
    QObject::connect(ui->boutonQuitter,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->histoP,SIGNAL(clicked(QModelIndex)),this,SLOT(clickOnHistoP()));
    QObject::connect(ui->histoF,SIGNAL(clicked(QModelIndex)),this,SLOT(clickOnHistoF()));
    this->lancerJeu();
}

void MainWindow::initJeu(){
    Poursuivant p = jeu->getPoursuivant();
    Fuyard f = jeu->getFuyard();
    jeu = new Jeu(p,f);
    this->initFenetre();
}

void MainWindow::majPositionGrille(){
    int xF=jeu->getFuyard().getPosActuelle().getX();
    int yF=jeu->getFuyard().getPosActuelle().getY();
    int xP=jeu->getPoursuivant().getPosActuelle().getX();
    int yP=jeu->getPoursuivant().getPosActuelle().getY();

    QString nTour = QString::number(jeu->getHistorique().getNbTours());

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

    majHisto();
}

void MainWindow::majHisto(){
    Historique histo = jeu->getHistorique();

    ui->histoF->clear();
    ui->histoP->clear();

    for (int i = 0; i < histo.getNbTours(); i++){
        Position posP= histo.getPositionPoursuivant(i);
        Position posF=histo.getPositionFuyard(i);

        int xP=posP.getX(); int yP=posP.getY();
        int xF=posF.getX();int yF=posF.getY();

        QString dernierePositionP="X:"+ QString::number(xP)+ ", Y:"+ QString::number(yP);
        ui->histoP->addItem(dernierePositionP);
        QString dernierePositionF="X:"+ QString::number(xF)+ ", Y:"+ QString::number(yF);
        ui->histoF->addItem(dernierePositionF);
    }
}

void MainWindow::clickOnHistoP()
{
     //Récupération de l'index sur lequel l'utilisateur click
    int currentIndex=ui->histoP->currentRow();

    Historique histo = jeu->getHistorique();
    Position posP = histo.getPositionPoursuivant(currentIndex);

    //Affichage de la position demandé
    ui->grille->clearContents(); //On efface la grille
    majPositionGrille(); //On réaffiche les positions actuelles de P et F
    ui->grille->setItem(posP.getX(),posP.getY(),new QTableWidgetItem);
    ui->grille->item(posP.getX(),posP.getY())->setBackground(QColor(255, 0, 0, 100));
       /*QFont f("Times", 10, QFont::Bold);
    ui->grille->item(posP.getX(),posP.getY())->setFont(f);
     ui->grille->item(posP.getX(),posP.getY())->setText("X");
     ui->grille->item(posP.getX(),posP.getY())->setTextAlignment(Qt::AlignRight);*/
}

void MainWindow::clickOnHistoF()
{
    //Récupération de l'index sur lequel l'utilisateur click
    int currentIndex=ui->histoF->currentRow();

    Historique histo = jeu->getHistorique();
    Position posF = histo.getPositionFuyard(currentIndex);

    //Affichage de la position demandé
    ui->grille->clearContents(); //On efface la grille
    majPositionGrille(); //On réaffiche les positions actuelles de P et F
    ui->grille->setItem(posF.getX(),posF.getY(),new QTableWidgetItem);
    ui->grille->item(posF.getX(),posF.getY())->setBackground(QColor(0,0,255,100));
}
