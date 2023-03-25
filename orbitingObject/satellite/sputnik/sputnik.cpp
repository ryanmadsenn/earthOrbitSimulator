#include "sputnik.h"

/*******************************************************
 * Description: Constructor for Sputnik.
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
 * Description: Draws the Sputnik.
 *******************************************************/
void Sputnik::draw() {
    drawSputnik(position, aRadians);
}

/*******************************************************
 * Description: Breaks the Sputnik into fragments.
 * @param orbitingObjects
 *******************************************************/
void Sputnik::smash(vector<OrbitingObject*> * orbitingObjects) {
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
}