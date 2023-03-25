#include "starlinkBody.h"

/*******************************************************
 * Description: Constructor for StarlinkBody.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
StarlinkBody::StarlinkBody(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 2, "StarlinkBody") {}

/*******************************************************
 * Description: Draws the StarlinkBody.
 *******************************************************/
void StarlinkBody::draw() {
    drawStarlinkBody(position, aRadians);
}

/*******************************************************
 * Description: Smashes the StarlinkBody into fragments.
 * @param orbitingObjects
 *******************************************************/
void StarlinkBody::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}