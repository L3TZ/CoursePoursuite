#include "strategieexception.h"
#include <sstream>

StrategieException::StrategieException(const char* msg,int line)
{
    ostringstream oss;
    oss<<"Erreur ligne "<<line<<" : "<<msg;
    this->msg=oss.str();
}

StrategieException::~StrategieException()throw()
{

}

const char* StrategieException::what()const throw()
{
    return msg.c_str();
}
