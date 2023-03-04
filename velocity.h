

#pragma once
#include <cmath>
#include "acceleration.h"

/*********************************************
	* VELOCITY
	* An instance of velocity
*********************************************/
class Velocity
{
public:
	// Constructors
	Velocity();
	Velocity(double dx, double dy);

	// Getters
	double getDX() const { return dx; }
	double getDY() const { return dy; }
	double getSpeed() const { return sqrt((dx * dx) + (dy * dy)); }
	void computeDX(double angle, double velocity) { setDX(sin(angle) * velocity); }
	void computeDY(double angle, double velocity) { setDY(cos(angle) * velocity); }

	// Setters
	void setDX(double dx) { this->dx = dx; }
	void setDY(double dy) { this->dy = dy; }
	void add(const Acceleration& accel, double time);	// updates the velocity DY and DY

private:
	double dx;
	double dy;
};