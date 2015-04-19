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

    cout<<"P : [";
    posP.affiche();
    cout<<"]"<<endl;
    cout<<"F : [";
    posF.affiche();
    cout<<"]"<<endl;

}

void Jeu::tourSuivant(){
    if (P.getPosActuelle() != F.getPosActuelle()) {

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
    } else {
        cout<<"Jeu terminé"<<endl;
    }
}

void Jeu::terminerPartie(){
    Position posP=P.getPosActuelle();
    Position posF=F.getPosActuelle();
    int cpt=0; //variable pour éviter une boucle infinie

    while(posP!=posF && cpt<1000000000){
        this->tourSuivant();
        posP=P.getPosActuelle();
        posF=F.getPosActuelle();
        cpt++;
    }
}

Poursuivant Jeu::getPoursuivant()const{
    return this->P;
}

Fuyard Jeu::getFuyard()const{
    return this->F;
}

Historique Jeu::getHistorique()const{
    return this->histo;
}
