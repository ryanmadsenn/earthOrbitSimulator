#include "gps.h"

/*******************************************************
 *
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 *******************************************************/
GPS::GPS(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "GPS");
}

/*******************************************************
 *
 ******************************************************/
void GPS::draw() {
    drawGPS(position, aRadians);
}

/*******************************************************
 *
 * @param orbitingObjects
 *******************************************************/
void GPS::smash(vector<OrbitingObject *> orbitingObjects) {
    // TODO: Implement this method
}