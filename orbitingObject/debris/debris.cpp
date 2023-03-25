#include "debris.h"
/*******************************************************
 * Description: Constructor for Debris.
 * @param position
 * @param dx
 * @param dy
 * @param aRadians
 * @param radius
 * @param type
 *******************************************************/
Debris::Debris(Position position, double dx, double dy, double aRadians, double radius, string type) {
    initialize(position, dx, dy, aRadians, radius, type);
    applyKick();
    applyOffset();
}
/*******************************************************
 * Description: applies kick to fragments and parts.
 ******************************************************/
void Debris::applyKick() {
    aRadians += random(-M_PI, M_PI);
    double totalVeloctiy = sqrt(pow(dx, 2) + pow(dy, 2));
    double kickedVelocity = totalVeloctiy + random(2500, 4500);
    dx = kickedVelocity * sin(aRadians);
    dy = kickedVelocity * cos(aRadians);
}

/*******************************************************
 * Description: applies offset to fragments and parts.
 ******************************************************/
void Debris::applyOffset() {
    double horizontalComp = radius * 2 * sin(aRadians);
    double verticalComp = radius * 2 * cos(aRadians);

    position.setPixelsX(position.getPixelsX() + horizontalComp);
    position.setPixelsY(position.getPixelsY() + verticalComp);
}