#include "gpsLeft.h"

/*******************************************************
 * Description: Constructor for GPSLeft.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
GPSLeft::GPSLeft(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "GPSLeft") {}

/*******************************************************
 * Description: Draws the GPSLeft.
 *******************************************************/
void GPSLeft::draw() {
    drawGPSLeft(position, aRadians);
}

/*******************************************************
 * Description: Breaks the GPSLeft into fragments.
 * @param orbitingObjects
 *******************************************************/
void GPSLeft::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}