#ifndef FUYARD_H
#define FUYARD_H

#include "joueur.h"
#include "historique.h"

class Fuyard : public Joueur
{
public:
    Fuyard(Position pos);

    Position donnerDecision(const Historique& historiqueJeu)const;
};

#endif // FUYARD_H
