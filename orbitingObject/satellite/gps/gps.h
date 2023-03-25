/*************************************************************
 * Header File:
 *    GPS : Class representing a GPS
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once
#include "../satellite.h"
#include "../../debris/fragment/fragment.h"
#include "../../debris/gpsCenter/gpsCenter.h"
#include "../../debris/gpsLeft/gpsLeft.h"
#include "../../debris/gpsRight/gpsRight.h"

class GPS : public Satellite {
public:
    GPS(Position position, double dx, double dy, double aRadians, double radius);
    GPS(double x, double y) : Satellite(x, y) {};
    virtual void draw() override;
    virtual void smash(vector<OrbitingObject *> * orbitingObjects) override;
};