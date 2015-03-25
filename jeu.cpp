#include "jeu.h"
#include <iostream>

using namespace std;


Jeu::Jeu(Poursuivant& p,Fuyard& f):P(p),F(f),N(),histo()
{
}

void Jeu::lancerJeu()
{
    Position posP=P.getPosActuelle();
    Position posF=F.getPosActuelle();

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


   // while(posP!=posF){
        this->tourSuivant();

        posP=P.getPosActuelle();
        posF=F.getPosActuelle();

        cout<<"P : [";
        posP.affiche();
        cout<<"]"<<endl;
        cout<<"F : [";
        posF.affiche();
        cout<<"]"<<endl;
  //  }

}

void Jeu::tourSuivant(){

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
}

Position Jeu::getPositionF(){
    return this->F.getPosActuelle();
}

Position Jeu::getPositionP(){
    return this->P.getPosActuelle();
}
