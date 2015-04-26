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

bool Jeu::testValTropPetite(int valeur){
    if(valeur<0){
        return true;
    }
    else return false;
}

bool Jeu::testValTropGrande(int valeur){
    if(valeur>=200){
        return true;
    }
    else return false;
}


void Jeu::tourSuivant(){
    if (P.getPosActuelle() != F.getPosActuelle()) {

        Position decisionP=P.donnerDecision(histo);
        Position decisionF=F.donnerDecision(histo);
        N.setFuyardDecision(decisionF);
        N.setPoursuivantDecision(decisionP);


        //Calcul du déplacement des joueurs
        int ecartXp = decisionP.getX()-histo.getDernierePositionPoursuivant().getX();
        int ecartYp = decisionP.getY()-histo.getDernierePositionPoursuivant().getY();
        int ecartXf = decisionF.getX()-histo.getDernierePositionFuyard().getX();
        int ecartYf = decisionF.getY()-histo.getDernierePositionFuyard().getY();

        //On sauvegarde les "vraies" positions pour l'historique, en fonction du déplacement demandé
        P.setPosReelle(P.getPosReelle().getX()+ecartXp,P.getPosReelle().getY()+ecartYp);
        F.setPosReelle(F.getPosReelle().getX()+ecartXf,F.getPosReelle().getY()+ecartYf);

        // Si un des deux X a une valeur <0
        if(testValTropPetite(decisionP.getX()) || testValTropPetite(decisionF.getX())){
            decisionP.setX(decisionP.getX()+5);
            decisionF.setX(decisionF.getX()+5);
        }
        // Si un des deux Y a une valeur <0
        if(testValTropPetite(decisionP.getY()) || testValTropPetite(decisionF.getY())){
            decisionP.setY(decisionP.getY()+5);
            decisionF.setY(decisionF.getY()+5);

        }
        // Si un des deux X a une valeur >200
        if(testValTropGrande(decisionP.getX()) || testValTropGrande(decisionF.getX())){
            decisionP.setX(decisionP.getX()-5);
            decisionF.setX(decisionF.getX()-5);

        }
        // Si un des deux Y a une valeur >200
        if(testValTropGrande(decisionP.getY()) || testValTropGrande(decisionF.getY())){
            decisionP.setY(decisionP.getY()-5);
            decisionF.setY(decisionF.getY()-5);

        }

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
