#include "hubbleComputer.h"

HubbleComputer::HubbleComputer(Position position, double dx, double dy, double aRadians)
: Debris(position, dx, dy, aRadians, 7, "hubbleComputer") {}

void HubbleComputer::draw() {
    drawHubbleComputer(position, aRadians);
}

void HubbleComputer::smash(vector<OrbitingObject *> * orbitingObjects) {
    for (int i = 0; i < 2; i++) {
        orbitingObjects->push_back(new Fragment(position, dx, dy, aRadians));
    }
}