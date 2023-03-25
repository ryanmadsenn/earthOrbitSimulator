#pragma once
#include "../orbitingObject.h"

class Debris : public OrbitingObject {
public:
    Debris(Position position, double dx, double dy, double aRadians, double radius, string type);

    void applyOffset();

    void applyKick();
};
