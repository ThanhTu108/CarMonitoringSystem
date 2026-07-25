find_package(spdlog REQUIRED)

add_library(common_lib STATIC src/logger.cpp)

target_include_directories(common_lib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(common_lib PUBLIC spdlog::spdlog)

# Define log level
if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("-----BUILD TYPE: RELEASE------")
    target_compile_definitions(common_lib PUBLIC LOG_LEVEL_CMAKE=1)
else()
    message("-----BUILD TYPE: DEV------")
    target_compile_definitions(common_lib PUBLIC LOG_LEVEL_CMAKE=0)
endif()

if(BUILD_TESTING)
    add_executable(test_common tests/test_logger.cpp)
    target_link_libraries(test_common PRIVATE common_lib)
endif()