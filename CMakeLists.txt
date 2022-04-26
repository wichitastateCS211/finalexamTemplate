cmake_minimum_required(VERSION 3.20)

project(cs211Final LANGUAGES CXX)
set_property(GLOBAL PROPERTY CXX_STANDARD C++17)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

set(wsuId a222a222)
add_executable(${wsuId}_final
    src/main.cpp
    src/Book.cpp
    src/Genre.cpp
    src/Shelf.cpp)