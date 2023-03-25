#include "starlinkArray.h"

StarlinkArray::StarlinkArray(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 4, "starlinkArray") {}

void StarlinkArray::draw() {
    drawStarlinkArray(position, aRadians);
}

void StarlinkArray::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}