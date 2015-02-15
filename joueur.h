#ifndef JOUEUR_H
#define JOUEUR_H

#include "position.h"
#include <vector>
#include "strategie.h"

class Joueur
{
protected:
    Position posActuelle;
    std::vector<Strategie*> tStrategiesFuyard;
public:
    Joueur();
    Joueur(Position pos);

    void setStrategiesFuyard(const std::vector<Strategie*>& tStrategiesFuyard);
    void avancer(const Position& decision);
};

#endif // JOUEUR_H
