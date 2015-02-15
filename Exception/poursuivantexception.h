#ifndef POURSUIVANTEXCEPTION_H
#define POURSUIVANTEXCEPTION_H


#include <exception>
#include <string>

using namespace std;

class PoursuivantException : public exception
{
private:
    string msg;
public:
    PoursuivantException(const char* msg,int line);
    virtual ~PoursuivantException()throw();
    virtual const char* what()const throw();
};

#endif // POURSUIVANTEXCEPTION_H
