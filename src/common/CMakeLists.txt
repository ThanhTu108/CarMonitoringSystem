find_package(spdlog REQUIRED)

add_library(common_lib STATIC src/logger.cpp)

target_include_directories(common_lib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(common_lib PUBLIC spdlog::spdlog)


if(BUILD_TESTING)
    add_executable(test_common tests/test_logger.cpp)
    target_link_libraries(test_common PRIVATE common_lib)
endif()