cmake_minimum_required(VERSION 3.24)
project(231_07_Ponder_GLDemo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")
include_directories(.)

add_executable(
        231_07_Ponder_GLDemo
        Lab07.cpp
        position/position.cpp
        position/position.h
        tests/test.cpp
        tests/test.h
        tests/testPosition.h
        uiDraw/uiDraw.cpp
        uiInteract/uiInteract.cpp
        uiInteract/uiInteract.h
        simulator/simulator.h
        simulator/simulator.cpp
        tests/testSimulator.h tests/testSimulator.cpp
        simulator/fakeSimulator.h
        simulator/fakeSimulator.cpp
        orbitingObject/orbitingObject.h
        orbitingObject/orbitingObject.cpp
        orbitingObject/satellite/satellite.h
        orbitingObject/satellite/sputnik/sputnik.h
        orbitingObject/satellite/sputnik/sputnik.cpp
        orbitingObject/satellite/gps/gps.h
        orbitingObject/satellite/gps/gps.cpp
        orbitingObject/satellite/hubble/hubble.h
        orbitingObject/satellite/hubble/hubble.cpp
        orbitingObject/satellite/starlink/starlink.h
        orbitingObject/satellite/starlink/starlink.cpp
        orbitingObject/satellite/crewDragon/crewDragon.h
        orbitingObject/satellite/crewDragon/crewDragon.cpp
        orbitingObject/dreamchaser/dreamchaser.h
        orbitingObject/dreamchaser/dreamchaser.cpp
        orbitingObject/satellite/satellite.cpp
        star/star.cpp
        projectile/projectile.cpp
        direction/direction.h
        direction/direction.cpp
        thrust/thrust.cpp
        thrust/thrust.h
        velocity/velocity.cpp
        velocity/velocity.h
        acceleration/acceleration.cpp
        acceleration/acceleration.h orbitingObject/debris/debris.h orbitingObject/debris/debris.cpp orbitingObject/debris/fragment/fragment.h orbitingObject/debris/fragment/fragment.cpp orbitingObject/debris/gpsCenter/gpsCenter.h orbitingObject/debris/gpsCenter/gpsCenter.cpp orbitingObject/debris/gpsLeft/gpsLeft.h orbitingObject/debris/gpsLeft/gpsLeft.cpp orbitingObject/debris/gpsRight/gpsRight.h orbitingObject/debris/gpsRight/gpsRight.cpp orbitingObject/debris/hubbleTelescope/hubbleTelescope.h orbitingObject/debris/hubbleTelescope/hubbleTelescope.cpp orbitingObject/debris/hubbleComputer/hubbleComputer.h orbitingObject/debris/hubbleComputer/hubbleComputer.cpp orbitingObject/debris/hubbleLeft/hubbleLeft.h orbitingObject/debris/hubbleLeft/hubbleLeft.cpp orbitingObject/debris/hubbleRight/hubbleRight.h orbitingObject/debris/hubbleRight/hubbleRight.cpp orbitingObject/debris/crewDragonCenter/crewDragonCenter.h orbitingObject/debris/crewDragonCenter/crewDragonCenter.cpp orbitingObject/debris/crewDragonLeft/crewDragonLeft.h orbitingObject/debris/crewDragonLeft/crewDragonLeft.cpp orbitingObject/debris/crewDragonRight/crewDragonRight.h orbitingObject/debris/crewDragonRight/crewDragonRight.cpp orbitingObject/debris/starlinkBody/starlinkBody.h orbitingObject/debris/starlinkBody/starlinkBody.cpp orbitingObject/debris/starlinkArray/starlinkArray.h orbitingObject/debris/starlinkArray/starlinkArray.cpp orbitingObject/dreamchaser/DeadDreamChaser.h)