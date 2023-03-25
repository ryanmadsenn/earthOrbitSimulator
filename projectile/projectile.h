#pragma once

#include <vector>
#include "../uiDraw/uiDraw.h"
using namespace std;

class Projectile
{
private:
    Position ptProjectile;
    double angleProjectile;
    double dx;
    double dy;
    int projectileAge;

public:
    Projectile() {}

    Projectile(Position ptProjectile, double angleProjectile, double dx, double dy);

    void setPosition(Position pt) { ptProjectile = pt; };

    Position * getPosition() { return &ptProjectile; }

    double getDX() { return dx; }

    double getDY() { return dy; }

    void draw() { drawProjectile(ptProjectile); }

    void incrementAge() { projectileAge++; }

    int getAge() { return projectileAge; }
};