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

    affichePosition(posP,posF);

    histo.ajoutEntree(posF,posP);
/*
    Position decisionP;
    Position decisionF;
*/

    cout<<"P : [";
    posP.affiche();
    cout<<"]"<<endl;
    cout<<"F : [";
    posF.affiche();
    cout<<"]"<<endl;


   /* while(posP!=posF){
        this->tourSuivant();

        posP=P.getPosActuelle();
        posF=F.getPosActuelle();

        cout<<"P : [";
        posP.affiche();
        cout<<"]"<<endl;
        cout<<"F : [";
        posF.affiche();
        cout<<"]"<<endl;
    }
  */

}

void MainWindow::tourSuivant(){

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
    Position posP=P.getPosActuelle();
    Position posF=F.getPosActuelle();

    cout<<"P : [";
    posP.affiche();
    cout<<"]"<<endl;
    cout<<"F : [";
    posF.affiche();
    cout<<"]"<<endl;

    affichePosition(posP,posF);
}


void MainWindow::on_boutonTerminer_clicked()
{
    close();
}

void MainWindow::affichePosition(Position posP, Position posF){
    //Affichage position du poursuivant
    int xP=posP.getX(); int yP=posP.getY();
    QString positionP="X :"+QString::number(xP)+" Y :"+ QString::number(yP);
    ui->labelPosP->setText(positionP);

    //Affichage position du fuyard
    int xF=posF.getX(); int yF=posF.getY();
    QString positionF="X :"+QString::number(xF)+" Y :"+ QString::number(yF);
    ui->labelPosF->setText(positionF);
}

