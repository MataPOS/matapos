cmake_minimum_required (VERSION 3.8)

project ("matapos")

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(OpenCV REQUIRED)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(dependencies)
add_subdirectory(test)

option(BUILD_EXAMPLES "Switch to build examples dir" OFF)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

