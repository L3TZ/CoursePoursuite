#ifndef POURSUIVANTEXCEPTIONAUCUNESTRATEGIEFUYARD_H
#define POURSUIVANTEXCEPTIONAUCUNESTRATEGIEFUYARD_H

#include "poursuivantexception.h"

class PoursuivantExceptionAucuneStrategieFuyard : public PoursuivantException
{
public:
    PoursuivantExceptionAucuneStrategieFuyard(const char* Msg,int line);
    virtual ~PoursuivantExceptionAucuneStrategieFuyard()throw();
};

#endif // POURSUIVANTEXCEPTIONAUCUNESTRATEGIEFUYARD_H
