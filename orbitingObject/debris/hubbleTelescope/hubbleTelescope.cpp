#include "./hubbleTelescope.h"

HubbleTelescope::HubbleTelescope(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 10, "hubbleTelescope") {}

void HubbleTelescope::draw() {
    drawHubbleTelescope(position, aRadians);
}

void HubbleTelescope::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 3; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}
