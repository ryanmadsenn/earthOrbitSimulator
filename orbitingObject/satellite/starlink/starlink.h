/*************************************************************
 * Header File:
 *    Starlink : Class representing a Starlink
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once
#include "../satellite.h"
#include "../../debris/starlinkBody/starlinkBody.h"
#include "../../debris/starlinkArray/starlinkArray.h"

class Starlink : public Satellite {
public:
    Starlink(Position position, double dx, double dy, double aRadins, double radius);
    Starlink(double x, double y) : Satellite(x, y) {};
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};