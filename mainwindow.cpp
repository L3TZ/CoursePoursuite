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
    jeu.tourSuivant();
    majPositionGrille();
}

void MainWindow::terminerPartie(){
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

    if (xF != xP || yF != yP){
        ui->labelPosF->setText(positionF);
        ui->labelPosP->setText(positionP);

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

void MainWindow::on_boutonQuitter_clicked()
{
    close();
}
