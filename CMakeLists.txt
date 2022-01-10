cmake_minimum_required(VERSION 3.20)
project(CSA_HW2)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSA_HW2 main.cpp objects/plant.cpp objects/plant.h objects/tree.cpp objects/tree.h objects/bush.cpp objects/bush.h objects/flower.cpp objects/flower.h container/container.cpp container/container.h)
