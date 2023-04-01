cmake_minimum_required(VERSION 3.8)

project(matapos)

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(PkgConfig REQUIRED)
find_package(Qt5 COMPONENTS Sql Core Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

pkg_check_modules(ZBar REQUIRED IMPORTED_TARGET zbar)


add_subdirectory(lib)
add_subdirectory(app)
