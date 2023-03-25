#include "hubbleRight.h"

/*******************************************************
 * Description: Constructor for HubbleRight.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
HubbleRight::HubbleRight(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "hubbleRight") {}

/*******************************************************
 * Description: Draws the HubbleRight.
 *******************************************************/
void HubbleRight::draw() {
    drawHubbleRight(position, aRadians);
}

/*******************************************************
 * Description: Smashes the HubbleRight into fragments.
 * @param orbitingObjects
 *******************************************************/
void HubbleRight::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}