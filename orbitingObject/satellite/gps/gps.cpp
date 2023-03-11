#include "gps.h"

GPS::GPS(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "GPS");
}

void GPS::draw() const {
    drawGPS(position, aRadians);
}

void GPS::smash(vector<OrbitingObject *> orbitingObjects) const {
    // TODO: Implement this method
}