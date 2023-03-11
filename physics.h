

#pragma once
#include "velocity.h"
#include "acceleration.h"
#include "position/position.h"
#include "orbitingObject/orbitingObject.h"

#define _USE_MATH_DEFINES
#define STANDARD_GRAVITY 9.80665
#define EARTH_RADIUS 6378000
#define FRAME_RATE 30
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60
#define TIME 24

// Important computations
double computeTimeDilation()				{ return HOURS_PER_DAY * MINUTES_PER_HOUR; }
double computeTimePerFrame()				{ return computeTimeDilation() * FRAME_RATE; }
double computeSecPerDay() { return HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE; }
double computeRotationSpeed()				{ return -(((2 * M_PI) / FRAME_RATE) * (computeTimeDilation() / computeSecPerDay())); }

double computeSatHeight(double satX, double satY)
{
    return (sqrt(pow(satX, 2) + pow(satY, 2)) - EARTH_RADIUS);
}

double getGravity(double satHeight)
{
    return (STANDARD_GRAVITY * pow((EARTH_RADIUS / (EARTH_RADIUS + satHeight)), 2));
}

double calculateDDX(double accGravity, double direction) {
    return accGravity * sin(direction);
}

double calculateDDY(double accGravity, double direction){
    return accGravity * cos(direction);
}

double calculateNewPosition(double position, double velocity, double acceleration) {
    return position + velocity * TIME + 0.5 * acceleration * pow(TIME, 2);
}

void applyPhysics(OrbitingObject * obj) {
    double satX = obj->getPosition().getMetersX();
    double satY = obj->getPosition().getMetersY();
    double satHeight = computeSatHeight(satX, satY);
    double accGravity = getGravity(satHeight);
    double direction = atan2(0- satY, 0 - satX);
    double accX = accGravity * sin(direction);
    double accY = accGravity * cos(direction);

    double prevDX = obj->getDx();
    double prevDY = obj->getDy();
    obj->setDx(obj->getDx() + accX * TIME);
    obj->setDy(obj->getDy() + accY * TIME);

    double xFromPrev = calculateNewPosition(satX, prevDX, accX);
    double yFromPrev = calculateNewPosition(satY, prevDY, accY);
    double xFromCurr = calculateNewPosition(satX, obj->getDx(), accX);
    double yFromCurr = calculateNewPosition(satY, obj->getDy(), accY);

    double xBetween = (xFromPrev + xFromCurr) / 2;
    double yBetween = (yFromPrev + yFromCurr) / 2;

    obj->setPosition(Position(xBetween, yBetween));
}
