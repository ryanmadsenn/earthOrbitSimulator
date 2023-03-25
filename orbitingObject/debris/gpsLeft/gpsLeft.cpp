#include "gpsLeft.h"

GPSLeft::GPSLeft(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "GPSLeft") {}

void GPSLeft::draw() {
    drawGPSLeft(position, aRadians);
}

void GPSLeft::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}