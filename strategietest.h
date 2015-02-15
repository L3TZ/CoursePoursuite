#ifndef STRATEGIETEST_H
#define STRATEGIETEST_H

#include "strategie.h"

class StrategieTest : public Strategie
{
public:
    StrategieTest(int rayonActionFuyard);

    virtual Position decisionFuyard(const std::vector<Strategie*>& tStrategies,const Position& posFuyard,const Position& posPoursuivant)const;
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const Position& posFuyard,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Position>& posFuyardPossibles,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const Position& dernierePosFuyard,const Position& nouvellePosFuyard)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const std::vector<Position>& dernieresPosPossiblesFuyard,const std::vector<Position>& nouvellesPosPossiblesfuyard)const;
};

#endif // STRATEGIETEST_H
