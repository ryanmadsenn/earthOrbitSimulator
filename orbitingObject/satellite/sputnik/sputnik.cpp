#include "sputnik.h"

Sputnik::Sputnik(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Sputnik");
}

void Sputnik::draw() {
    drawSputnik(position, aRadians);
}

void Sputnik::smash(vector<OrbitingObject*> orbitingObjects) {
    // TODO: Implement this.
}