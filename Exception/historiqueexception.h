#ifndef HISTORIQUEEXCEPTION_H
#define HISTORIQUEEXCEPTION_H

#include <exception>
#include <string>

class HistoriqueException : public exception
{
private:
    string msg;
public:
    HistoriqueException(const char* msg,int line);
    virtual ~HistoriqueException()throw();
    virtual const char* what()const throw();
};

#endif // HISTORIQUEEXCEPTION_H
