/*************************************************************
 * Header File:
 *    HubbleTelescope : Debris
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/#include "../debris.h"
#include "../fragment/fragment.h"

class HubbleTelescope : public Debris {
public:
    HubbleTelescope(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};