#include "strategietest.h"

StrategieTest::StrategieTest(int rayonActionFuyard):Strategie(rayonActionFuyard)
{
}

Position StrategieTest::decisionFuyard(const std::vector<Strategie*>& tStrategies,const Position& posFuyard,const Position& posPoursuivant)const
{
    return Position(posFuyard.getX()+1,posFuyard.getY()+1);
}

Position StrategieTest::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const Position &posFuyard, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    if (tStrategiesDecouvertes.size()==0)
        return Position(posFuyard.getX(),posFuyard.getY());
    else
        return Position(posFuyard.getX()+1,posFuyard.getY()+1);
}

void StrategieTest::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const Position &dernierePosFuyard, const Position &nouvellePosFuyard) const
{
    tStrategiesDecouvertes.push_back(tStrategiesFuyard[0]);
}




Position StrategieTest::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Position> &posFuyardPossibles, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    return Position();
}

void StrategieTest::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const std::vector<Position> &dernieresPosPossiblesFuyard, const std::vector<Position> &nouvellesPosPossiblesfuyard) const
{

}
