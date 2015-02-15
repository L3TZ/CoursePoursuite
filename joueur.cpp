#include "joueur.h"

Joueur::Joueur()
{
}

Joueur::Joueur(Position pos):posActuelle(pos)
{

}

void Joueur::avancer(const Position& decision)
{
    posActuelle=decision;
}
