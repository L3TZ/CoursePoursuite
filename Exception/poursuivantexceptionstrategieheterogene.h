#ifndef POURSUIVANTEXCEPTIONSTRATEGIEHETEROGENE_H
#define POURSUIVANTEXCEPTIONSTRATEGIEHETEROGENE_H

#include "poursuivantexception.h"

class PoursuivantExceptionStrategieHeterogene : public PoursuivantException
{
public:
    PoursuivantExceptionStrategieHeterogene(const char* Msg,int line);
    virtual ~PoursuivantExceptionStrategieHeterogene()throw();
};

#endif // POURSUIVANTEXCEPTIONSTRATEGIEHETEROGENE_H
