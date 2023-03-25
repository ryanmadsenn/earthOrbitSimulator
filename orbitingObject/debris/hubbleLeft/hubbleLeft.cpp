#include "hubbleLeft.h"

/*******************************************************
 * Description: Constructor for HubbleLeft.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
HubbleLeft::HubbleLeft(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "hubbleLeft") {}

/*******************************************************
 * Description: Draws the HubbleLeft.
 *******************************************************/
void HubbleLeft::draw() {
    drawHubbleLeft(position, aRadians);
}

/*******************************************************
 * Description: Smashes the HubbleLeft into fragments.
 * @param orbitingObjects
 *******************************************************/
void HubbleLeft::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}