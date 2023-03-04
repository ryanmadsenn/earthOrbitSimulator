

#pragma once

#include "physics.h"
#include "dummyPosition.h"

class TestPhysics 
{
public:
	void run()
	{
		testDefaultConstructor();
		testComputeTimeDialtion();
		testComputeTimePerFrame();
		testComputeRotationSpeed();
		testComputeSecPerDay();
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
	void testDefaultConstructor()
	{
		// SETUP

		// EXERCISE
		Physics physics;

		// VERIFY
		assert(physics.gravity == 9.80665);
		assert(physics.earthRadius == 6378000);
		assert(physics.frameRate == 30);
		assert(physics.hoursPerDay == 24);
		assert(physics.minutesPerHour == 60);
		assert(physics.secondsPerMinute == 60);

		// TEARDOWN
	}

	void testComputeTimeDialtion()
	{
		// SETUP
		Physics physics;
		double timeDilation;

		// EXERCISE
		timeDilation = physics.computeTimeDilation();

		// VERIFY
		assert(timeDilation > 0);
		assert(timeDilation > physics.hoursPerDay);
		assert(timeDilation > physics.minutesPerHour);

		// TEARDOWN
	}

	void testComputeTimePerFrame()
	{
		// SETUP
		Physics physics;
		double timePerframe;

		// EXERCISE
		timePerframe = physics.computeTimeDilation() * physics.frameRate;

		// VERIFY
		assert(timePerframe > 0);
		assert(timePerframe > physics.frameRate);

		// TEARDOWN
	}

	void testComputeRotationSpeed()
	{
		// SETUP
		Physics physics;
		double rotationSpeed;

		// EXERCISE
		rotationSpeed = physics.computeRotationSpeed();

		// VERIFY
		assert(rotationSpeed < 0);

		// TEARDOWN
	}

	void testComputeSecPerDay()
	{
		// SETUP
		Physics physics;
		double secPerDay;

		// EXERCISE
		secPerDay = physics.computeSecPerDay();

		// VERIFY
		assert(secPerDay > 0);
		assert(secPerDay > physics.minutesPerHour);
		assert(secPerDay > physics.secondsPerMinute);
		assert(secPerDay > physics.hoursPerDay);

		// TEARDOWN
	}

	void testAccCloseAboveEarth()
	{
		// setup
		DummyPosition p(0, 6378000 + 1);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 9.806;
		g.direction = 3.14;

		// teardown
	}

	void testAccCloseBelowEarth()
	{
		// setup
		DummyPosition p(0, -6378000 + 1);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 9.806;
		g.direction = 0;

		// teardown
	}

	void testAccCloseLeftEarth()
	{
		// setup
		DummyPosition p(-6378000 - 1, 0);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 9.806;
		g.direction = 1.57;

		// teardown
	}

	void testAccCloseRightEarth()
	{
		// setup
		DummyPosition p(6378000 + 1, 0);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 9.806;
		g.direction = -1.57;

		// teardown
	}

	void testAccTwiceAboveEarth()
	{
		// setup
		DummyPosition p(0, 6378000 * 2);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 2.45;
		g.direction = 3,14;

		// teardown
	}

	void testAccTwiceBelowEarth()
	{
		// setup
		DummyPosition p(0, -6378000 * 2);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 2.45;
		g.direction = 0;

		// teardown
	}

	void testAccTwiceRightEarth()
	{
		// setup
		DummyPosition p(6378000 * 2, 0);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 2.45;
		g.direction = -1.57;

		// teardown
	}

	void testAccTwiceLeftEarth()
	{
		// setup
		DummyPosition p(-6378000 * 2, 0);

		// exercise
		g = getGravity(p);

		// verify
		g.acceleration = 2.45;
		g.direction = 1.57;

		// teardown
	}
};