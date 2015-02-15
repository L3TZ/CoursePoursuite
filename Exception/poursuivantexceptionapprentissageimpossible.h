#ifndef POURSUIVANTEXCEPTIONAPPRENTISSAGEIMPOSSIBLE_H
#define POURSUIVANTEXCEPTIONAPPRENTISSAGEIMPOSSIBLE_H

#include "poursuivantexception.h"

class PoursuivantExceptionApprentissageImpossible : public PoursuivantException
{
public:
    PoursuivantExceptionApprentissageImpossible(const char* Msg,int line);
    virtual ~PoursuivantExceptionApprentissageImpossible()throw();
};

#endif // POURSUIVANTEXCEPTIONAPPRENTISSAGEIMPOSSIBLE_H
