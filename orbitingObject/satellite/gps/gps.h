#pragma once
#include "orbitingObject/satellite/satellite.h"

class GPS : public Satellite {
public:
    GPS(Position position, double dx, double dy, double aRadians, double radius);
    GPS(double x, double y) : Satellite(x, y) {};
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> orbitingObjects) override;
};