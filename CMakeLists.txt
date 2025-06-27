cmake_minimum_required(VERSION 3.31)
project(RubikCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubikCubeSolver main.cpp
        Model/GenericRubiksClass.cpp
        Model/GenericRubiksClass.h)
