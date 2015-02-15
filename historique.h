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
    void ajoutEntree(Position posFuyard,Position posPoursuivant);
    Position getPositionFuyard(int ind)const;
    Position getPositionPoursuivant(int ind)const;
};

#endif // HISTORIQUE_H
