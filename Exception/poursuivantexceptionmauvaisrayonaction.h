#ifndef POURSUIVANTEXCEPTIONMAUVAISRAYONACTION_H
#define POURSUIVANTEXCEPTIONMAUVAISRAYONACTION_H

#include "poursuivantexception.h"

class PoursuivantExceptionMauvaisRayonAction : public PoursuivantException
{
public:
    PoursuivantExceptionMauvaisRayonAction(const char* Msg,int line);
    virtual ~PoursuivantExceptionMauvaisRayonAction()throw();
};

#endif // POURSUIVANTEXCEPTIONMAUVAISRAYONACTION_H
