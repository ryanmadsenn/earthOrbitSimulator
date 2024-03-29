/*************************************************************
 * Header File:
 *    Physics: A file containing utility functions used in the game
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#pragma once

#include "../orbitingObject/orbitingObject.h"
#include "../orbitingObject/dreamchaser/dreamchaser.h"
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h> // for windows

#define STANDARD_GRAVITY 9.80665
#define EARTH_RADIUS 6378000
#define FRAME_RATE 60
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60
#define TIME 24

// Important computations
inline double computeTimeDilation()	{ return HOURS_PER_DAY * MINUTES_PER_HOUR; }
inline double computeTimePerFrame()	{ return computeTimeDilation() / FRAME_RATE; }
inline double computeSecPerDay()       { return HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE; }
inline double computeRotationSpeed()   { return -(((2 * M_PI) / FRAME_RATE) * (computeTimeDilation() / computeSecPerDay())); }

/*******************************************************
 * Compute Satellite Height
 * @param satX
 * @param satY
 * @return
 ********************************************************/
inline double computeSatHeight(double satX, double satY)
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
inline double computeAltitude(Position& ptOrbitingObject)
{
    double distance = computeDistance(Position(), ptOrbitingObject);
    return distance - EARTH_RADIUS;
}

/******************************************************
 * Get Gravity
 * @param satHeight
 * @return
 *****************************************************/
inline double getGravity(double satHeight)
{
    return (STANDARD_GRAVITY * pow((EARTH_RADIUS / (EARTH_RADIUS + satHeight)), 2));
}

/******************************************************
 * Here is an alternate "getGravity" given the position
 * of an orbitingObject
 * @param ptOrbitingObject
 * @return
 ******************************************************/
inline double getGravity(Position& ptOrbitingObject)
{
    double altitude = computeAltitude(ptOrbitingObject);
    double tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
    return STANDARD_GRAVITY * tmp * tmp;
}

/******************************************************
 * Update Velocity
 * @param orbitingObject
 * @param acceleration
 * @param time
 ******************************************************/
inline void updateVelocity(OrbitingObject& orbitingObject, double acceleration)
{
    orbitingObject.setDx(orbitingObject.getDx() + (acceleration * computeTimePerFrame()));
    orbitingObject.setDy(orbitingObject.getDy() + (acceleration * computeTimePerFrame()));
}

/******************************************************
 * Calculate DDX
 * @param accGravity
 * @param direction
 * @return
 ******************************************************/
inline double calculateDDX(double accGravity, double direction)
{
    return accGravity * sin(direction);
}

/******************************************************
 * Calculate DDY
 * @param accGravity
 * @param direction
 * @return
 ******************************************************/
inline double calculateDDY(double accGravity, double direction)
{
    return accGravity * cos(direction);
}

/*******************************************************
 * Compute Direction
 * @param ptX
 * @param ptY
 * @return
 *******************************************************/
inline double computeDirection(double ptX, double ptY)
{
    return atan2(0 - ptY, 0 - ptX);
}

/*******************************************************
 * Calculate New Position
 * @param position
 * @param velocity
 * @param acceleration
 * @return
 ********************************************************/
inline double calculateNewPosition(double position, double velocity, double acceleration)
{
    return position + velocity * TIME + 0.5 * acceleration * pow(TIME, 2);
}

/*******************************************************
 * Update Position
 * @param orbitingObject
 * @param velocity
 * @param acceleration
 *******************************************************/
inline void updatePosition(OrbitingObject& orbitingObject, double velocity, double acceleration)
{
    Position *pt = orbitingObject.getPosition();
    pt->addMetersX(velocity * computeTimePerFrame() + 0.5 * acceleration * pow(computeTimePerFrame(), 2));
    pt->addMetersY(velocity * computeTimePerFrame() + 0.5 * acceleration * pow(computeTimePerFrame(), 2));
    orbitingObject.setPosition(*pt);
}

/*******************************************************
 * Apply Physics
 * @param obj
 *******************************************************/
inline void applyPhysics(OrbitingObject * obj)
{
    double satX = obj->getPosition()->getMetersX();
    double satY = obj->getPosition()->getMetersY();
    double satHeight = computeSatHeight(satX, satY);
    double accGravity = getGravity(satHeight);
    double direction = atan2(0 - satX, 0 - satY);
    double accX = accGravity * sin(direction);
    double accY = accGravity * cos(direction);

    if (obj->getType() == "Dreamchaser") {
        if (dynamic_cast<DreamChaser *>(obj)->getIsThrusting()) {
            accX += 2.0 * sin(obj->getARadians());
            accY += 2.0 * cos(obj->getARadians());
        }
    }
    
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

/*******************************************************
 * Apply Projectile Physics
 * @param projetile
 *******************************************************/
inline void applyProjectilePhysics(Projectile * projectile) {
    double x = calculateNewPosition(projectile->getPosition()->getMetersX(), projectile->getDX(), 0);
    double y = calculateNewPosition(projectile->getPosition()->getMetersY(), projectile->getDY(), 0);

    projectile->setPosition(Position(x, y));
}
