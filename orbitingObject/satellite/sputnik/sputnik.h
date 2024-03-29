/*************************************************************
 * Header File:
 *    Sputnik : Class representing a Sputnik
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once
#include "../satellite.h"
#include "../../debris/fragment/fragment.h"

class Sputnik : public Satellite {

public:
    Sputnik(Position position, double dx, double dy, double aRadians, double radius);
    Sputnik(double x, double y) : Satellite(x, y) {};
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject*> * orbitingObjects) override;
};