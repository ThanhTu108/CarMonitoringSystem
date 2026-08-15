cmake_minimum_required(VERSION 3.20)

project(CarMonitoringSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTING "build test" ON)

# Add subdirectories for each component
# add_subdirectory(src/common)


add_executable(CarMonitoringSystem main.cpp)

target_link_libraries(CarMonitoringSystem PRIVATE hmi_lib)
