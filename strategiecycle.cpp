#include "strategiecycle.h"
#include <iostream>

#include "typeinfo"

int StrategieCycle::compteurMouvements(0);

int StrategieCycle::suppositionLongueurCyclePoursuivant(0);

int StrategieCycle::suppositionEtapeCyclePoursuivant(0);

StrategieCycle::StrategieCycle(int rayonActionFuyard, int ajoutX, int ajoutY,int positionDansCycle):Strategie(rayonActionFuyard),ajoutX(ajoutX),ajoutY(ajoutY),positionDansCycle(positionDansCycle)
{

}

bool StrategieCycle::correspondancePosition() const
{
    if(positionDansCycle!=compteurMouvements)
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
        if (dynamic_cast<StrategieCycle*>(tStrategies[i])->correspondancePosition())
        {
            std::cout<<"--Utilisation strategie num"<<i+1<<"--"<<std::endl;
            compteurMouvements=(compteurMouvements+1)%(tStrategies.size());
            return dynamic_cast<StrategieCycle*>(tStrategies[i])->calculNouvellePosition(posFuyard);
        }
    }
    return posFuyard;
}

Position StrategieCycle::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const Position &posFuyard, const Position &posPoursuivant, int rayonActionPoursuivant) const
{

    if (suppositionLongueurCyclePoursuivant == 0)
    {
        return Position::reductionRayonAction(posPoursuivant,posFuyard,rayonActionPoursuivant);
    }
    else
    {
        for (unsigned int i=0;i<tStrategiesDecouvertes.size();i++)
        {
            if (dynamic_cast<StrategieCycle*>(tStrategiesDecouvertes[i])->positionDansCycle == suppositionEtapeCyclePoursuivant)
            {
                return Position::reductionRayonAction(posPoursuivant,dynamic_cast<StrategieCycle*>(tStrategiesDecouvertes[i])->calculNouvellePosition(posFuyard),rayonActionPoursuivant);
            }
        }
        return Position::reductionRayonAction(posPoursuivant,posFuyard,rayonActionPoursuivant);
    }
}

void StrategieCycle::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const Position &dernierePosFuyard, const Position &nouvellePosFuyard) const
{


    if (suppositionLongueurCyclePoursuivant == 0)
    {
        for (unsigned int i=0;i<tStrategiesFuyard.size();i++)
        {
            if (dynamic_cast<StrategieCycle*>(tStrategiesFuyard[i])->positionDansCycle == 0)
            {
                tStrategiesDecouvertes.push_back(tStrategiesFuyard[i]);
            }
        }
        suppositionLongueurCyclePoursuivant++;
        return;
    }
    else
    {
        for (unsigned int i=0;i<tStrategiesDecouvertes.size();i++)
        {
            if (dynamic_cast<StrategieCycle*>(tStrategiesDecouvertes[i])->positionDansCycle == suppositionEtapeCyclePoursuivant)
            {
                if (dynamic_cast<StrategieCycle*>(tStrategiesDecouvertes[i])->calculNouvellePosition(dernierePosFuyard) != nouvellePosFuyard)
                {
                    suppositionLongueurCyclePoursuivant++;
                    suppositionEtapeCyclePoursuivant=0;

                    for (unsigned int j=0;j<tStrategiesFuyard.size();j++)
                    {
                        if (dynamic_cast<StrategieCycle*>(tStrategiesFuyard[j])->positionDansCycle == suppositionLongueurCyclePoursuivant-1)
                        {
                            tStrategiesDecouvertes.push_back(tStrategiesFuyard[j]);
                            return;
                        }
                    }
                    return;
                }
                else
                {
                    suppositionEtapeCyclePoursuivant=(suppositionEtapeCyclePoursuivant+1)%suppositionLongueurCyclePoursuivant;
                    return;
                }
            }
        }
    }
}

Position StrategieCycle::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Position> &posFuyardPossibles, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    return Position();
}

void StrategieCycle::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const std::vector<Position> &dernieresPosPossiblesFuyard, const std::vector<Position> &nouvellesPosPossiblesfuyard) const
{

}
