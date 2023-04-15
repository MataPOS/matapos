add_library(numpad src/numpad.cpp include/numpad.h)


target_include_directories(keypad PUBLIC include/)

target_link_libraries(keypad PUBLIC wiringPi)

