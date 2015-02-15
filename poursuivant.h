#ifndef POURSUIVANT_H
#define POURSUIVANT_H

#include "joueur.h"
#include <vector>
#include "strategie.h"
#include "historique.h"

class Poursuivant : public Joueur
{
private:
    const int rayonAction;
    std::vector<Strategie*> tStrategiesDecouvertes;
    const bool visibiliteFuyard;    //vrai si on connait la position du fuyard, faux si on a seulement sa distance
    const int profondeurHistorique; //taille de la mémoire des coups joués, 0 pour infini
public:
    Poursuivant(int rayonAction,bool visibiliteFuyard,int profondeurHistorique);

    Position donnerDecision(const Historique& historiqueJeu)const;
    void apprentissage(const Historique& historiqueJeu);
};

#endif // POURSUIVANT_H
