add_library(window src/window.cpp include/window.h)

target_include_directories(window PUBLIC include/)

target_link_libraries(window Qt5::Widgets Qt5::Core Qt5::Sql Threads::Threads)




