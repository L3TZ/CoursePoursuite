#include "notaire.h"
#include "Exception/notaireexceptiondecisiondejavue.h"

Notaire::Notaire():j1Decision(nullptr),j2Decision(nullptr)
{
}

Notaire::~Notaire()
{
    if (j1Decision!=nullptr)
        delete j1Decision;
    if (j2Decision!=nullptr)
        delete j2Decision;
}

Position Notaire::getJ1Decision()const
{
    if (j1Decision!=nullptr)
        return *j1Decision;
    else
        throw NotaireExceptionAucuneDecision("La décision du joueur 1 n'est pas encore enregistrée.",__LINE__);
}

Position Notaire::getJ2Decision()const
{
    if (j2Decision!=nullptr)
        return *j2Decision;
    else
        throw NotaireExceptionAucuneDecision("La décision du joueur 2 n'est pas encore enregistrée.",__LINE__);
}

void Notaire::setJ1Decision(Position& p)
{
    if (j1Decision!=nullptr)
        throw NotaireExceptionDecisionDejaVue("La décision du joueur 1 est déjà enregistrée.",__LINE__);
    j1Decision=new Position(p);
}

void Notaire::setJ2Decision(Position& p)
{
    if (j2Decision!=nullptr)
        throw NotaireExceptionDecisionDejaVue("La décision du joueur 2 est déjà enregistrée.",__LINE__);
    j2Decision=new Position(p);
}

bool Notaire::tourValide()const
{
    if (j1Decision!=nullptr && j2Decision!=nullptr)
        return true;
    else
        return false;
}

void Notaire::raz()
{
    if (j1Decision!=nullptr)
        delete j1Decision;
    if (j2Decision!=nullptr)
        delete j2Decision;
}
