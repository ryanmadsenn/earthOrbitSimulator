#pragma once
#include "../orbitingObject.h"

class Satellite : public OrbitingObject {
protected:
    Satellite();
    Satellite(double x, double y) : OrbitingObject(x,y) {};
};
