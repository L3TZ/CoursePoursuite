#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <vector>
#include "position.h"

class Historique
{
private:
 std::vector<Position> histoFuyard;
 std::vector<Position> histoPoursuivant;
 int nbTours;
public:
    Historique();

    int getNbTours()const;
    void ajoutEntree(const Position& posFuyard,const Position& posPoursuivant);
    Position getPositionFuyard(int ind)const;
    Position getPositionPoursuivant(int ind)const;
    Position getDernierePositionFuyard()const;
    Position getDernierePositionPoursuivant()const;
};

#endif // HISTORIQUE_H
