#include "dreamchaser.h"
/*******************************************************
 * Description: Constructor for DreamChaser.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 ********************************************************/
DreamChaser::DreamChaser(Position position, double dx, double dy, double aRadians, double radius) {
    initialize(position, dx, dy, aRadians, radius, "Dreamchaser");
    computeShipFront();
}

/*******************************************************
 * Description: Draws the DreamChaser.
 ********************************************************/
void DreamChaser::draw() {
    if (isAlive)
        drawShip(position, aRadians, isThrusting);
}

/*******************************************************
 * Description: Rotates the DreamChaser.
 * @param right
 ********************************************************/
void DreamChaser::rotate(bool right) {
    right ? aRadians += 0.05 : aRadians -= 0.05;
}

/*******************************************************
 * Description: Thrusts the DreamChaser.
 ********************************************************/
void DreamChaser::thrust() {
    if (isAlive)
        isThrusting = true;
}

/*******************************************************
 * Description: Shoots other orbiting objects.
 ********************************************************/
void DreamChaser::shoot(vector<Projectile *> * projectiles) {
    if (isAlive) {
        double totalVelocity = sqrt(pow(dx, 2) + pow(dy, 2)) + 9000.0;
        double projDX = totalVelocity * sin(aRadians);
        double projDY = totalVelocity * cos(aRadians);
        auto projectile = new Projectile(computeShipFront(), aRadians, projDX, projDY);
        projectiles->push_back(projectile);
    }
}

/*******************************************************
 * Description: computes the front of the DreamChaser.
 ********************************************************/
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
 * Description: breaks the DreamChaser into fragments.
 * @param orbitingObjects
 ********************************************************/
void DreamChaser::smash(vector<OrbitingObject *> * orbitingObjects) {
    // TODO: Implement this method.
}