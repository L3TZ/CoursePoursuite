#include "joueur.h"
#include "Exception/poursuivantexceptionaucunestrategiefuyard.h"

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

void Joueur::setStrategiesFuyard(const std::vector<Strategie *>& tStrategiesFuyard)
{
    if (tStrategiesFuyard.empty())
        throw PoursuivantExceptionAucuneStrategieFuyard("Le fuyard n'a pas de stratégie.",__LINE__);
    this->tStrategiesFuyard=tStrategiesFuyard;
}
