#include "starlink.h"

Starlink::Starlink(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Starlink");
}

void Starlink::draw() const {
    drawStarlink(position, aRadians);
}

void Starlink::smash(vector<OrbitingObject *> orbitingObjects) const {
    // TODO: Implement this method
}