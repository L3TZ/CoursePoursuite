#include "fuyard.h"

Fuyard::Fuyard()
{
}

Position Fuyard::donnerDecision(const Historique& historiqueJeu)const
{
    Position posFuyard=historiqueJeu.getDernierePositionFuyard();
    Position posPoursuivant=historiqueJeu.getDernierePositionPoursuivant();

    return tStrategiesFuyard[0]->decisionFuyard(tStrategiesFuyard,posFuyard,posPoursuivant);

}
