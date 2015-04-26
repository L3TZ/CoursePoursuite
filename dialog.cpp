#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //connect(ui->fermer,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->quitter,SIGNAL(clicked()),this,SLOT(quitterApplication()));
    connect(ui->valider,SIGNAL(clicked()),this,SLOT(recupValeur()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::recupValeur(){
    QString yF = ui->yPosF->text();
    QString yP = ui->yPosP->text();
    QString xF = ui->xPosF->text();
    QString xP = ui->xPosP->text();

    QString position = yF +"," +xF+","+yP+","+xP;
    emit envoyerValeur(position);
    this->close();
}

void Dialog::quitterApplication(){
    int quit = 1;
    emit quitter();
    this->close();
}
