#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(Poursuivant& p, Fuyard& f,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dlg(0)
{
    jeu = new Jeu(p,f);
    this->initJeu();
}

MainWindow::~MainWindow()
{
    delete jeu;
    delete ui;
}


void MainWindow::initJeu()
{
    ui->setupUi(this);
    this->showMaximized();

    dlg = new Dialog(this);
    //On affiche le menu
    showDialogModal();

    connect(dlg, SIGNAL(envoyerValeur(QString)), this, SLOT(recevoirValeur(QString)));
    connect(dlg,SIGNAL(quitter()),this,SLOT(quit()));
    QObject::connect(ui->boutonTourSuiv,SIGNAL(clicked()),this,SLOT(tourSuivant()));
    QObject::connect(ui->boutonFinirPartie,SIGNAL(clicked()),this,SLOT(terminerPartie()));
    QObject::connect(ui->boutonReinitJeu,SIGNAL(clicked()),this,SLOT(showDialogModal()));
    QObject::connect(ui->boutonQuitter,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->histoP,SIGNAL(clicked(QModelIndex)),this,SLOT(clickOnHistoP()));
    QObject::connect(ui->histoF,SIGNAL(clicked(QModelIndex)),this,SLOT(clickOnHistoF()));
    QObject::connect(ui->affHistoF,SIGNAL(clicked()),this,SLOT(afficherHistoF()));
    QObject::connect(ui->affHistoP,SIGNAL(clicked()),this,SLOT(afficherHistoP()));
    this->lancerJeu();
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
    Position posP = jeu->getPoursuivant().getPosActuelle();
    Position posF = jeu->getFuyard().getPosActuelle();
    int cpt=0; //variable pour éviter une boucle infinie
    while(posP!=posF && cpt<1000000000){
        this->tourSuivant();
        posP=jeu->getPoursuivant().getPosActuelle();
        posF=jeu->getFuyard().getPosActuelle();
        cpt++;
    }
}

void MainWindow::majPositionGrille(){
    // On prend les positions réelles pour afficher et mettre dans l'historique
    int xF=jeu->getFuyard().getPosReelle().getX();
    int yF=jeu->getFuyard().getPosReelle().getY();
    int xP=jeu->getPoursuivant().getPosReelle().getX();
    int yP=jeu->getPoursuivant().getPosReelle().getY();

    QString nTour = QString::number(jeu->getHistorique().getNbTours());

    QString positionF="X = "+QString::number(xF)+",  Y = "+ QString::number(yF);

    QString positionP="X = "+QString::number(xP)+",  Y = "+ QString::number(yP);

    ui->grille->clearContents();
    ui->labelNumTour->setText(nTour); //Modification du numéro de tour actuel

    //Modification de la position en cours des joueurs
    ui->labelPosF->setText(positionF);
    ui->labelPosP->setText(positionP);

    //Ce qu'on va afficher dans l'historique des positions
    positionP=nTour+":   "+positionP;
    positionF=nTour+":   "+positionF;

    //Ajout dans l'historique
    ui->histoP->addItem(positionP);
    ui->histoF->addItem(positionF);



    // On prend les positions actuelles sur la grille (relatives)
    // pour déplacer les joueurs sur la grille
    int XF=jeu->getFuyard().getPosActuelle().getX();
    int YF=jeu->getFuyard().getPosActuelle().getY();
    int XP=jeu->getPoursuivant().getPosActuelle().getX();
    int YP=jeu->getPoursuivant().getPosActuelle().getY();

    if (XF != XP || YF != YP){

        ui->grille->setItem(XF,YF,new QTableWidgetItem);
        ui->grille->item(XF,YF)->setBackground(Qt::blue);

        ui->grille->setItem(XP,YP,new QTableWidgetItem);
        ui->grille->item(XP,YP)->setBackground(Qt::red);
    }
    else {
        ui->grille->setItem(XF,YF,new QTableWidgetItem);
        ui->grille->item(XF,YF)->setBackground(Qt::green);
    }
}

void MainWindow::clickOnHistoP()
{
    //Récupération de l'index sur lequel l'utilisateur click
    int currentIndex=ui->histoP->currentRow();

    //Récupération de la position associée à l'index
    Historique histo = jeu->getHistorique();
    Position posP = histo.getPositionPoursuivant(currentIndex);
    // Dernières positions de P et F
    Position lastPosF = jeu->getFuyard().getPosActuelle();
    Position lastPosP = jeu->getPoursuivant().getPosActuelle();

    //Récupération de l'item (case de la grille) à modifier
    QTableWidgetItem* item = ui->grille->item(posP.getX(),posP.getY());

    //Si on est pas sur P ou sur F actuel
    if(posP != lastPosF){
        if(posP != lastPosP){

            if(item != NULL){ // Si Null, on ne peut pas changer le texte car la case "n'existe pas"
                item->setText("X");
            }
            else{
                ui->grille->setItem(posP.getX(),posP.getY(),new QTableWidgetItem);
                ui->grille->item(posP.getX(),posP.getY())->setText("X");
            }
       }
    }
}

