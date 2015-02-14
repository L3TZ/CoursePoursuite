#ifndef NOTAIREEXCEPTIONDECISIONDEJAVUE_H
#define NOTAIREEXCEPTIONDECISIONDEJAVUE_H

#include "notaireexception.h"

class NotaireExceptionDecisionDejaVue : public NotaireException
{
public:
    NotaireExceptionDecisionDejaVue(const char* Msg,int line);
    virtual ~NotaireExceptionDecisionDejaVue()throw();
};

#endif // NOTAIREEXCEPTIONDECISIONDEJAVUE_H
