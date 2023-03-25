//
// Created by Ryan Madsen on 3/24/23.
//
#include "debris.h"

Debris::Debris(Position position, double velocity, double aRadians) {
    double newVelocity = velocity + random(5000, 9000);
    double newDX = newVelocity * sin(aRadians);
    double newDY = newVelocity * cos(aRadians);
    double newRadians = aRadians + random(-M_PI / 2, M_PI / 2);
    position.setPixelsX(position.getPixelsX() + 4 * sin(newRadians));
    position.setPixelsY(position.getPixelsY() + 4 * cos(newRadians));

//    initialize(position, newDX, newDY, newRadians);


    this->aRadians = aRadians;
}