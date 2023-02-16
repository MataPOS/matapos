cmake_minimum_required (VERSION 3.8)

project ("matapos")

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(OpenCV REQUIRED)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(dependencies)
add_subdirectory(test)

option(BUILD_EXAMPLES "Switch to build examples dir" OFF)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

