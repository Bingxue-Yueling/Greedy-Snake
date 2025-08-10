cmake_minimum_required(VERSION 3.16)
project(GreedySnake)
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(main main.cpp ${SOURCES})
