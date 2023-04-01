add_library(camera src/camera.cpp include/camera.h)

target_include_directories(camera PUBLIC include/)

target_link_libraries(camera Threads::Threads PkgConfig::ZBar ${OpenCV_LIBS})

