/*************************************************************
 * Header File:
 *    Debris : The class representing the debris
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once
#include "../orbitingObject.h"

class Debris : public OrbitingObject {
public:
    Debris(Position position, double dx, double dy, double aRadians, double radius, string type);

    void applyOffset();

    void applyKick();
};
