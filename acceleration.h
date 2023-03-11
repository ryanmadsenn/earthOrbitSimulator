

#pragma once
#include "direction.h"

class TestPhysics;

/*********************************************
  * ACCELERATION
  * An instance of acceleration.
  *********************************************/
class Acceleration
{
public:
    friend class TestPhysics;

   // Constructors
   Acceleration() : ddx(0.0), ddy(0.0) {}
   Acceleration(double accel, const Direction& direction) : ddx(0.0), ddy(0.0)
   {
      setAccelerationDirection(accel, direction);
   }
   Velocity getVelocity(double time) 
   {
      return Velocity(ddx * time, ddy * time);
   }
   Acceleration(double ddx, double ddy)
   {
      this->ddx = ddx;
      this->ddy = ddy;
   };
   void computeDDXDDY(double angle, double magnitude);

   // Getters
   double getDDX() const { return ddx; }
   double getDDY() const { return ddy; }

   // Setters
   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }
   void addAcceleration(Acceleration& accel);
   void computeDDX(double angle, double dx) { setDDX(sin(angle) * dx); };
   void computeDDY(double angle, double dy) { setDDY(cos(angle) * dy); };
   void setAccelerationDirection(double accel, const Direction& direction);


private:
   double ddx;     //horizontal acceleration
   double ddy;     //vertical acceleration
   double acceleration;
   Direction direction;

};