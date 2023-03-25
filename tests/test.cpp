/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich, Vega Erick Penafiel, Madsen Ryan, and Bueze Nwokolo
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testPhysics.h"
#include "testSimulator.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
    cout << "Running tests..."  << endl;
    TestSimulator().run();
    TestPosition().run();
    TestPhysics().run();
}
