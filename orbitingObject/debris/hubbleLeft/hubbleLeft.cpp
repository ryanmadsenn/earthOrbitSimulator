#include "hubbleLeft.h"

HubbleLeft::HubbleLeft(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 8, "hubbleLeft") {}

void HubbleLeft::draw() {
    drawHubbleLeft(position, aRadians);
}

void HubbleLeft::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}