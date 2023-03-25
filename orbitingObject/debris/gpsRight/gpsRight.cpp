#include "gpsRight.h"

/*******************************************************
 * Description: Constructor for GPSRight.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
GPSRight::GPSRight(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "gpsRight") {}

/*******************************************************
 * Description: Draws the GPSRight.
 *******************************************************/
void GPSRight::draw() {
    drawGPSRight(position, aRadians);
}

/*******************************************************
 * Description: Breaks the GPSRight into fragments.
 * @param orbitingObjects
 *******************************************************/
void GPSRight::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}