#include "historique.h"
#include "Exception/historiqueexceptionhorslimites.h"

Historique::Historique():nbTours(0)
{
}

int Historique::getNbTours()const
{
    return nbTours;
}

void Historique::ajoutEntree(Position posFuyard, Position posPoursuivant)
{
    this->histoFuyard.push_back(posFuyard);
    this->histoPoursuivant.push_back(posPoursuivant);
    this->nbTours++;
}

Position Historique::getPositionFuyard(int ind) const
{
    if (ind<0 || ind>=nbTours)
        throw HistoriqueExceptionHorsLimites("L'indice de l'historique demandé est hors limite.",__LINE__);
    return this->histoFuyard[ind];
}

Position Historique::getPositionPoursuivant(int ind) const
{
    if (ind<0 || ind>=nbTours)
        throw HistoriqueExceptionHorsLimites("L'indice de l'historique demandé est hors limite.",__LINE__);
    return this->histoPoursuivant[ind];
}
