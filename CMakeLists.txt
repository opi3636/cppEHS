cmake_minimum_required(VERSION 3.31)
project(PokerCalc)

set(CMAKE_CXX_STANDARD 26)

add_executable(PokerCalc src/main.cpp
        src/Poker.hpp
        src/Tables.hpp
        src/Card.hpp
        src/Card.cpp
)
