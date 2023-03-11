#include "gps.h"

GPS::GPS(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "GPS");
}

void GPS::draw() {
    drawGPS(position, aRadians);
}

void GPS::smash(vector<OrbitingObject *> orbitingObjects) {
    // TODO: Implement this method
}