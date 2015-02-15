#include "poursuivant.h"
#include "Exception/poursuivantexceptionaucunestrategiefuyard.h"
#include "Exception/poursuivantexceptionmauvaisrayonaction.h"
#include "Exception/poursuivantexceptionmauvaiseprofondeurhisto.h"

Poursuivant::Poursuivant(int rayonAction,bool visibiliteFuyard,int profondeurHistorique):rayonAction(rayonAction),visibiliteFuyard(visibiliteFuyard),profondeurHistorique(profondeurHistorique)
{
    if (rayonAction<0)
        throw PoursuivantExceptionMauvaisRayonAction("Le rayon d'action du poursuivant est incorrect (< 0).",__LINE__);
    if (profondeurHistorique<0)
        throw PoursuivantExceptionMauvaiseProfondeurHisto("La profondeur de l'historique est incorrecte (< 0).",__LINE__);
}

Position Poursuivant::donnerDecision(const Historique& historiqueJeu)const
{
    Position decision;

    Position posFuyard;

    int indiceHistorique;
    int profondeurHistoriqueReelle=historiqueJeu.getNbTours();
    std::vector<Position> posPossiblesFuyard;
    std::vector<Position> cercleFuyardTmp;
    int distanceFuyard;
    Position posPoursuivantHisto;
    Position posFuyardHisto;
    int rayonActionFuyard=tStrategiesFuyard[0]->getRayonActionFuyard();

    if (visibiliteFuyard)
    {
        posFuyard=historiqueJeu.getDernierePositionFuyard();
        decision=this->tStrategiesFuyard[0]->decisionPoursuivant(this->tStrategiesDecouvertes,posFuyard,this->posActuelle,this->rayonAction);
    }
    else
    {
        indiceHistorique=profondeurHistoriqueReelle-profondeurHistorique;
        if (indiceHistorique<0 || profondeurHistorique==0)
            indiceHistorique=0;

        while (indiceHistorique<profondeurHistoriqueReelle)
        {
            posPoursuivantHisto=historiqueJeu.getPositionPoursuivant(indiceHistorique);
            posFuyardHisto=historiqueJeu.getPositionFuyard(indiceHistorique);
            distanceFuyard=Position::calculDistance(posPoursuivantHisto,posFuyardHisto);
            cercleFuyardTmp=Position::cerclePosition(posPoursuivantHisto,distanceFuyard);
            posPossiblesFuyard=Position::intersectionCercle(posPossiblesFuyard,cercleFuyardTmp,rayonActionFuyard);

            indiceHistorique++;
        }
        decision=tStrategiesFuyard[0]->decisionPoursuivant(tStrategiesDecouvertes,posPossiblesFuyard,posActuelle,rayonAction);
    }
    return decision;
}

void Poursuivant::setStrategiesFuyard(const std::vector<Strategie *>& tStrategiesFuyard)
{
    if (tStrategiesFuyard.empty())
        throw PoursuivantExceptionAucuneStrategieFuyard("Le fuyard n'a pas de stratégie.",__LINE__);
    this->tStrategiesFuyard=tStrategiesFuyard;
}
