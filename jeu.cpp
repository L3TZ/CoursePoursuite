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

    Position decisionP;
    Position decisionF;

    while (posP!=posF)
    {
        cout<<"P : [";
        posP.affiche();
        cout<<"]"<<endl;
        cout<<"F : [";
        posF.affiche();
        cout<<"]"<<endl;

        decisionP=P.donnerDecision(histo);
        decisionF=F.donnerDecision(histo);
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
    }

    cout<<"P : [";
    posP.affiche();
    cout<<"]"<<endl;
    cout<<"F : [";
    posF.affiche();
    cout<<"]"<<endl;
}
