#ifndef STRATEGIEEXCEPTIONMAUVAISRAYONACTION_H
#define STRATEGIEEXCEPTIONMAUVAISRAYONACTION_H

#include "strategieexception.h"

class StrategieExceptionMauvaisRayonAction : public StrategieException
{
public:
    StrategieExceptionMauvaisRayonAction(const char* Msg,int line);
    virtual ~StrategieExceptionMauvaisRayonAction()throw();
};

#endif // STRATEGIEEXCEPTIONMAUVAISRAYONACTION_H
