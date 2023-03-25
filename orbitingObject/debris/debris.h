#pragma once
#include "../orbitingObject.h"

class Debris : public OrbitingObject {
public:
    Debris(Position position, double velocity, double aRadians);

    void applyOffset();

    void applyKick();

};
