#ifndef HISTORIQUEEXCEPTIONHORSLIMITES_H
#define HISTORIQUEEXCEPTIONHORSLIMITES_H

#include "historiqueexception.h"

class HistoriqueExceptionHorsLimites : public HistoriqueException
{
public:
    HistoriqueExceptionHorsLimites(const char* Msg,int line);
    virtual ~HistoriqueExceptionHorsLimites()throw();
};

#endif // HISTORIQUEEXCEPTIONHORSLIMITES_H
