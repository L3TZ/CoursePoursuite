#include "strategie.h"
#include "Exception/strategieexceptionmauvaisrayonaction.h"

Strategie::Strategie(int rayonActionFuyard):rayonActionFuyard(rayonActionFuyard)
{
    if (this->rayonActionFuyard<0)
        throw StrategieExceptionMauvaisRayonAction("Le rayon d'action du fuyard est incorrect (< 0).",__LINE__);
}

int Strategie::getRayonActionFuyard()const
{
    return rayonActionFuyard;
}
