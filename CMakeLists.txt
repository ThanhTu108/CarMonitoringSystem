cmake_minimum_required(VERSION 3.20)

project(CarMonitoringSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTING "build test" ON)

add_subdirectory(src/common)