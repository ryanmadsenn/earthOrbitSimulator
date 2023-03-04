

#pragma once

#include "physics.h"
#include <cassert>

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
		testComputeSatHeight();
		testComputeAcceDueGravity();
		testComputeGravityPullDirection();
		testComputeDistance();
		testUpdatePosition();
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

	void testComputeSatHeight()
	{
		// SETUP


		// EXERCISE


		// VERIFY


		// TEARDOWN
	}

	void testComputeAcceDueGravity()
	{
		// SETUP


		// EXERCISE


		// VERIFY


		// TEARDOWN
	}

	void testComputeGravityPullDirection()
	{
		// SETUP


		// EXERCISE


		// VERIFY


		// TEARDOWN
	}

	void testComputeDistance()
	{
		// SETUP


		// EXERCISE


		// VERIFY


		// TEARDOWN
	}

	void testUpdatePosition()
	{
		// SETUP


		// EXERCISE


		// VERIFY


		// TEARDOWN
	}
};