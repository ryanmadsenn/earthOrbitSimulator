#pragma once
#include "../satellite.h"

class Starlink : public Satellite {
public:
    Starlink(Position position, double dx, double dy, double aRadins, double radius);
    Starlink(double x, double y) : Satellite(x, y) {};
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};