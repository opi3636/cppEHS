cmake_minimum_required(VERSION 3.31)
project(PokerCalc)

set(CMAKE_CXX_STANDARD 23)

# GCC/Clang
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# MSVC
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
endif()

add_executable(PokerCalc src/main.cpp
        src/Poker.hpp
        src/Tables.hpp
        src/Card.hpp
        src/Card.cpp
)
