#ifndef JOUEUR_H
#define JOUEUR_H

#include "position.h"

class Joueur
{
protected:
    Position posActuelle;
public:
    Joueur();
    Joueur(Position pos);

    void avancer(const Position& decision);
};

#endif // JOUEUR_H
