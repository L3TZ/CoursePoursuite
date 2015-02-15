#ifndef HISTORIQUEEXCEPTIONHISTORIQUEVIDE_H
#define HISTORIQUEEXCEPTIONHISTORIQUEVIDE_H

#include "historiqueexception.h"

class HistoriqueExceptionHistoriqueVide : public HistoriqueException
{
public:
    HistoriqueExceptionHistoriqueVide(const char* Msg,int line);
    virtual ~HistoriqueExceptionHistoriqueVide()throw();
};

#endif // HISTORIQUEEXCEPTIONHISTORIQUEVIDE_H
