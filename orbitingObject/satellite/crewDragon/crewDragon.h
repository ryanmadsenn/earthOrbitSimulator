#pragma once
#include "../satellite.h"

class CrewDragon : public Satellite {
public:
    CrewDragon(Position position, double dx, double dy, double aRadins, double radius);
    CrewDragon(double x, double y) : Satellite(x, y) {};
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};
