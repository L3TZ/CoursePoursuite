#ifndef NOTAIRE_H
#define NOTAIRE_H

#include "position.h"
#include "Exception/notaireexceptionaucunedecision.h"

class Notaire
{
private:
    Position* j1Decision;   //contient la décision du joueur1 pour le tour courant
    Position* j2Decision;   //contient la décision du joueur2 pour le tour courant
public:
    Notaire();
    ~Notaire();
    Position getJ1Decision()const;
    Position getJ2Decision()const;
    void setJ1Decision(Position& p);
    void setJ2Decision(Position& p);
    bool tourValide()const;     //retourne vrai si on a les 2 décisions, faux sinon
    void raz();     //efface les décisions enregistrées
};

#endif // NOTAIRE_H
