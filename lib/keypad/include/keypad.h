#ifndef KEYPAD_H
#define KEYPAD_H




#include <iostream>
#include <thread>

class NumpadDriver{
    public:
    std::thread keypadthread;
    void wake(int);
    void readNumpad();
    void stop();
    NumpadDriver();

};

#endif
