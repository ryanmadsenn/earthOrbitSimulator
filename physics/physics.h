

#pragma once
#include "orbitingObject/orbitingObject.h"
#include <cmath>
#include <math.h>
#include <vector>
#include <map>

#define _USE_MATH_DEFINES
#define STANDARD_GRAVITY 9.80665
#define EARTH_RADIUS 6378000
#define FRAME_RATE 30
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60
#define TIME 24

// Important computations
double computeTimeDilation()	{ return HOURS_PER_DAY * MINUTES_PER_HOUR; }
double computeTimePerFrame()	{ return computeTimeDilation() * FRAME_RATE; }
double computeSecPerDay()       { return HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE; }
double computeRotationSpeed()   { return -(((2 * M_PI) / FRAME_RATE) * (computeTimeDilation() / computeSecPerDay())); }

/*******************************************************
 *
 * @param satX
 * @param satY
 * @return
 ********************************************************/
double computeSatHeight(double satX, double satY)
{
    return (sqrt(pow(satX, 2) + pow(satY, 2)) - EARTH_RADIUS);
}

/*this method is the same with "computeSatHeight" but I will name if "computeAltitude" because
 * it can be applied to all orbitingObjects and it uses the position of theorbitingObjects.*/
/*******************************************************
 * GET ALTITUDE
 * Returns the altitude of a point above the earth
 * @param ptOrbitingObject
 * @return distance from the earth
 *********************************************************/
double computeAltitude(Position& ptOrbitingObject)
{
    double distance = computeDistance(Position(), ptOrbitingObject);
    return distance - EARTH_RADIUS;
}

/******************************************************
 *
 * @param satHeight
 * @return
 *****************************************************/
double getGravity(double satHeight)
{
    return (STANDARD_GRAVITY * pow((EARTH_RADIUS / (EARTH_RADIUS + satHeight)), 2));
}

/******************************************************
 * Here is an alternate "getGravity" given the position
 * of an orbitingObject
 * @param ptOrbitingObject
 * @return
 ******************************************************/
double getGravity(Position& ptOrbitingObject)
{
    double altitude = computeAltitude(ptOrbitingObject);
    double tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
    return STANDARD_GRAVITY * tmp * tmp;
}

/******************************************************
 *
 * @param orbitingObject
 * @param acceleration
 * @param time
 ******************************************************/
void updateVelocity(OrbitingObject& orbitingObject, double acceleration)
{
    orbitingObject.setDx(orbitingObject.getDx() + (acceleration * TIME));
    orbitingObject.setDy(orbitingObject.getDy() + (acceleration * TIME));
}

/******************************************************
 *
 * @param accGravity
 * @param direction
 * @return
 ******************************************************/
double calculateDDX(double accGravity, double direction)
{
    return accGravity * sin(direction);
}

/******************************************************
 *
 * @param accGravity
 * @param direction
 * @return
 ******************************************************/
double calculateDDY(double accGravity, double direction)
{
    return accGravity * cos(direction);
}

/*******************************************************
 *
 * @param ptX
 * @param ptY
 * @return
 *******************************************************/
double computeDirection(double ptX, double ptY)
{
    return atan2(0 - ptY, 0 - ptX);
}

/*******************************************************
 *
 * @param position
 * @param velocity
 * @param acceleration
 * @return
 ********************************************************/
double calculateNewPosition(double position, double velocity, double acceleration)
{
    return position + velocity * TIME + 0.5 * acceleration * pow(TIME, 2);
}

/*******************************************************
 *
 * @param orbitingObject
 * @param velocity
 * @param acceleration
 *******************************************************/
void updatePosition(OrbitingObject& orbitingObject, double velocity, double acceleration)
{
    Position *pt = orbitingObject.getPosition();
    pt->addMetersX(velocity * TIME + 0.5 * acceleration * pow(TIME, 2));
    pt->addMetersY(velocity * TIME + 0.5 * acceleration * pow(TIME, 2));
    orbitingObject.setPosition(*pt);
}

/*******************************************************
 *
 * @param obj
 *******************************************************/
void applyPhysics(OrbitingObject * obj)
{
    double satX = obj->getPosition()->getMetersX();
    double satY = obj->getPosition()->getMetersY();
    double satHeight = computeSatHeight(satX, satY);
    double accGravity = getGravity(satHeight);
    double direction = computeDirection(satX, satY);
//    double direction = atan2(0- satY, 0 - satX);
    double accX = calculateDDX(accGravity, direction);
    double accY = calculateDDY(accGravity, direction);
//    double accX = accGravity * sin(direction);
//    double accY = accGravity * cos(direction);

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
