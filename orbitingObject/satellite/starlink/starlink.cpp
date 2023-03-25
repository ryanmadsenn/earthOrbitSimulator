#include "starlink.h"

/*******************************************************
 * Description: Constructor for Starlink.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 *******************************************************/
Starlink::Starlink(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Starlink");
}

/*******************************************************
 * Description: Draws the Starlink.
 *******************************************************/
void Starlink::draw() {
    drawStarlink(position, aRadians);
}

/*******************************************************
 * Description: Smashes the Starlink.
 * @param orbitingObjects
 *******************************************************/
void Starlink::smash(vector<OrbitingObject *> * orbitingObjects) {
    orbitingObjects->push_back(new StarlinkBody(position, dx, dy, aRadians));
    orbitingObjects->push_back(new StarlinkArray(position, dx, dy, aRadians));
}