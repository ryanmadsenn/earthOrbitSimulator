
#include "../projectile/projectile.h"
//#include "physics/physics.h"

/*******************************************************
 *
 *******************************************************/
Projectile::Projectile(Position ptProjectile, double angleProjectile, double velocity)
{
    this->ptProjectile = ptProjectile;
    this->angleProjectile = angleProjectile;
    this->velocity = velocity;
    this->projectileAge = 0.0;
}

void Projectile::reset(Position &pt, double angle, double velocity)
{
    path.clear();
    ptProjectile = pt;
    path.push_back(ptProjectile);
    angleProjectile = angle;
    this->velocity = velocity;
    projectileAge = 0.0;
}

/*******************************************************
 *
 *******************************************************/
//void Projectile::move()
//{
//    double ddx = calculateDDX(getGravity(ptProjectile), angleProjectile);
//    double ddy = calculateDDY(getGravity(ptProjectile), angleProjectile);
//    double dx = calculateNewPosition(ptProjectile.getMetersX(), velocity, ddx);
//    double dy = calculateNewPosition(ptProjectile.getMetersY(), velocity, ddy);
//    ptProjectile.setMetersX(dx);
//    ptProjectile.setMetersY(dy);
//    path.push_back(ptProjectile);
////    path.insert(path.begin(), ptProjectile);
//    projectileAge += TIME;
//    velocity += getGravity(ptProjectile) * TIME;
//}