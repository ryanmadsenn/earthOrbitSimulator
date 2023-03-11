/***********************************************************************
 * Header File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Erick Vega, Ryan Madsen, Bueze Nwokolo
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/

#pragma once

#include <iostream>
#include "acceleration.h"
#include "position/dummyPosition.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST Acceleration
 * A friend class for Acceleration which contains the Acceleration unit tests
 ********************************/
class TestAcceleration
{
public:
    void run()
    {
        test_1();
    }

private:
    void test_1()
    {
        // setup
        DummyPosition p(0, 6378000 + 1);
        Acceleration acc();

        // exercise
        acc.getGravity(p);




    }
};