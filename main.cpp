/*************************************************************
 * 1. Name:
 *      Ryan Madsen, Erick Vega, and Bueze Nwokolo
 * 2. Assignment Name:
 *      Lab 13: Orbit Simulator Complete
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was figuring out how to keep the satellite
 *      from drifting away from the Earth. We ended up calculating
 *      the new position of the satellite with the both the previous
 *      and new velocities, and then averaged those two points to
 *      get a more accurate new position.
 * 5. How long did it take for you to complete the assignment?
 *      It took about 4 hours ot complete this assignment.
 *****************************************************************/

#define _USE_MATH_DEFINES

#include <cassert>      // for ASSERT
#include <cmath>        // for M_PI
#include <iomanip>
#include <vector>
#include "uiInteract/uiInteract.h" // for INTERFACE
#include "uiDraw/uiDraw.h"     // for RANDOM and DRAW*
#include "position/position.h"      // for POINT
#include "tests/test.h"
#include "simulator/simulator.h"

using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   Simulator* pSim = (Simulator*)p;
   pSim->update();
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    testRunner();

    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
    ptUpperRight.setPixelsX(1000.0);
    ptUpperRight.setPixelsY(1000.0);

    Interface ui(0, nullptr,"Orbital Simulator",   /* name on the window */ptUpperRight);
    ui.setFramesPerSecond(60);

    // Initialize the simulator.
    Simulator simulator(&ptUpperRight, &ui);

    // set everything into action
    ui.run(callBack, &simulator);

    return 0;
}
