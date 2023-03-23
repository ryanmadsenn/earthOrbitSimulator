#pragma once

#include <iostream>
#include "../position/position.h"
#include <cassert>

using namespace std;

/************************************
  * DUMMY POSITION
  ************************************/
class DummyPosition : public Position

{

public:

    DummyPosition() : Position() {}

    DummyPosition(double x, double y) : Position( x, y) {}

    virtual double getMetersX() const { assert(false); return 0.0; }

    virtual double getMetersY() const { assert(false); return 0.0; }

    virtual double getPixelsX() const { assert(false); return 0.0; }

    virtual double getPixelsY() const { assert(false); return 0.0; }

    void setMeters(double xMeters, double yMeters) { assert(false); }
    void setMetersX(double xMeters) { assert(false); }
    void setMetersY(double yMeters) { assert(false); }
    void setPixelsX(double xPixels) { assert(false); }
    void setPixelsY(double yPixels) { assert(false); }
    void addMetersX(double dxMeters) { assert(false); }
    void addMetersY(double dyMeters) { assert(false); }
    void addPixelsX(double dxPixels) { assert(false); }
    void addPixelsY(double dyPixels) { assert(false); }
    void setZoom(double metersFromPixels) { assert(false);}
    double getZoom() const { assert(false); }
};
