
cmake_minimum_required(VERSION 3.7.0)

project(Matapos)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable(Matapos camera.cpp CartScreen.cpp WelcomeScreen.cpp window.cpp main.cpp )

target_link_libraries(Matapos Qt5::Widgets)
target_link_libraries(Matapos qwt-qt5)
target_link_libraries(Matapos ${OpenCV_LIBS} Threads::Threads)

install(TARGETS Matapos)
