

#include "acceleration.h"

void Acceleration::computeDDXDDY(double angle, double magnitude)
{
	computeDDX(angle, magnitude);
	computeDDY(angle, magnitude);
}

void Acceleration::addAcceleration(Acceleration& accel)
{
	ddx += accel.getDDX();
	ddy += accel.getDDY();
}