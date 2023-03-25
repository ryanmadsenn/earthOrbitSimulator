#include "gpsCenter.h"

/*******************************************************
 * Description: Constructor for GPSCenter.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
GPSCenter::GPSCenter(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 7, "GPSCenter") {}

/*******************************************************
 * Description: Draws the GPSCenter.
 *******************************************************/
void GPSCenter::draw() {
    drawGPSCenter(position, aRadians);
}

/*******************************************************
 * Description: Breaks the GPSCenter into fragments.
 * @param orbitingObjects
 *******************************************************/
void GPSCenter::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}
