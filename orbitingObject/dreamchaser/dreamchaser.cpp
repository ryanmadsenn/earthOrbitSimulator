#include "dreamchaser.h"
/*******************************************************
 *
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 ********************************************************/
DreamChaser::DreamChaser(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Dreamchaser");
//    velocityObject.setVelocity(dx, dy);
//    directionObject.setDirection(dx, dy);
    computeShipFront();
}

/*******************************************************
 *
 ********************************************************/
void DreamChaser::draw() {
    drawShip(position, aRadians, isThrusting);
}

void DreamChaser::rotate(bool right) {
    right ? aRadians += 0.05 : aRadians -= 0.05;
}

void DreamChaser::thrust() {
    isThrusting = true;
}

void DreamChaser::shoot(vector<Projectile *> * projectiles) {
    double totalVelocity = sqrt(pow(dx, 2) + pow(dy, 2)) + 9000.0;
    double projDX = totalVelocity * sin(aRadians);
    double projDY = totalVelocity * cos(aRadians);
    auto projectile = new Projectile(computeShipFront(), aRadians, projDX, projDY);
    projectiles->push_back(projectile);
}

Position DreamChaser::computeShipFront()
{
    // Because sine and cosine are expensive, we want to call them only once
    double cosA = cos(aRadians);
    double sinA = sin(aRadians);

    // Start with our original point
    Position shipFront = Position(position);

    // Find the new values
    shipFront.addPixelsX(0.0 * cosA + 19.0 * sinA);
    shipFront.addPixelsY(19.0 * cosA - 0.0 * sinA);

    return shipFront;
}

/*******************************************************
 *
 * @param orbitingObjects
 ********************************************************/
void DreamChaser::smash(vector<OrbitingObject *> * orbitingObjects) {
    // TODO: Implement this method.
}