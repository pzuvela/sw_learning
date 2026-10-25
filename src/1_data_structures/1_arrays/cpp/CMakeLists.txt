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

 add_executable(stock_span
    stock_span.cpp)

 add_executable(valid_parentheses
    valid_parentheses.cpp)

 add_executable(two_sum
    two_sum.cpp)

add_executable(second_largest
    second_largest.cpp)

add_executable(move_zeroes
    move_zeroes.cpp)

add_executable(remove_duplicates
    remove_duplicates.cpp)
