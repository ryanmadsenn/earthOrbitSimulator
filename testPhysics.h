

#pragma once

#include "physics.h"
#include "dummyPosition.h"

class TestPhysics 
{
public:
	void run()
	{
		accCloseAboveEarth();
		accCloseBelowEarth();
		accCloseLeftEarth();
		accCloseRightEarth();
		accTwiceAboveEarth();
		accTwiceBelowEarth();
		accTwiceLeftEarth();
		accTwiceRightEarth();

	}

private:
	void testDefaultConstructor()
	{
		// SETUP

		// EXERCISE
		Physics physics;

		// VERIFY


		// TEARDOWN
	}

	void accCloseAboveEarth()
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

	void accCloseBelowEarth()
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

	void accCloseLeftEarth()
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

	void accCloseRightEarth()
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

	void accTwiceAboveEarth()
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

	void accTwiceBelowEarth()
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


	void accTwiceRightEarth()
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

	void accTwiceLeftEarth()
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