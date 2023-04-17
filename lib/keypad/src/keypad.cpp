#include <keypad.h>
#include <stdio.h>
#include <vector>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <thread>
#include <pigpio.h>

void NumpadDriver::wake(int data_pin)
{
    std::thread keypadthread(&NumpadDriver::readNumpad, this);

    keypadthread.join();
    // return 1;
}

void interuptHandler(int gpio, int level, uint32_t tick)
{
    static int state_1 = -1; // Forwards
    static int state_2 = -1; // Forwards
    static int state_3 = -1; // Backwards
    static int state_4 = -1; // Backwards
    static int state_5 = -1; // Backwards
    static int state_6 = -1; // Backwards
    static int state_7 = -1; // Backwards
    // int r1 = 7 ,r2 = 9 ,r3 = 11, r4 = 13 ,c1 = 15,c2 = 17 ,c3 = 19;
    if (gpio == 7)
    {
        state_1 = level;
    }
    else if (gpio == 9)
    {
        state_2 = level;
    }
    else if (gpio == 11)
    {
        state_3 = level;
    }
    else if (gpio == 13)
    {
        state_4 = level;
    }
    else if (gpio == 15)
    {
        state_5 = level;
    }
    else if (gpio == 17)
    {
        state_6 = level;
    }
    else if (gpio == 19)
    {
        state_7 = level;
    }

    if (state_1 == 0 && state_2 == 0)
    {
        std::cout << "1";
    }
    else if (state_1 == 0 && state_6 == 0)
    {
        std::cout << "2";
    }
    else if (state_1 == 0 && state_7 == 0)
    {
        std::cout << "3";
    }
    
    else if (state_2 == 0 && state_5 == 0)
    {
        std::cout << "4";
    }
    else if (state_2 == 0 && state_6 == 0)
    {
        std::cout << "5";
    }
    else if (state_2 == 0 && state_7 == 0)
    {
        std::cout << "6";
    }
    else if (state_3 == 0 && state_5 == 0)
    {
        std::cout << "7";
    }
    else if (state_3 == 0 && state_6 == 0)
    {
        std::cout << "8";
    }
    else if (state_3 == 0 && state_7 == 0)
    {
        std::cout << "9";
    }
    else if (state_4 == 0 && state_5 == 0)
    {
        std::cout << "*";
    }
    else if (state_4 == 0 && state_6 == 0)
    {
        std::cout << "0";
    }
    else if (state_4 == 0 && state_7 == 0)
    {
        std::cout << "#";
    }
}
void NumpadDriver::readNumpad()
{
    long unsigned int lookup[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 11}};
    int r1 = 7, r2 = 9, r3 = 11, r4 = 13, c1 = 15, c2 = 17, c3 = 19;

    if (gpioInitialise() < 0)
    {
        std::cout << "Keypad cannot be initialised";
        // return(0);
    }

    gpioSetMode(r1, PI_INPUT);
    gpioSetMode(r2, PI_INPUT);
    gpioSetMode(r3, PI_INPUT);
    gpioSetMode(c1, PI_INPUT);
    gpioSetMode(c2, PI_INPUT);
    gpioSetMode(c3, PI_INPUT);
    gpioSetMode(r4, PI_INPUT);

    // Setting Pull Down Resistor
    gpioSetPullUpDown(r1, PI_PUD_UP);
    gpioSetPullUpDown(r2, PI_PUD_UP);
    gpioSetPullUpDown(r3, PI_PUD_UP);
    gpioSetPullUpDown(c1, PI_PUD_UP);
    gpioSetPullUpDown(c2, PI_PUD_UP);
    gpioSetPullUpDown(c3, PI_PUD_UP);
    gpioSetPullUpDown(r4, PI_PUD_UP);

    gpioSetISRFunc(r1, EITHER_EDGE, 0, interuptHandler);
    gpioSetISRFunc(r2, EITHER_EDGE, 0, interuptHandler);
    gpioSetISRFunc(r3, EITHER_EDGE, 0, interuptHandler);
    gpioSetISRFunc(r4, EITHER_EDGE, 0, interuptHandler);
    gpioSetISRFunc(c1, EITHER_EDGE, 0, interuptHandler);
    gpioSetISRFunc(c2, EITHER_EDGE, 0, interuptHandler);
    gpioSetISRFunc(c3, EITHER_EDGE, 0, interuptHandler);
}


void NumpadDriver::stop()
{
    gpioTerminate();
    keypadthread.detach();
}

int main(){
    NumpadDriver numpad;
    numpad.wake(1);
    numpad.readNumpad();
    sleep(10);
    numpad.stop();
    return 0;
}