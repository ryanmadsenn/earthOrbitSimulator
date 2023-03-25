#include "./hubbleTelescope.h"

/*******************************************************
 * Description: Constructor for HubbleTelescope.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 ******************************************************/
HubbleTelescope::HubbleTelescope(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 10, "hubbleTelescope") {}

/*******************************************************
 * Description: Draws the HubbleTelescope.
 ******************************************************/
void HubbleTelescope::draw() {
    drawHubbleTelescope(position, aRadians);
}

/*******************************************************
 * Description: Smashes the HubbleTelescope into fragments.
 * @param orbitingObjects
 ******************************************************/
void HubbleTelescope::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}
