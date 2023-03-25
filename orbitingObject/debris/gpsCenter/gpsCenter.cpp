#include "gpsCenter.h"

GPSCenter::GPSCenter(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 7, "GPSCenter") {}

void GPSCenter::draw() {
    drawGPSCenter(position, aRadians);
}

void GPSCenter::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}
