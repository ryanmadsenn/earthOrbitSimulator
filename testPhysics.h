

#pragma once

#include "physics.h"
#include "dummyPosition.h"

class TestPhysics 
{
public:
	void run()
	{
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
		assert(timeDilation == 1440.0);

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
		assert(timePerframe == 432000.0);

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
		assert(rotationSpeed == -0.00349065920212);

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
		assert(secPerDay == 86400.0);

		// TEARDOWN
	}

	void testAccCloseAboveEarth()
	{
		// SETUP
		DummyPosition p(0, 6378000 + 1);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction == 3.14);

		// TEARDOWN
	}

	void testAccCloseBelowEarth()
	{
		// SETUP
		DummyPosition p(0, -6378000 + 1);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction == 0);

		// TEARDOWN
	}

	void testAccCloseLeftEarth()
	{
		// SETUP
		DummyPosition p(-6378000 - 1, 0);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction == 1.57);

		// TEARDOWN
	}

	void testAccCloseRightEarth()
	{
		// SETUP
		DummyPosition p(6378000 + 1, 0);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration == 9.806);
		assert(g.direction == -1.57);

		// TEARDOWN
	}

	void testAccTwiceAboveEarth()
	{
		// SETUP
		DummyPosition p(0, 6378000 * 2);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration = 2.45);
		assert(g.direction = 3,14);

		// TEARDOWN
	}

	void testAccTwiceBelowEarth()
	{
		// SETUP
		DummyPosition p(0, -6378000 * 2);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration = 2.45);
		assert(g.direction = 0);

		// TEARDOWN
	}

	void testAccTwiceRightEarth()
	{
		// SETUP
		DummyPosition p(6378000 * 2, 0);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration = 2.45);
		assert(g.direction = -1.57);

		// TEARDOWN
	}

	void testAccTwiceLeftEarth()
	{
		// SETUP
		DummyPosition p(-6378000 * 2, 0);

		// EXERCISE
		g = getGravity(p);

		// VERIFY
		assert(g.acceleration = 2.45);
		assert(g.direction = 1.57);

		// TEARDOWN
	}
};