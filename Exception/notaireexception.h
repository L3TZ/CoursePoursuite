#ifndef NOTAIREEXCEPTION_H
#define NOTAIREEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class NotaireException : public exception
{
private:
    string msg;
public:
    NotaireException(const char* msg,int line);
    virtual ~NotaireException()throw();
    virtual const char* what()const throw();
};

#endif // NOTAIREEXCEPTION_H
