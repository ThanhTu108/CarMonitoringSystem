cmake_minimum_required(VERSION 3.20)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB HMI_SOURCE "src/*.cpp")
file(GLOB HMI_HEADER "include/*.h")
file(GLOB HMI_UI "ui/*.ui")
file(GLOB HMI_WIDGET_HEADER "widget/*.h")
file(GLOB HMI_WIDGET_SOURCE "widget/*.cpp")
file(GLOB HMI_HELPER_HEADER "widget/helper/include/*.h")
file(GLOB HMI_HELPER_SOURCE "widget/helper/src/*.cpp")

add_library(hmi_lib STATIC
    ${HMI_SOURCE}
    ${HMI_HEADER}
    ${HMI_UI}
    ${HMI_WIDGET_HEADER}
    ${HMI_WIDGET_SOURCE}
    ${HMI_HELPER_SOURCE}
    ${HMI_HELPER_HEADER})

set_target_properties(hmi_lib PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui" 
)

target_include_directories(hmi_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/widget
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/widget/helper/include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(hmi_lib PUBLIC Qt6::Widgets)
