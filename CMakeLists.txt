cmake_minimum_required(VERSION 3.20)

project(cs211Final LANGUAGES CXX)
set_property(GLOBAL PROPERTY CXX_STANDARD C++17)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_custom_target(copy-booklist ALL
                  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/booklist.txt)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/booklist.txt
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/booklist.txt
          ${CMAKE_CURRENT_BINARY_DIR}/booklist.txt
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/booklist.txt)

set(wsuId a222a222)
add_executable(${wsuId}_final src/main.cpp src/Book.cpp src/Genre.cpp
                              src/Shelf.cpp)
