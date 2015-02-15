#include "jeu.h"

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
        decisionP=P.donnerDecision(histo);
        decisionF=F.donnerDecision(histo);
        N.setFuyardDecision(decisionF);
        N.setPoursuivantDecision(decisionP);

        if (N.tourValide())
        {
            P.avancer(decisionP);
            F.avancer(decisionF);
            histo.ajoutEntree(decisionF,decisionP);
            N.raz();
        }
        posP=P.getPosActuelle();
        posF=F.getPosActuelle();
    }
}
