add_library(keypad src/keypad.cpp include/keypad.h)

find_library(PIGPIO_LIBRARY pigpio)

target_include_directories(keypad PUBLIC include/)

target_link_libraries(keypad PUBLIC ${PIGPIO_LIBRARY})


target_compile_features(keypad PUBLIC cxx_std_11)


