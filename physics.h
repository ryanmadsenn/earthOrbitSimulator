

#pragma once
#define _USE_MATH_DEFINES

#include "velocity.h"
#include "acceleration.h"
#include "position.h"

class TestPhysics;

class Physics 
{
public:
	// Friend class
	friend class TestPhysics;

	// Constructor
	Physics() {}

	// Important computations
	double computeTimeDilation()				{ return hoursPerDay * minutesPerHour; }
	double computeTimePerFrame()				{ return computeTimeDilation() * frameRate; }
	double computeRotationSpeed()				{ return -(((2 * M_PI) / frameRate) * (computeTimeDilation() / computeSecPerDay())); }
	double computeSecPerDay()					{ return hoursPerDay * minutesPerHour * secondsPerMinute; }
	double computeSatHeight(const Position& posElement)
	{
		// Earth is at Position(0,0) by default
		double distance = computeDistance(Position(), posElement);
		return distance - earthRadius;
	}
	Acceleration getGravity(const Position& posElement)
	{
		double height = computeSatHeight(posElement);

		Direction direction;

		direction.setDxDy(-posElement.getMetersX(), -posElement.getMetersY());


		// a = g_0 (R_e / (R_e + h)) ^ 2
		double tmp = earthRadius / (earthRadius + height);
		double acceleration = standardGravity * tmp * tmp;

		return Acceleration(acceleration, direction);

	}

private:
	double gravity = 9.80665;
	double earthRadius = 6378000.0;
	double frameRate = 30.0;
	double hoursPerDay = 24.0;
	double minutesPerHour = 60.0;
	double secondsPerMinute = 60.0;
};
