#ifndef JEU_H
#define JEU_H

#include "poursuivant.h"
#include "fuyard.h"
#include "notaire.h"
#include "historique.h"

class Jeu
{
private:
    Poursuivant P;
    Fuyard F;
    Notaire N;
    Historique histo;
public:
    Jeu(Poursuivant& p, Fuyard& f);

    void lancerJeu();

};

#endif // JEU_H
