#include "hubbleRight.h"

HubbleRight::HubbleRight(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "hubbleRight") {}

void HubbleRight::draw() {
    drawHubbleRight(position, aRadians);
}

void HubbleRight::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}