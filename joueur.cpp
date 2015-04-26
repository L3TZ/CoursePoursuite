#include "joueur.h"
#include "Exception/poursuivantexceptionaucunestrategiefuyard.h"
#include "Exception/poursuivantexceptionstrategieheterogene.h"
#include <typeinfo>

Joueur::Joueur()
{
}

Joueur::Joueur(Position pos):posActuelle(pos),posInitiale(pos),posActReelle(pos)
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

    string typeStrategie=typeid(*tStrategiesFuyard[0]).name();
    int rayonActionFuyard=tStrategiesFuyard[0]->getRayonActionFuyard();
    for (unsigned i=1;i<tStrategiesFuyard.size();i++)
    {
        if ((typeStrategie.compare(typeid(*tStrategiesFuyard[i]).name())!=0) || tStrategiesFuyard[i]->getRayonActionFuyard()!=rayonActionFuyard)
            throw PoursuivantExceptionStrategieHeterogene("Les stratégies du fuyard sont hétérogènes.",__LINE__);
    }
    this->tStrategiesFuyard=tStrategiesFuyard;
}

Position Joueur::getPosInitiale()const
{
    return posInitiale;
}

Position Joueur::getPosActuelle()const
{
    return posActuelle;
}

Position Joueur::getPosReelle()const
{
    return posActReelle;
}

void Joueur::setPosReelle(int X, int Y){
    posActReelle.setX(X);
    posActReelle.setY(Y);
}
