
#include "../projectile/projectile.h"
//#include "physics/physics.h"

/*******************************************************
 *
 *******************************************************/
Projectile::Projectile(Position ptProjectile, double angleProjectile, double dx, double dy)
{
    this->ptProjectile = ptProjectile;
    this->angleProjectile = angleProjectile;
    this->dx = dx;
    this->dy = dy;
    this->projectileAge = 0;
}