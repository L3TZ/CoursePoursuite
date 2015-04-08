#include "strategiequart.h"
#include <iostream>

StrategieQuart::StrategieQuart(int rayonActionFuyard, int relativeX, int relativeY, int ajoutX, int ajoutY):Strategie(rayonActionFuyard),relativeX(relativeX),relativeY(relativeY),ajoutX(ajoutX),ajoutY(ajoutY)
{

}

bool StrategieQuart::correspondancePosition(const Position &posFuyard, const Position &posPoursuivant) const
{
    bool egalX=posFuyard.getX()==posPoursuivant.getX();
    bool egalY=posFuyard.getY()==posPoursuivant.getY();
    bool diffX=posFuyard.getX()>posPoursuivant.getX();
    bool diffY=posFuyard.getY()>posPoursuivant.getY();

    if ((egalX && relativeX!=0) || (egalY && relativeY!=0))
        return false;
    if ((!egalX && (diffX && relativeX!=-1)) || (!egalY && (diffY && relativeY!=-1)))
        return false;
    if ((!egalX && (!diffX && relativeX!=1)) || (!egalY && (!diffY && relativeY!=1)))
        return false;
    return true;
}

Position StrategieQuart::calculNouvellePosition(const Position &posFuyard) const
{
    return Position(posFuyard.getX()+ajoutX,posFuyard.getY()+ajoutY);
}

Position StrategieQuart::decisionFuyard(const std::vector<Strategie *> &tStrategies, const Position &posFuyard, const Position &posPoursuivant) const
{
    for (unsigned int i=0;i<tStrategies.size();i++)
    {
        if (dynamic_cast<StrategieQuart*>(tStrategies[i])->correspondancePosition(posFuyard,posPoursuivant))
        {
            std::cout<<"--Utilisation stratégie n°"<<i+1<<"--"<<std::endl;
            return dynamic_cast<StrategieQuart*>(tStrategies[i])->calculNouvellePosition(posFuyard);
        }
    }
    return posFuyard;
}

Position StrategieQuart::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const Position &posFuyard, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    for (unsigned int i=0;i<tStrategiesDecouvertes.size();i++)
    {
        if (dynamic_cast<StrategieQuart*>(tStrategiesDecouvertes[i])->correspondancePosition(posFuyard,posPoursuivant))
        {
            return Position::reductionRayonAction(posPoursuivant,dynamic_cast<StrategieQuart*>(tStrategiesDecouvertes[i])->calculNouvellePosition(posFuyard),rayonActionPoursuivant);
        }
    }
    return Position::reductionRayonAction(posPoursuivant,posFuyard,rayonActionPoursuivant);
}

void StrategieQuart::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const Position &dernierePosFuyard, const Position &nouvellePosFuyard) const
{
    for (unsigned int i=0;i<tStrategiesDecouvertes.size();i++)
    {
        if (dynamic_cast<StrategieQuart*>(tStrategiesDecouvertes[i])->correspondancePosition(dernierePosFuyard,dernierePosPoursuivant))
        {
            return ;
        }
    }
    for (unsigned int i=0;i<tStrategiesFuyard.size();i++)
    {
        if (dynamic_cast<StrategieQuart*>(tStrategiesFuyard[i])->correspondancePosition(dernierePosFuyard,dernierePosPoursuivant))
        {
            tStrategiesDecouvertes.push_back(tStrategiesFuyard[i]);
        }
    }
}






Position StrategieQuart::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Position> &posFuyardPossibles, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    return Position();
}

void StrategieQuart::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const std::vector<Position> &dernieresPosPossiblesFuyard, const std::vector<Position> &nouvellesPosPossiblesfuyard) const
{

}

