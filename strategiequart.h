#ifndef STRATEGIEQUART_H
#define STRATEGIEQUART_H

#include "strategie.h"

class StrategieQuart : public Strategie
{
private:
    const int relativeX;
    const int relativeY;
    const int ajoutX;
    const int ajoutY;
public:
    StrategieQuart(int rayonActionFuyard,int relativeX,int relativeY,int ajoutX,int ajoutY);

    bool correspondancePosition(const Position& posFuyard,const Position& posPoursuivant)const;
    Position calculNouvellePosition(const Position& posFuyard)const;

    virtual Position decisionFuyard(const std::vector<Strategie*>& tStrategies,const Position& posFuyard,const Position& posPoursuivant)const;
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const Position& posFuyard,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Position>& posFuyardPossibles,const Position& posPoursuivant,int rayonActionPoursuivant)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const Position& dernierePosFuyard,const Position& nouvellePosFuyard)const;
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const std::vector<Position>& dernieresPosPossiblesFuyard,const std::vector<Position>& nouvellesPosPossiblesfuyard)const;
};

#endif // STRATEGIEQUART_H
