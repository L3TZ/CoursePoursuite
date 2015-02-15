#ifndef STRATEGIE_H
#define STRATEGIE_H

#include <vector>
#include "position.h"

class Strategie
{
private:
    const int rayonActionFuyard;
public:
    Strategie(int rayonActionFuyard);

    int getRayonActionFuyard()const;

    virtual Position decisionFuyard(const std::vector<Strategie*>& tStrategies,const Position& posFuyard,const Position& posPoursuivant)const=0;  //retourne le déplacement du fuyard en fonction de ses stratégies et des positions des 2
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const Position& posFuyard,const Position& posPoursuivant,int rayonActionPoursuivant)const=0; //retourne le déplacement du poursuivant en fonction des stratégies qu'il a découvert et des positions des 2
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Position>& posFuyardPossibles,const Position& posPoursuivant,int rayonActionPoursuivant)const=0;   //retourne le déplacement du poursuivant en fonction des stratégies qu'il a découvert et de l'ensemble des positions possibles du fuyard (dans le cas ou il n'a que la distance qui les sépare)
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const Position& dernierePosFuyard,const Position& nouvellePosFuyard)const=0;  //met à jour les stratégies découvertes par P en fonction du dernier déplacement de F en sachant sa position exacte
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const std::vector<Position>& dernieresPosPossiblesFuyard,const std::vector<Position>& nouvellesPosPossiblesfuyard)const=0;    //met à jour les stratégies découvertes par P en fonction du dernier déplacement de F ne sachant pas sa position exacte
};

#endif // STRATEGIE_H
