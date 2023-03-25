#include "hubbleComputer.h"

/*******************************************************
 * Description: Constructor for HubbleComputer.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 *******************************************************/
HubbleComputer::HubbleComputer(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 7, "hubbleComputer") {}

/*******************************************************
 * Description: Draws the HubbleComputer.
 *******************************************************/
void HubbleComputer::draw() {
    drawHubbleComputer(position, aRadians);
}

/*******************************************************
 * Description: Breaks the HubbleComputer into fragments.
 * @param orbitingObjects
 *******************************************************/
void HubbleComputer::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}