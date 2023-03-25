#include "gpsRight.h"

GPSRight::GPSRight(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "gpsRight") {}

void GPSRight::draw() {
    drawGPSRight(position, aRadians);
}

void GPSRight::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}