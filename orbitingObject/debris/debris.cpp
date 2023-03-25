//
// Created by Ryan Madsen on 3/24/23.
//
#include "debris.h"

Debris::Debris(Position position, double dx, double dy, double aRadians, double radius, string type) {
    initialize(position, dx, dy, aRadians, radius, type);
    applyKick();
    applyOffset();
}

void Debris::applyKick() {
    aRadians += random(-M_PI, M_PI);
    double totalVeloctiy = sqrt(pow(dx, 2) + pow(dy, 2));
    double kickedVelocity = totalVeloctiy + random(2500, 4500);
    dx = kickedVelocity * sin(aRadians);
    dy = kickedVelocity * cos(aRadians);
}

void Debris::applyOffset() {
    double horizontalComp = radius * 2 * sin(aRadians);
    double verticalComp = radius * 2 * cos(aRadians);

    position.setPixelsX(position.getPixelsX() + horizontalComp);
    position.setPixelsY(position.getPixelsY() + verticalComp);
}