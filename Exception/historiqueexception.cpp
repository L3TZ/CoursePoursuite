#include "historiqueexception.h"

HistoriqueException::HistoriqueException(const char* msg,int line)
{
    ostringstream oss;
    oss<<"Erreur ligne "<<line<<" : "<<msg;
    this->msg=oss.str();
}

HistoriqueException::~HistoriqueException()throw()
{

}

const char* HistoriqueException::what()const throw()
{
    return msg.c_str();
}
