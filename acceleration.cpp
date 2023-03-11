//
//
//#include "acceleration.h"
//
//void Acceleration::computeDDXDDY(double angle, double magnitude)
//{
////	computeDDX(angle, magnitude);
//	computeDDY(angle, magnitude);
//}
//
//void Acceleration::addAcceleration(Acceleration& accel)
//{
//	ddx += accel.getDDX();
//	ddy += accel.getDDY();
//}
//
//void Acceleration::setAccelerationDirection(double accel, const Direction& direction)
//{
//	ddx = accel * direction.getDx();
//	ddy = accel * direction.getDy();
//}
//
////// For debugging
////std::ostream& operaotor << (std::ostream & out, const Velocity & velocity)
////{
////	out << "[" << velocity.getDX() << "m/s " << velocity.getDY() << "m/s";
////	return out;
////}