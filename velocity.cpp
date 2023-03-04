

#include "velocity.h"
#include "acceleration.h"
#include "direction.h"

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

/************************************************************************
 * DIRECTION
 * Set and return new direction.
 ************************************************************************/
Direction Velocity::getDirection() const
{
	Direction direction;
	direction.setDxDy(dx, dy);
	return direction;
}

/************************************************************************
 * SET SPEED DIRECTION
 * Set and return new direction.
 ************************************************************************/
void Velocity::setSpeedDirection(double speed, const Direction& direction)
{
	dx = speed * direction.getDx();
	dy = speed * direction.getDy();
}