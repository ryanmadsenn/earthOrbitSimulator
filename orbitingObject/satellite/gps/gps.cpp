#include "gps.h"

/*******************************************************
 * Description: Constructor for GPS.
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
 * Description: draws the GPS.
 ******************************************************/
void GPS::draw() {
    drawGPS(position, aRadians);
}

/*******************************************************
 * Description: Smashes the GPS into fragments.
 * @param orbitingObjects
 *******************************************************/
void GPS::smash(vector<OrbitingObject *> * orbitingObjects) {
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    orbitingObjects->push_back(new GPSCenter(position, dx, dy, aRadians));
    orbitingObjects->push_back(new GPSLeft(position, dx, dy, aRadians));
    orbitingObjects->push_back(new GPSRight(position, dx, dy, aRadians));
}