void MainWindow::clickOnHistoF()
{
    //Récupération de l'index de l'historique sur lequel l'utilisateur clique
    int currentIndex=ui->histoF->currentRow();

    //Récupération de la position associée à l'index
    Historique histo = jeu->getHistorique();
    Position posF = histo.getPositionFuyard(currentIndex);
    // Dernières positions de P et F
    Position lastPosF = jeu->getFuyard().getPosActuelle();
    Position lastPosP = jeu->getPoursuivant().getPosActuelle();

    //Récupération de l'item (case de la grille) à modifier
    QTableWidgetItem* item = ui->grille->item(posF.getX(),posF.getY());

    //Si on est pas sur P ou sur F actuel
    if(posF != lastPosF){
        if(posF != lastPosP){

            // On vérifie si l'item "existe" déjà
            if(item != NULL) item->setBackground(QColor(0,0,255,100));
            else{
                ui->grille->setItem(posF.getX(),posF.getY(),new QTableWidgetItem);
                ui->grille->item(posF.getX(),posF.getY())->setBackground(QColor(0,0,255,100));
            }
        }
    }
}

void MainWindow::nouveauJeu(int yF,int xF, int yP, int xP){

    //Initialisation de la position de F et P
    Position positionP,positionF;
    positionP.setX(xP); positionP.setY(yP);
    positionF.setX(xF); positionF.setY(yF);

    //Initialisation du jeu
    Poursuivant p = jeu->getPoursuivant();
    p.avancer(positionP);
    p.setPosReelle(positionP.getX(),positionP.getY());
    Fuyard f = jeu->getFuyard();
    f.avancer(positionF);
    f.setPosReelle(positionF.getX(),positionF.getY());
    jeu = new Jeu(p,f);

    this->lancerJeu();
}

void MainWindow::showDialogModal()
{
    // on affiche la boite de dialogue de facon modale
    dlg->setModal(true);
    dlg->show();
}

void MainWindow::recevoirValeur(QString position){
    //On vide les historiques
    ui->histoF->clear();
    ui->histoP->clear();

    //Parse position
    QRegExp rx("[,]");
    QStringList list = position.split(rx,QString::SkipEmptyParts);
    QList <int> pos;
    for (int i=0;i < list.size(); i++){
        pos.append(list.at(i).toInt());
    }
    nouveauJeu(pos.at(0),pos.at(1),pos.at(2),pos.at(3));
}


void MainWindow::quit(){
    this->close();
}

void MainWindow::afficherHistoF(){
    Historique histo = jeu->getHistorique();
    // Dernières positions de P et F
    Position lastPosF = jeu->getFuyard().getPosActuelle();
    Position lastPosP = jeu->getPoursuivant().getPosActuelle();

    for (int i=0; i<histo.getNbTours();i++){
        Position posF=histo.getPositionFuyard(i);

        //Récupération de l'item (case de la grille) à modifier
        QTableWidgetItem* item = ui->grille->item(posF.getX(),posF.getY());
        //On vérifie que l'on efface pas la couleur de la dernière position de P ou F
        if(posF != lastPosF){
            if(posF != lastPosP){

                // On vérifie si l'item "existe" déjà
                if(item != NULL) item->setBackground(QColor(0,0,255,100));
                else{
                    ui->grille->setItem(posF.getX(),posF.getY(),new QTableWidgetItem);
                    ui->grille->item(posF.getX(),posF.getY())->setBackground(QColor(0,0,255,100));
                }
            }
        }
    }  
}

void MainWindow::afficherHistoP(){
    Historique histo = jeu->getHistorique();
    // Dernières positions de P et F
    Position lastPosF = jeu->getFuyard().getPosActuelle();
    Position lastPosP = jeu->getPoursuivant().getPosActuelle();

    for (int i=0; i<histo.getNbTours();i++){
        Position posP=histo.getPositionPoursuivant(i);

        //Récupération de l'item (case de la grille) à modifier
        QTableWidgetItem* item = ui->grille->item(posP.getX(),posP.getY());

        //Si on est pas sur P ou sur F actuel
        if(posP != lastPosF){
            if(posP != lastPosP){

                if(item != NULL) item->setText("X");
                else{// Si Null, on ne peut pas changer le texte car la case "n'existe pas"
                    ui->grille->setItem(posP.getX(),posP.getY(),new QTableWidgetItem);
                    ui->grille->item(posP.getX(),posP.getY())->setText("X");
                }
            }
        }
    }
}
