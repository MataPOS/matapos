cmake_minimum_required (VERSION 3.8)

project ("matapos")

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(PkgConfig REQUIRED)
find_package(Qt5 COMPONENTS Sql Core Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

pkg_check_modules(ZBar REQUIRED IMPORTED_TARGET zbar)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


option(BUILD_EXAMPLES "Switch to build examples dir" OFF)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

set(SOURCES
    src/main.cpp
    src/camera.cpp
    src/barcodereader.cpp
    src/window.cpp
)

set(HEADERS
    include/camera/camera.h
    include/barcodereader/barcodereader.h
    include/guiheaderfiles/window.h

)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME}
    Threads::Threads 
    PkgConfig::ZBar 
    Qt5::Core 
    Qt5::Sql
    Qt5::Widgets 
    ${OpenCV_LIBS} 
 )

enable_testing()