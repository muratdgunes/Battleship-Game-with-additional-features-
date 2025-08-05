cmake_minimum_required(VERSION 3.28)
project(Assignment3)

set(CMAKE_CXX_STANDARD 26)

add_executable(Assignment3 main.cpp
        Battle_Ship.cpp
        Battle_Ship.h
        Player.cpp
        Player.h
        Board.cpp
        Board.h)
