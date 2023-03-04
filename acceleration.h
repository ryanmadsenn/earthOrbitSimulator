

#pragma once

/*********************************************
  * ACCELERATION
  * An instance of acceleration.
  *********************************************/
class Acceleration
{
public:
   // Constructors
   Acceleration() : ddx(0.0), ddy(0.0) {}
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


private:
   double ddx;     //horizontal acceleration
   double ddy;     //vertical acceleration
};