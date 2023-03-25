
#include "../projectile/projectile.h"
//#include "physics/physics.h"

/*******************************************************
 * Description: Constructor for the Projectile class.
 *******************************************************/
Projectile::Projectile(Position ptProjectile, double angleProjectile, double dx, double dy)
{
    this->ptProjectile = ptProjectile;
    this->angleProjectile = angleProjectile;
    this->dx = dx;
    this->dy = dy;
    this->projectileAge = 0;
}