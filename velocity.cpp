

#include "velocity.h"
#include "acceleration.h"

#include <cmath>

#include "velocity.h"	// for the velocity object

/************************************************************************
 * VELOCITY Default constructor
 * Create a new velocity object
 ************************************************************************/
Velocity::Velocity()
{
	dx = 0.0;
	dy = 0.0;
}

/************************************************************************
 * VELOCITY  constructor
 * Create a new velocity object with existing velocities
 ************************************************************************/
Velocity::Velocity(double dx, double dy)
{
	this->dx = dx;
	this->dy = dy;
}



/************************************************************************
 * ADD
 * Updates velocity based on acceleration and time
 * The equation is:
 *      v = v + a t
 * Inputs:
 *		accel: current acceleration
 *		time: time interval to calculate velocity change
 ************************************************************************/
void Velocity::add(const Acceleration& accel, double time)
{
	dx = dx + accel.getDDX() * time;
	dy = dy + accel.getDDY() * time;
}