/*************************************************************
 * Header File:
 *    Satellite: A class representing a satellite
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once
#include "../orbitingObject.h"

class Satellite : public OrbitingObject {
protected:
    Satellite();
    Satellite(double x, double y) : OrbitingObject(x,y) {};
};
