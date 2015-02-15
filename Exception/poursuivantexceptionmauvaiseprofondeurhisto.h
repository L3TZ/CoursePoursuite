#ifndef POURSUIVANTEXCEPTIONMAUVAISEPROFONDEURHISTO_H
#define POURSUIVANTEXCEPTIONMAUVAISEPROFONDEURHISTO_H

#include "poursuivantexception.h"

class PoursuivantExceptionMauvaiseProfondeurHisto : public PoursuivantException
{
public:
    PoursuivantExceptionMauvaiseProfondeurHisto(const char* Msg,int line);
    virtual ~PoursuivantExceptionMauvaiseProfondeurHisto()throw();
};

#endif // POURSUIVANTEXCEPTIONMAUVAISEPROFONDEURHISTO_H
