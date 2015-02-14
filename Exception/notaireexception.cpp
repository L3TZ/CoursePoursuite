#include "notaireexception.h"
#include <sstream>

NotaireException::NotaireException(const char* msg,int line)
{
    ostringstream oss;
    oss<<"Erreur ligne "<<line<<" : "<<msg;
    this->msg=oss.str();
}

NotaireException::~NotaireException()throw()
{

}

const char* NotaireException::what()const throw()
{
    return msg.c_str();
}
