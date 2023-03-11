#include "hubble.h"

Hubble::Hubble(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Hubble");
}

void Hubble::draw() {
    drawHubble(position, aRadians);
}

void Hubble::smash(vector<OrbitingObject *> orbitingObjects) {
    // TODO: Implement this method
}