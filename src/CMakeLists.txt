cmake_minimum_required (VERSION 3.8)

project(matapos)


include_directories(${OpenCV_INCLUDE_DIRS})

add_library(simplecameralib printhello.cpp)
target_include_directories(simplecameralib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(cameralib camera.cpp)
target_include_directories(cameralib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Threads::Threads PkgConfig::ZBar simplecameralib cameralib Qt5::Widgets ${OpenCV_LIBS})

