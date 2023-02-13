cmake_minimum_required (VERSION 3.8)

project(matapos)


add_library(simplecameralib printhello.cpp)
target_include_directories(simplecameralib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_executable(main main.cpp)

target_link_libraries(main PRIVATE simplecameralib)
target_link_libraries(main PRIVATE Qt5::Widgets)


