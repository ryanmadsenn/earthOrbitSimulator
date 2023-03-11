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
		testAccCloseBelowEarth();
		testAccCloseLeftEarth();
		testAccCloseRightEarth();
		testAccTwiceAboveEarth();
		testAccTwiceBelowEarth();
		testAccTwiceLeftEarth();
		testAccTwiceRightEarth();
	}

private:
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


	void testAccCloseAboveEarth()
	{
		// SETUP
		DummyPosition p(0, 6378000 + 1);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction.radians == 0.055);

		// TEARDOWN
	}

	void testAccCloseBelowEarth()
	{
		// SETUP
		DummyPosition p(0, -6378000 + 1);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction.radians == 0);

		// TEARDOWN
	}

	void testAccCloseLeftEarth()
	{
		// SETUP
		DummyPosition p(-6378000 - 1, 0);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction.radians == 1.57);

		// TEARDOWN
	}

	void testAccCloseRightEarth()
	{
		// SETUP
		DummyPosition p(6378000 + 1, 0);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction.radians == -1.57);

		// TEARDOWN
	}

	void testAccTwiceAboveEarth()
	{
		// SETUP
		DummyPosition p(0, 6378000 * 2);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 2.45);
		assert(g.direction.radians == 0.055);

		// TEARDOWN
	}

	void testAccTwiceBelowEarth()
	{
		// SETUP
		DummyPosition p(0, -6378000 * 2);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration = 2.45);
		assert(g.direction.radians = 0);

		// TEARDOWN
	}

	void testAccTwiceRightEarth()
	{
		// SETUP
		DummyPosition p(6378000 * 2, 0);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration = 2.45);
		assert(g.direction.radians = -1.57);

		// TEARDOWN
	}

	void testAccTwiceLeftEarth()
	{
		// SETUP
		DummyPosition p(-6378000 * 2, 0);

		// EXERCISE
		Acceleration g = getGravity(p);

		// VERIFY
		assert(g.acceleration = 2.45);
		assert(g.direction.radians = 1.57);

		// TEARDOWN
	}
};