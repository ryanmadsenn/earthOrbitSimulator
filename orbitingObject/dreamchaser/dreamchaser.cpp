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
    initialize(position, dx, dy, aRadians, radius, "DreamChaser");
    computeShipFront();
}

/*******************************************************
 *
 ********************************************************/
void DreamChaser::draw() {
    drawShip(position, aRadians, isThrusting);
}

/*******************************************************
 *
 ********************************************************/
void DreamChaser::computeShipFront()
{
    // because sine and cosine are expensive, we want to call them only once
    double cosA = cos(aRadians);
    double sinA = sin(aRadians);

    // start with our original point
    shipFront = Position(position);

    // find the new values
    shipFront.addPixelsX(0.0 * cosA + 19.0 * sinA);
    shipFront.addPixelsY(19.0 * cosA - 0.0 * sinA);
}

//void DreamChaser::fireProjectile()
//{
//    // Velocity of the DreamChaser need to be added to the initial velocity of the projectile.
//    double initialVelocity = 9000.0;
//    double finalVelocity = sqrt(pow(dx, 2) + pow(dy, 2)) + initialVelocity;
//
//    projectile.reset(getShipFront(), aRadians, finalVelocity);
//    projectile.draw();
//}

/*******************************************************
 *
 * @param orbitingObjects
 ********************************************************/
void DreamChaser::smash(vector<OrbitingObject *> orbitingObjects) {
    // TODO: Implement this method.
}