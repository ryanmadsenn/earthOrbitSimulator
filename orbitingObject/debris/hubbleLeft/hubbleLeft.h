#include "../debris.h"
#include "../fragment/fragment.h"

class HubbleLeft : public Debris {
public:
    HubbleLeft(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};