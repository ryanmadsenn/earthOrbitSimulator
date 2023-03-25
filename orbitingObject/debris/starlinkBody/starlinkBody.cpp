#include "starlinkBody.h"

StarlinkBody::StarlinkBody(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 2, "StarlinkBody") {}

void StarlinkBody::draw() {
    drawStarlinkBody(position, aRadians);
}

void StarlinkBody::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}