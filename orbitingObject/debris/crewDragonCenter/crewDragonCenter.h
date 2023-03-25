#include "../debris.h"
#include "../fragment/fragment.h"

class CrewDragonCenter : public Debris {
public:
    CrewDragonCenter(Position position, double dx, double dy, double aRadians);

    void draw() override;

    void smash(vector<OrbitingObject *> * orbitingObjects) override;
};