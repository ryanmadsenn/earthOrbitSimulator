/***********************************************************************
* Header File:
*    Test Physics : Test the Physics class
* Author:
*    Erick Vega, Ryan Madsen, Bueze Nwokolo
* Summary:
*    All the unit tests for Physics
************************************************************************/

#pragma once

#include "../physics/physics.h"
#include "../position/dummyPosition.h"
#include <cassert>
#include <cmath>
#define _USE_MATH_DEFINES

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
		testGravityOnEarth();
		testGravityAboveEarth();
		testGravityCloseAboveEarth();
		testGravityCloseBelowEarth();
		testGravityTwiceEarthRadius();
		testCalculateDDX_EarthRight();
		testCalculateDDX_EarthUp();
		testCalculateDDY_EarthRight();
		testCalculateDDY_EarthUp();
		testSatHeight_CloseEarthX();
		testSatHeight_CloseEarthY();
		testSatHeight_SameEarthRadiusX();
		testSatHeight_SameEarthRadiusY();
        cout << "Physics tests passed!\n" << endl;
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
		assert(FRAME_RATE == 60);
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
		assert(FRAME_RATE == 60);
		assert(HOURS_PER_DAY == 24);
		assert(MINUTES_PER_HOUR == 60);
		assert(timePerframe == 24);

		// TEARDOWN
	}

	void testComputeRotationSpeed()
	{
		// SETUP

		// EXERCISE
		double rotationSpeed = computeRotationSpeed();

		// VERIFY
		assert(FRAME_RATE == 60);
		assert(HOURS_PER_DAY == 24);
		assert(MINUTES_PER_HOUR == 60);
//		assert(closeEnough(rotationSpeed, 0.00174533, 0.0001));

		// TEARDOWN
	}

	void testGravityOnEarth()
	{
		// SETUP
		double satHeight = 0;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, STANDARD_GRAVITY, 0.0001));

		// TEARDOWN
	}

	void testGravityCloseAboveEarth()
	{
		// SETUP
		double satHeight = 1;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, 9.80665, 0.0001));

		// TEARDOWN
	}

	void testGravityCloseBelowEarth()
	{
		// SETUP
		double satHeight = -1;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, 9.80665, 0.00001));

		// TEARDOWN
	}

	void testGravityTwiceEarthRadius()
	{
		// SETUP
		double satHeight = 6378000;

		// EXERCISE
		double g = getGravity(satHeight);

		// VERIFY
		assert(closeEnough(g, 2.45166, 0.00001));

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

	void testSatHeight_SameEarthRadiusY()
	{
		// Setup.
		double satX = 0;
		double satY = 6378000;

		// Exercise.
		double height = computeSatHeight(satX, satY);

		// Verify.
		assert(height == 0.0);

		// Teardown.
	}

	void testSatHeight_SameEarthRadiusX()
	{
		// Setup.
		double satX = 6378000;
		double satY = 0;

		// Exercise.
		double height = computeSatHeight(satX, satY);

		// Verify.
		assert(height == 0.0);

		// Teardown.
	}

	void testSatHeight_CloseEarthX()
	{
		// Setup.
		double satX = 6378000 + 1;
		double satY = 0;

		// Exercise.
		double height = computeSatHeight(satX, satY);

		// Verify.
		assert(height == 1.0);

		// Teardown.
	}

	void testSatHeight_CloseEarthY()
	{
		// Setup.
		double satX = 0;
		double satY = 6378000 + 1;

		// Exercise.
		double height = computeSatHeight(satX, satY);

		// Verify.
		assert(height == 1.0);

		// Teardown.
	}

	void testCalculateDDX_EarthRight()
	{
		// Setup.
		double accGravity = 9.806;
		double direction = 0;

		// Exercise.
		double acc = calculateDDX(accGravity, direction);

		// Verify.
		assert(closeEnough(acc, 0.0, 0.000001));

		// Teardown.
	}

	void testCalculateDDY_EarthRight()
	{
		// Setup.
		double accGravity = 9.806;
		double direction = 0;

		// Exercise.
		double acc = calculateDDY(accGravity, direction);

		// Verify.
		assert(closeEnough(acc, 9.806, 0.000001));

		// Teardown.
	}

	void testCalculateDDX_EarthUp()
	{
		// Setup.
		double accGravity = 9.806;
		double direction = M_PI/2;

		// Exercise.
		double acc = calculateDDX(accGravity, direction);

		// Verify.
		assert(closeEnough(acc, 9.806, 0.000001));

		// Teardown.
	}

	void testCalculateDDY_EarthUp()
	{
		// Setup.
		double accGravity = 9.806;
		double direction = M_PI / 2;

		// Exercise.
		double acc = calculateDDY(accGravity, direction);

		// Verify.
		assert(closeEnough(acc, 0.0, 0.000001));

		// Teardown.
	}


};