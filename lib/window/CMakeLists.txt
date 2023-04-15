add_library(window src/window.cpp src/CartScreen.cpp src/WelcomeScreen.cpp include/CartScreen.h include/WelcomeScreen.h include/window.h)

target_include_directories(window PUBLIC include/)

target_link_libraries(window entity database camera barcodereader Qt5::Widgets Qt5::Core Qt5::Sql Threads::Threads)




