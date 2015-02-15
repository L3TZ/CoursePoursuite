#include "poursuivant.h"
#include "Exception/poursuivantexceptionaucunestrategiefuyard.h"
#include "Exception/poursuivantexceptionmauvaisrayonaction.h"
#include "Exception/poursuivantexceptionmauvaiseprofondeurhisto.h"
#include "Exception/poursuivantexceptionapprentissageimpossible.h"

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

void Poursuivant::apprentissage(const Historique &historiqueJeu)
{
    int profondeurHistoriqueReelle=historiqueJeu.getNbTours();
    Position dernierePosPoursuivant;
    Position dernierePosFuyard;
    Position nouvellePosFuyard;
    int indiceHistorique;
    Position posPoursuivantHisto;
    Position posFuyardHisto;
    int distanceFuyard;
    std::vector<Position> cercleFuyardTmp;
    std::vector<Position> nouvellesPosPossiblesFuyard;
    std::vector<Position> dernieresPosPossiblesFuyard;
    int rayonActionFuyard=tStrategiesFuyard[0]->getRayonActionFuyard();

    if (profondeurHistoriqueReelle<2)
        throw PoursuivantExceptionApprentissageImpossible("Apprentissage impossible, la partie vient de commencer.",__LINE__);

    if (visibiliteFuyard)
    {
        dernierePosPoursuivant=historiqueJeu.getPositionPoursuivant(profondeurHistoriqueReelle-1);
        dernierePosFuyard=historiqueJeu.getPositionFuyard(profondeurHistoriqueReelle-1);
        nouvellePosFuyard=historiqueJeu.getDernierePositionFuyard();
        tStrategiesFuyard[0]->apprentissagePoursuivant(tStrategiesDecouvertes,tStrategiesFuyard,dernierePosPoursuivant,dernierePosFuyard,nouvellePosFuyard);
    }
    else
    {
        dernierePosPoursuivant=historiqueJeu.getPositionPoursuivant(profondeurHistoriqueReelle-1);
        indiceHistorique=profondeurHistoriqueReelle-profondeurHistorique;
        if (indiceHistorique<0 || profondeurHistorique==0)
            indiceHistorique=0;

        while (indiceHistorique<profondeurHistoriqueReelle)
        {
            posPoursuivantHisto=historiqueJeu.getPositionPoursuivant(indiceHistorique);
            posFuyardHisto=historiqueJeu.getPositionFuyard(indiceHistorique);
            distanceFuyard=Position::calculDistance(posPoursuivantHisto,posFuyardHisto);
            cercleFuyardTmp=Position::cerclePosition(posPoursuivantHisto,distanceFuyard);
            nouvellesPosPossiblesFuyard=Position::intersectionCercle(nouvellesPosPossiblesFuyard,cercleFuyardTmp,rayonActionFuyard);

            if (indiceHistorique==profondeurHistoriqueReelle-2)
                dernieresPosPossiblesFuyard=nouvellesPosPossiblesFuyard;
            indiceHistorique++;
        }
        tStrategiesFuyard[0]->apprentissagePoursuivant(tStrategiesDecouvertes,tStrategiesFuyard,dernierePosPoursuivant,dernieresPosPossiblesFuyard,nouvellesPosPossiblesFuyard);
    }
}
