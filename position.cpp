#include "position.h"
#include "algorithm"

Position::Position():x(0),y(0)
{
}

Position::Position(int x,int y):x(x),y(y)
{
}

int Position::getX()const
{
    return x;
}

int Position::getY()const
{
    return y;
}

void Position::setX(int x)
{
    this->x=x;
}

void Position::setY(int y)
{
    this->y=y;
}

int Position::calculDistance(const Position &posPoursuivant, const Position &posFuyard)
{
    int diffX=abs(posPoursuivant.getX()-posFuyard.getX());
    int diffY=abs(posPoursuivant.getY()-posFuyard.getY());

    return std::max(diffX,diffY);
}

std::vector<Position> Position::cerclePosition(const Position &posPoursuivant, int distanceFuyard)
{
    int posX=posPoursuivant.getX();
    int posY=posPoursuivant.getY();

    std::vector<Position> cercle;

    for (int tmpX=posX-distanceFuyard;tmpX<=posX+distanceFuyard;tmpX++)
    {
        cercle.push_back(Position(tmpX,posY+distanceFuyard));
    }
    for (int tmpX=posX-distanceFuyard;tmpX<=posX+distanceFuyard;tmpX++)
    {
        cercle.push_back(Position(tmpX,posY-distanceFuyard));
    }
    for (int tmpY=posY-distanceFuyard+1;tmpY<=posY+distanceFuyard-1;tmpY++)
    {
        cercle.push_back(Position(posX+distanceFuyard,tmpY));
    }
    for (int tmpY=posY-distanceFuyard+1;tmpY<=posY+distanceFuyard-1;tmpY++)
    {
        cercle.push_back(Position(posX-distanceFuyard,tmpY));
    }

    return cercle;
}

std::vector<Position> Position::intersectionCercle(const std::vector<Position> cercle1, const std::vector<Position> cercle2, int rayonActionFuyard)
{
    std::vector<Position> nouveauCercle;

    for (unsigned i=0;i<cercle1.size();i++)
    {
        for (unsigned j=0;j<cercle2.size();j++)
        {
            if (Position::calculDistance(cercle1[i],cercle2[j])<=rayonActionFuyard)
                nouveauCercle.push_back(cercle2[j]);
        }
    }

    return nouveauCercle;
}
