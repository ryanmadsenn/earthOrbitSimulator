#include "sputnik.h"

/*******************************************************
 *
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 *******************************************************/
Sputnik::Sputnik(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Sputnik");
}

/*******************************************************
 *
 *******************************************************/
void Sputnik::draw() {
    drawSputnik(position, aRadians);
}

/*******************************************************
 *
 * @param orbitingObjects
 *******************************************************/
void Sputnik::smash(vector<OrbitingObject*> * orbitingObjects) {
    // TODO: Implement this.
}