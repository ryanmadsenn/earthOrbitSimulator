/*************************************************************
 * Header File:
 *    StarlinkArray : Class for the Starlink Array
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#include "../debris.h"
#include "../fragment/fragment.h"

class StarlinkArray : public Debris {
public:
    StarlinkArray(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};