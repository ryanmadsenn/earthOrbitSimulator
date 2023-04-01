/*************************************************************
 * Header File:
 *    Hubble : Class representing a Hubble
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once
#include "../satellite.h"
#include "../../debris/hubbleTelescope/hubbleTelescope.h"
#include "../../debris/hubbleComputer/hubbleComputer.h"
#include "../../debris/hubbleLeft/hubbleLeft.h"
#include "../../debris/hubbleRight/hubbleRight.h"

class Hubble : public Satellite {
public:
    Hubble(Position position, double dx, double dy, double aRadins, double radius);
    Hubble(double x, double y) : Satellite(x, y) {};
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};
