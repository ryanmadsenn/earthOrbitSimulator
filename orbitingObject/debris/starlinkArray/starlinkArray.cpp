#include "starlinkArray.h"

/*******************************************************
 * Description: Constructor for StarlinkArray.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
StarlinkArray::StarlinkArray(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 4, "starlinkArray") {}

/*******************************************************
 * Description: Draws the StarlinkArray.
 *******************************************************/
void StarlinkArray::draw() {
    drawStarlinkArray(position, aRadians);
}

/*******************************************************
 * Description: Smashes the StarlinkArray into fragments.
 * @param orbitingObjects
 *******************************************************/
void StarlinkArray::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}