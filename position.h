#ifndef POSITION_H
#define POSITION_H

#include <vector>

class Position
{
private:
    int x;
    int y;
public:
    Position();
    Position(int x,int y);
    int getX()const;
    int getY()const;
    void setX(int x);
    void setY(int y);

    static int calculDistance(const Position& posPoursuivant,const Position& posFuyard);
    static std::vector<Position> cerclePosition(const Position& posPoursuivant,int distanceFuyard);
    static std::vector<Position> intersectionCercle(const std::vector<Position> cercle1, const std::vector<Position> cercle2,int rayonActionFuyard);

};

#endif // POSITION_H
