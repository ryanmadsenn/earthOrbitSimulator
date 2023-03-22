/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit simulator
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

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) : ptUpperRight(ptUpperRight)
   {
//      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

//      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptGPS.setMetersX(0);
      ptGPS.setMetersY(42164000);

      for (int i = 0; i < 200; i++)
      {
         Position pt;
         pt.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
         pt.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

         // Random phase.
         unsigned char phase = random(0, 224);

         stars.push_back(make_pair(pt, phase));
      }

      angleShip = M_PI / 2.0;
      angleEarth = 0.0;
      gpsDX = -3085;
      gpsDY = 0;
   }

//   Position ptHubble;
//   Position ptSputnik;
//   Position ptStarlink;
//   Position ptCrewDragon;
//   Position ptShip;
   Position ptGPS;
   Position ptUpperRight;

   vector<pair<Position, unsigned char>> stars;

   double gpsDX;
   double gpsDY;

   double angleShip;
   double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   //Demo* pDemo = (Demo*)p;
   Simulator* pSim = (Simulator*)p;

   //
   // accept input
   //
    pSim->handleInput();

   // move by a little
//   if (pUI->isUp())
//      pDemo->ptShip.addPixelsY(1.0);
//   if (pUI->isDown())
//      pDemo->ptShip.addPixelsY(-1.0);
//   if (pUI->isLeft())
//      pDemo->ptShip.addPixelsX(-1.0);
//   if (pUI->isRight())
//      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //
   pSim->update();

    // rotate the earth
//    double multiplier = 0.5;

    // Move the GPS.
//    double satX = pDemo->ptGPS.getMetersX();
//    double satY = pDemo->ptGPS.getMetersY();
//    double gravSeaLevel = 9.80665;
//    double earthRadius = 6378000;
//
//    double satHeight = sqrt(pow(satX, 2) + pow(satY, 2)) - earthRadius;
//    double accGrav = (gravSeaLevel * pow((earthRadius / (earthRadius + satHeight)), 2));
//    double direction = atan2(0 - satX, 0 - satY);
//    double accX = accGrav * sin(direction);
//    double accY = accGrav * cos(direction);
//
//    double time = 24;
//
//    double prevDX = pDemo->gpsDX;
//    double prevDY = pDemo->gpsDY;
//    pDemo->gpsDX = pDemo->gpsDX + accX * time;
//    pDemo->gpsDY = pDemo->gpsDY + accY * time;
//
//    double xFromPrev = pDemo->ptGPS.getMetersX() + prevDX * time + 0.5 * accX * pow(time, 2);
//    double yFromPrev = pDemo->ptGPS.getMetersY() + prevDY * time + 0.5 * accY * pow(time, 2);
//    double xFromCurr = pDemo->ptGPS.getMetersX() + pDemo->gpsDX * time + 0.5 * accX * pow(time, 2);
//    double yFromCurr = pDemo->ptGPS.getMetersY() + pDemo->gpsDY * time + 0.5 * accY * pow(time, 2);
//
//    double xBetween = (xFromPrev + xFromCurr) / 2;
//    double yBetween = (yFromPrev + yFromCurr) / 2;
//
//    pDemo->ptGPS.setMetersX(xBetween);
//    pDemo->ptGPS.setMetersY(yBetween);
//
//    double hypotenuse = sqrt(pow(pDemo->ptGPS.getMetersX(), 2) + pow(pDemo->ptGPS.getMetersY(), 2));
//
//    double angle = asin(pDemo->ptGPS.getMetersY() / hypotenuse);
////    cout << "Angle: " << angle << endl;
//
//    pDemo->angleEarth += -(2.0 * M_PI / 60.0) * (1440.0 / 86400.0);
//    pDemo->angleShip = angle;

   //
   // draw everything
   //
   pSim->draw();

//   Position pt;

   // draw satellites
//   drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
//   drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
//   drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
//   drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
//   drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
//   drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
//   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
//   drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
//   drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
//   drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
//   drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
//   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
//   drawFragment(pt, pDemo->angleShip);
//   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
//   drawFragment(pt, pDemo->angleShip);

   // draw a single star
//   drawStar(pDemo->ptStar, pDemo->phaseStar);

    // draw the stars
//    for (auto it = pDemo->stars.begin(); it != pDemo->stars.end(); ++it)
//    {
//        drawStar(it->first, it->second);
//        it->second++;
//    }

   // draw the earth
//   pt.setMeters(0.0, 0.0);
//   drawEarth(pt, pDemo->angleEarth);
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
    Interface ui(0, nullptr,"Demo",   /* name on the window */ptUpperRight);
    ui.setFramesPerSecond(60);

    // Initialize the demo
    // Demo demo(ptUpperRight);
    Simulator simulator(ptUpperRight);

    // set everything into action
    ui.run(callBack, &simulator);

    return 0;
}
