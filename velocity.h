//
//
//#pragma once
//
//#include "acceleration.h"
//
///*********************************************
//	* VELOCITY
//	* An instance of velocity
//*********************************************/
//class Velocity
//{
//public:
//	// Constructors
//	Velocity() : dx(0.0), dy(0.0) {};
//	Velocity(double dx, double dy) { this->dx = dx; this->dy = dy; };
//
//	// Getters
//	double getDX() const { return dx; }
//	double getDY() const { return dy; }
//	double getSpeed() const { return sqrt((dx * dx) + (dy * dy)); }
//	void computeDX(double angle, double velocity) { setDX(sin(angle) * velocity); }
//	void computeDY(double angle, double velocity) { setDY(cos(angle) * velocity); }
//	Direction getDirection() const;
//
//
//	// Setters
//	void setDX(double dx) { this->dx = dx; }
//	void setDY(double dy) { this->dy = dy; }
//	void setSpeedDirection(double speed, const Direction& direction);
//	void add(const Acceleration& accel, double time);
//
//private:
//	double dx;
//	double dy;
//};