#include "strategiecycle.h"
#include <iostream>

int StrategieCycle::compteurMouvements(0);

StrategieCycle::StrategieCycle(int rayonActionFuyard, int ajoutX, int ajoutY):Strategie(rayonActionFuyard),ajoutX(ajoutX),ajoutY(ajoutY)
{

}

bool StrategieCycle::correspondancePosition(int numeroStrategie) const
{
    if(numeroStrategie!=compteurMouvements)
        return false;

    return true;
}

Position StrategieCycle::calculNouvellePosition(const Position &posFuyard) const
{
    return Position(posFuyard.getX()+ajoutX,posFuyard.getY()+ajoutY);
}

Position StrategieCycle::decisionFuyard(const std::vector<Strategie *> &tStrategies, const Position &posFuyard, const Position &posPoursuivant) const
{
    for (unsigned int i=0;i<tStrategies.size();i++)
    {
        if (dynamic_cast<StrategieCycle*>(tStrategies[i])->correspondancePosition(i))
        {
            std::cout<<"--Utilisation stratégie n°"<<i+1<<"--"<<std::endl;
            compteurMouvements=(compteurMouvements+1)%longueurCycle;
            return dynamic_cast<StrategieCycle*>(tStrategies[i])->calculNouvellePosition(posFuyard);
        }
    }
    return posFuyard;
}

Position StrategieCycle::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const Position &posFuyard, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    for (unsigned int i=0;i<tStrategiesDecouvertes.size();i++)
    {
        if (dynamic_cast<StrategieCycle*>(tStrategiesDecouvertes[i])->correspondancePosition(i))
        {
            return Position::reductionRayonAction(posPoursuivant,dynamic_cast<StrategieCycle*>(tStrategiesDecouvertes[i])->calculNouvellePosition(posFuyard),rayonActionPoursuivant);
        }
    }
    return posFuyard;
}

void StrategieCycle::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const Position &dernierePosFuyard, const Position &nouvellePosFuyard) const
{
    if(tStrategiesDecouvertes.size()==longueurCycle)
    {
        return ;
    }

    tStrategiesDecouvertes.push_back(tStrategiesFuyard[compteurMouvements-1]);

}

Position StrategieCycle::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Position> &posFuyardPossibles, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    return Position();
}

void StrategieCycle::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const std::vector<Position> &dernieresPosPossiblesFuyard, const std::vector<Position> &nouvellesPosPossiblesfuyard) const
{

}
