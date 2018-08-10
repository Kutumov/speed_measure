cmake_minimum_required(VERSION 2.8)

project(speed_testing)
add_compile_options(-std=c++14)
add_executable(${PROJECT_NAME} "main.cpp")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(boost_system SHARED IMPORTED)

target_sources(${PROJECT_NAME} PUBLIC
    TestsHandler.cpp
    Test.cpp
    ./include/TestsHandler.h
    ./include/Test.h)


message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
