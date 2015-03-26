#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(Poursuivant& p, Fuyard& f,QWidget *parent) :
    P(p),
    F(f),
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    N(),
    histo()
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
    Position posP=P.getPosActuelle();
    Position posF=F.getPosActuelle();

    histo.ajoutEntree(posF,posP);

    cout<<"P : [";
    posP.affiche();
    cout<<"]"<<endl;
    cout<<"F : [";
    posF.affiche();
    cout<<"]"<<endl;

    majLabGrillePositionsF();
    majLabGrillePositionsP();
    majLabTour();
}

void MainWindow::tourSuivant(){

    Position posP=P.getPosActuelle();
    Position posF=F.getPosActuelle();

    if(posP != posF){
        Position decisionP=P.donnerDecision(histo);
        Position decisionF=F.donnerDecision(histo);
        N.setFuyardDecision(decisionF);
        N.setPoursuivantDecision(decisionP);

        if (N.tourValide())
        {
            P.avancer(decisionP);
            F.avancer(decisionF);
            histo.ajoutEntree(decisionF,decisionP);
            P.apprentissage(histo);
            N.raz();
        }
        posP=P.getPosActuelle();
        posF=F.getPosActuelle();

        cout<<"P : [";
        posP.affiche();
        cout<<"]"<<endl;
        cout<<"F : [";
        posF.affiche();
        cout<<"]"<<endl;

        //Appeler F avant P car clean de la grille
        majLabGrillePositionsF();
        majLabGrillePositionsP();
        majLabTour();
        if(posP==posF)majGrilleJeuTermine(posP);
    }
    else{
        cout<<"Jeu terminé"<<endl;
        majGrilleJeuTermine(posP);
    }
}

//Termine la partie
void MainWindow::terminerPartie(){
    Position posP=P.getPosActuelle();
    Position posF=F.getPosActuelle();
    int cpt=0; //variable pour éviter une boucle infinie

    while(posP!=posF && cpt<1000){
        this->tourSuivant();
        posP=P.getPosActuelle();
        posF=F.getPosActuelle();
        cpt++;
    }
}

//Affichage position du fuyard
void MainWindow::majLabGrillePositionsF(){
    int xF=F.getPosActuelle().getX();
    int yF=F.getPosActuelle().getY();
    QString positionF="X:"+QString::number(xF)+"  Y:"+ QString::number(yF);
    ui->labelPosF->setText(positionF);

    ui->grille->clearContents();
    ui->grille->setItem(xF,yF,new QTableWidgetItem);
    ui->grille->item(xF,yF)->setBackground(Qt::blue);
}

//Affichage position du poursuivant
void MainWindow::majLabGrillePositionsP(){
    int xP=P.getPosActuelle().getX();
    int yP=P.getPosActuelle().getY();
    QString positionP="X:"+QString::number(xP)+"  Y:"+ QString::number(yP);
    ui->labelPosP->setText(positionP);

    ui->grille->setItem(xP,yP,new QTableWidgetItem);
    ui->grille->item(xP,yP)->setBackground(Qt::red);
}

//Affichage numéro du tour
void MainWindow::majLabTour(){
    QString nTour = ui->labelNumTour->text();
    int newNumTour = nTour.toInt();

    newNumTour = newNumTour+1;
    nTour = QString::number(newNumTour);
    ui->labelNumTour->setText(nTour);
}

//Affichage de la position finale en noir
void MainWindow::majGrilleJeuTermine(Position p){
    int x=p.getX();
    int y=p.getY();

    ui->grille->clearContents();
    ui->grille->setItem(x,y,new QTableWidgetItem);
    ui->grille->item(x,y)->setBackground(Qt::black);
}

void MainWindow::on_boutonQuitter_clicked()
{
    close();
}
