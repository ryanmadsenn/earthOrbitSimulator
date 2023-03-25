#include "fragment.h"

Fragment::Fragment(Position position, double dx, double dy, double aRadians)
        : Debris(position, dx, dy, aRadians, 2.0, "Fragment") {
    lifespan = random(100, 200);
}

void Fragment::draw() {
    drawFragment(position, aRadians);
}

void Fragment::smash(vector<OrbitingObject *> * orbitingObjects) {
    // Do nothing.
}