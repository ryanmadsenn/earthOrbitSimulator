#include "fragment.h"

/*******************************************************
 * Description: Constructor for Fragment.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
Fragment::Fragment(Position position, double dx, double dy, double aRadians)
        : Debris(position, dx, dy, aRadians, 2.0, "Fragment") {
    lifespan = random(100, 200);
}

/*******************************************************
 * Description: Draws the Fragment.
 *******************************************************/
void Fragment::draw() {
    drawFragment(position, aRadians);
}

/*******************************************************
 * Description: Does nothing.
 * @param orbitingObjects
 *******************************************************/
void Fragment::smash(vector<OrbitingObject *> * orbitingObjects) {
    // Do nothing.
}