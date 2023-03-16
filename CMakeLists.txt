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
)