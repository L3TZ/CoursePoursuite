#include "poursuivantexception.h"
#include <sstream>

PoursuivantException::PoursuivantException(const char* msg,int line)
{
    ostringstream oss;
    oss<<"Erreur ligne "<<line<<" : "<<msg;
    this->msg=oss.str();
}

PoursuivantException::~PoursuivantException()throw()
{

}

const char* PoursuivantException::what()const throw()
{
    return msg.c_str();
}
