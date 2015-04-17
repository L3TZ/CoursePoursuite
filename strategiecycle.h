#ifndef STRATEGIECYCLE_H
#define STRATEGIECYCLE_H

#include "strategie.h"

class StrategieCycle : public Strategie
{
private:
    const int ajoutX;
    const int ajoutY;
    int longueurCycle;
    static int compteurMouvements;

public:
    StrategieCycle(int rayonActionFuyard,int ajoutX,int ajoutY,int longueurCycle);

    bool correspondancePosition(int numeroStrategie)const;
    Position calculNouvellePosition(const Position& posFuyard)const;

    virtual Position decisionFuyard(const std::vector<Strategie*>& tStrategies,const Position& posFuyard,const Position& posPoursuivant)const;
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const Position& posFuyard,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Position>& posFuyardPossibles,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const Position& dernierePosFuyard,const Position& nouvellePosFuyard)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const std::vector<Position>& dernieresPosPossiblesFuyard,const std::vector<Position>& nouvellesPosPossiblesfuyard)const;

};

#endif // STRATEGIECYCLE_H
