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

    virtual Position decisionFuyard(std::vector<Strategie*>& tStrategies,Position& posFuyard,Position& posPoursuivant)const=0;  //retourne le déplacement du fuyard en fonction de ses stratégies et des positions des 2
    virtual Position decisionPoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,Position& posFuyard, Position& posPoursuivant,int rayonActionPoursuivant)const=0; //retourne le déplacement du poursuivant en fonction des stratégies qu'il a découvert et des positions des 2
    virtual Position decisionPoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,std::vector<Position>& posFuyardPossibles, Position& posPoursuivant,int rayonActionPoursuivant)const=0;   //retourne le déplacement du poursuivant en fonction des stratégies qu'il a découvert et de l'ensemble des positions possibles du fuyard (dans le cas ou il n'a que la distance qui les sépare)
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,std::vector<Strategie*>& tStrategiesFuyard,Position& dernierePosPoursuivant,Position& dernierePosFuyard,Position& nouvellePosFuyard)const=0;  //met à jour les stratégies découvertes par P en fonction du dernier déplacement de F en sachant sa position exacte
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,std::vector<Strategie*>& tStrategiesFuyard,Position& dernierePosPoursuivant,std::vector<Position>& dernieresPosPossiblesFuyard,std::vector<Position>& nouvellesPosPossiblesfuyard)const=0;    //met à jour les stratégies découvertes par P en fonction du dernier déplacement de F ne sachant pas sa position exacte
};

#endif // STRATEGIE_H
