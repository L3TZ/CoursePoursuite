#include "fuyard.h"
#include "Exception/poursuivantexceptionaucunestrategiefuyard.h"

Fuyard::Fuyard(Position pos):Joueur(pos)
{
}

Position Fuyard::donnerDecision(const Historique& historiqueJeu)const
{
    if (tStrategiesFuyard.size()==0)
        throw PoursuivantExceptionAucuneStrategieFuyard("Le fuyard n'a pas de stratégie, impossible de décider.",__LINE__);

    Position posFuyard=historiqueJeu.getDernierePositionFuyard();
    Position posPoursuivant=historiqueJeu.getDernierePositionPoursuivant();

    return tStrategiesFuyard[0]->decisionFuyard(tStrategiesFuyard,posFuyard,posPoursuivant);

}
