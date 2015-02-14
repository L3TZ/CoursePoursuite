#ifndef NOTAIREEXCEPTIONAUCUNEDECISION_H
#define NOTAIREEXCEPTIONAUCUNEDECISION_H

#include "notaireexception.h"

class NotaireExceptionAucuneDecision : public NotaireException
{
public:
    NotaireExceptionAucuneDecision(const char* Msg,int line);
    virtual ~NotaireExceptionAucuneDecision()throw();
};

#endif // NOTAIREEXCEPTIONAUCUNEDECISION_H
