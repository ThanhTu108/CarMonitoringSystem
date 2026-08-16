cmake_minimum_required(VERSION 3.20)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB HMI_SOURCE "src/*.cpp")
file(GLOB HMI_HEADER "include/*.h")
file(GLOB HMI_UIS "ui/*.ui")

add_library(hmi_lib STATIC
    ${HMI_SOURCE}
    ${HMI_HEADER}
    ${HMI_UIS})

set_target_properties(hmi_lib PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui" 
)

target_include_directories(hmi_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(hmi_lib PUBLIC Qt6::Widgets)
