cmake_minimum_required(VERSION 3.20)

project(CppAlgorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(next_greater
    next_greater.cpp
)

add_executable(daily_temperatures
    daily_temperatures.cpp
)