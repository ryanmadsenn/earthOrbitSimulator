/*************************************************************
 * Header File:
 *    GubbleRight : The class representing the right half of the Hubble Space Telescope
 * Author:
 *    Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 *************************************************************/
#include "../debris.h"
#include "../fragment/fragment.h"

class HubbleRight : public Debris {
public:
    HubbleRight(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};