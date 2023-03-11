/***********************************************************************
* Header File:
*    Test Physics : Test the Physics class
* Author:
*    Erick Vega, Ryan Madsen, Bueze Nwokolo
* Summary:
*    All the unit tests for Physics
************************************************************************/

#pragma once

#include "physics.h"
#include "position/dummyPosition.h"
#include "direction.h"
#include <cassert>

/*******************************
 * TEST Physics
 * A friend class for Physics which contains the Physics unit tests
 ********************************/
class TestPhysics 
{
public:
	void run()
	{
		
		testDefaultVariables();
		testComputeTimeDialtion();
		testComputeTimePerFrame();
		testComputeRotationSpeed();
		testAccCloseAboveEarth();
//		testAccCloseBelowEarth();
//		testAccCloseLeftEarth();
//		testAccCloseRightEarth();
//		testAccTwiceAboveEarth();
//		testAccTwiceBelowEarth();
//		testAccTwiceLeftEarth();
//		testAccTwiceRightEarth();
	}

private:
    bool closeEnough(double value, double test, double tolerance) const
    {
        double difference = value - test;
        return (difference >= -tolerance) && (difference <= tolerance);
    }

	void testDefaultVariables()
	{
		// SETUP
		// 
		// EXERCISE		

		// VERIFY
		assert(STANDARD_GRAVITY == 9.80665);
		assert(EARTH_RADIUS == 6378000);
		assert(FRAME_RATE == 30);
		assert(HOURS_PER_DAY == 24);
		assert(MINUTES_PER_HOUR == 60);
		assert(SECONDS_PER_MINUTE == 60);
		// TEARDOWN
	}

	void testComputeTimeDialtion()
	{
		// SETUP    

		// EXERCISE
		double timeDilation = computeTimeDilation();

		// VERIFY
		assert(HOURS_PER_DAY == 24);
		assert(MINUTES_PER_HOUR == 60);
		assert(timeDilation == 1440);

		// TEARDOWN
	}

	void testComputeTimePerFrame()
	{
		// SETUP

		// EXERCISE
		double timePerframe = computeTimePerFrame();

		// VERIFY
		assert(FRAME_RATE == 30);
		assert(HOURS_PER_DAY == 24);
		assert(MINUTES_PER_HOUR == 60);
		assert(timePerframe == 43200);

		// TEARDOWN
	}

	void testComputeRotationSpeed()
	{
		// SETUP

		// EXERCISE
		double rotationSpeed = computeRotationSpeed();

		// VERIFY
		assert(FRAME_RATE == 30);
		assert(HOURS_PER_DAY == 24);
		assert(MINUTES_PER_HOUR == 60);
		assert(rotationSpeed == -0.00348);
		

		// TEARDOWN
	}

	void testGravityOnEarth()
	{
		// SETUP
		double satHeight = 0;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, STANDARD_GRAVITY, 0.000001));

		// TEARDOWN
	}

	void testGravityCloseAboveEarth()
	{
		// SETUP
		double satHeight = 1;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, 9.806, 0.000001));

		// TEARDOWN
	}

	void testGravityCloseBelowEarth()
	{
		// SETUP
		double satHeight = -1;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, 9.806, 0.000001));

		// TEARDOWN
	}

	void testGravityTwiceEarthRadius()
	{
		// SETUP
		double satHeight = 6378000;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, 2.452, 0.000001));

		// TEARDOWN
	}

	void testGravityAboveEarth()
	{
		// SETUP
		double satHeight = 42164000;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, 0.169299, 0.000001));

		// TEARDOWN
	}
};