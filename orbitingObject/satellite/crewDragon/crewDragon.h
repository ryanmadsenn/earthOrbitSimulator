#pragma once
#include "../satellite.h"
#include "../../debris/fragment/fragment.h"
#include "../../debris/crewDragonCenter/crewDragonCenter.h"
#include "../../debris/crewDragonRight/crewDragonRight.h"
#include "../../debris/crewDragonLeft/crewDragonLeft.h"



class CrewDragon : public Satellite {
public:
    CrewDragon(Position position, double dx, double dy, double aRadins, double radius);
    CrewDragon(double x, double y) : Satellite(x, y) {};
    void draw() override;
    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};
