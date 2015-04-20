#include <cstdlib>
#include <ctime>

#include "strategiecyclerandom.h"


StrategieCycleRandom::StrategieCycleRandom(int rayonActionFuyard, int ajoutX, int ajoutY,int positionDansCycle):StrategieCycle(rayonActionFuyard,ajoutX,ajoutY,positionDansCycle)
{

}

Position StrategieCycleRandom::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const Position &posFuyard, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    int ajoutX = std::rand() % 3 + (-1);
    int ajoutY = std::rand() % 3 + (-1);

    Position posCible = Position(posFuyard.getX()+ajoutX, posFuyard.getY()+ajoutY);

    return Position::reductionRayonAction(posPoursuivant,posCible,rayonActionPoursuivant);
}

void StrategieCycleRandom::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const Position &dernierePosFuyard, const Position &nouvellePosFuyard) const
{

}

Position StrategieCycleRandom::decisionPoursuivant(const std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Position> &posFuyardPossibles, const Position &posPoursuivant, int rayonActionPoursuivant) const
{
    return Position();
}

void StrategieCycleRandom::apprentissagePoursuivant(std::vector<Strategie *> &tStrategiesDecouvertes, const std::vector<Strategie *> &tStrategiesFuyard, const Position &dernierePosPoursuivant, const std::vector<Position> &dernieresPosPossiblesFuyard, const std::vector<Position> &nouvellesPosPossiblesfuyard) const
{

}
