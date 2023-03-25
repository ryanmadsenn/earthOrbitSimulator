#include "hubble.h"

/*******************************************************
 * Description: Constructor for Hubble.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 *******************************************************/
Hubble::Hubble(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Hubble");
}

/*******************************************************
 * Description: Draws the Hubble.
 *******************************************************/
void Hubble::draw() {
    drawHubble(position, aRadians);
}

/*******************************************************
 * Description: Smashes the Hubble into its components.
 * @param orbitingObjects
 *******************************************************/
void Hubble::smash(vector<OrbitingObject *> * orbitingObjects) {
    orbitingObjects->push_back(new HubbleTelescope(position, dx, dy, aRadians));
    orbitingObjects->push_back(new HubbleComputer(position, dx, dy, aRadians));
    orbitingObjects->push_back(new HubbleLeft(position, dx, dy, aRadians));
    orbitingObjects->push_back(new HubbleRight(position, dx, dy, aRadians));
}