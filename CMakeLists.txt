cmake_minimum_required(VERSION 3.21)
project(Andreev_KNFK)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Andreev_KNFK
        collision.cpp
        collision.h
        input.cpp
        main.cpp
        input.h
        particle.cpp
        particle.h
        print.cpp
        print.h
        simulation.cpp
        vector.cpp
        vector.h
        simulation.h)
