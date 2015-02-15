#ifndef STRATEGIEEXCEPTION_H
#define STRATEGIEEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class StrategieException : public exception
{
private:
    string msg;
public:
    StrategieException(const char* msg,int line);
    virtual ~StrategieException()throw();
    virtual const char* what()const throw();
};

#endif // STRATEGIEEXCEPTION_H
