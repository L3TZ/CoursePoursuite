#ifndef STRATEGIECYCLERANDOM_H
#define STRATEGIECYCLERANDOM_H

#include "strategiecycle.h"


class StrategieCycleRandom : public StrategieCycle
{
public:
    StrategieCycleRandom(int rayonActionFuyard,int ajoutX,int ajoutY,int positionDansCycle);

    bool correspondancePosition()const;
    Position calculNouvellePosition(const Position& posFuyard)const;

    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const Position& posFuyard,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Position>& posFuyardPossibles,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const Position& dernierePosFuyard,const Position& nouvellePosFuyard)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const std::vector<Position>& dernieresPosPossiblesFuyard,const std::vector<Position>& nouvellesPosPossiblesfuyard)const;

};

#endif // STRATEGIECYCLERANDOM_H
