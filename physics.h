

#pragma once

#include "velocity.h"
#include "acceleration.h"
#include "position/position.h"

#define _USE_MATH_DEFINES
#define STANDARD_GRAVITY 9.80665
#define EARTH_RADIUS 6378000
#define FRAME_RATE 30
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60


// Important computations
double computeTimeDilation()				{ return HOURS_PER_DAY * MINUTES_PER_HOUR; }
double computeTimePerFrame()				{ return computeTimeDilation() * FRAME_RATE; }
double computeSecPerDay() { return HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE; }
double computeRotationSpeed()				{ return -(((2 * M_PI) / FRAME_RATE) * (computeTimeDilation() / computeSecPerDay())); }

double computeSatHeight(const Position& posElement)
{
	// Earth is at Position(0,0) by default
	double distance = computeDistance(Position(), posElement);
	return distance - EARTH_RADIUS;
}
Acceleration getGravity(const Position& posElement)
{
	double height = computeSatHeight(posElement);

	Direction direction;

	direction.setDxDy(-posElement.getMetersX(), -posElement.getMetersY());


	// a = g_0 (R_e / (R_e + h)) ^ 2
	double tmp = EARTH_RADIUS / (EARTH_RADIUS + height);
	double acceleration = STANDARD_GRAVITY * tmp * tmp;

	return Acceleration(acceleration, direction);

}
