#include "hubble.h"

Hubble::Hubble(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Hubble");
}

void Hubble::draw() const {
    drawHubble(position, aRadians);
}

void Hubble::smash(vector<OrbitingObject *> orbitingObjects) const {
    // TODO: Implement this method
}