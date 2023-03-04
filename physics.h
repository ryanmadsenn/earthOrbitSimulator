

#pragma once
#define _USE_MATH_DEFINES

#include "velocity.h"
#include "acceleration.h"

class Physics 
{
public:
	Physics() {}

	double computeTimeDilation() { return hoursPerDay * minutesPerHour; }

	double computeTimePerFrame() { return computeTimeDilation() * frameRate; }

	double computeRotationSpeed() { return -(((2 * M_PI) / frameRate) * (computeTimeDilation() / seconsPerDay)); }

	double computeSatHeight();

	double computeAcceDueGravity() { return gravity * pow(earthRadius / (earthRadius + computeSatHeight()), 2); }

	double computeGravityPullDirection();

	double computeDistance();

	void updatePosition();

private:
	double time = 24;
	double gravity = 9.80665;
	double earthRadius = 6378000;
	double frameRate = 30;
	double hoursPerDay = 24;
	double minutesPerHour = 60;
	double secondsPerMinute = 60;
	double seconsPerDay = hoursPerDay * minutesPerHour * secondsPerMinute;
};