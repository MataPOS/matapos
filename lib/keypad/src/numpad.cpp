# include <numpad.h>
#include <stdio.h>
#include <vector.h>


#include <iostream>
#include <thread>
#include <pigpio.h>

int NumpadDriver::wake(int data_pin)
{
    t = thread::(&NumpadDriver::Readnumpad, this);
}


void NumpadDriver::registerCallback(NumpadCallback *np)
{
    numpadcallback.push_back(np);
}



vector<int> NumpadDriver::insertAtEnd(vector<int> v, int x){
    v.push_back(x);
    return v;
}

void NumpadDriver::readNumpad()
{
    int data = [0,0,0,0];

    int r1 = 29 ,r2 = 31 ,r3 = 33, r4 = 35 ,c1 = 15,c2 = 17 ,c3 = 19;

    //Initialising GPIO Pins
    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

    //Setting GPIO Pins as Input
    gpioSetMode(r1, PI_INPUT);
    gpioSetMode(r2, PI_INPUT);
    gpioSetMode(r3, PI_INPUT);
    gpioSetMode(r4, PI_INPUT);
    gpioSetMode(c1, PI_INPUT);
    gpioSetMode(c2, PI_INPUT);
    gpioSetMode(c3, PI_INPUT);

    //Setting Pull Up Resistor
    gpioSetPullUpDown(r1, PI_PUD_UP);
    gpioSetPullUpDown(r2, PI_PUD_UP);
    gpioSetPullUpDown(r3, PI_PUD_UP);
    gpioSetPullUpDown(r4, PI_PUD_UP);
    gpioSetPullUpDown(c1, PI_PUD_UP);
    gpioSetPullUpDown(c2, PI_PUD_UP);
    gpioSetPullUpDown(c3, PI_PUD_UP);

    int lookup[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,0,11}};

    while (1){
        if (gpioRead(r1) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                data = insertAtEnd(data,lookup[0][0]);
            }
            else if (gpioRead(c2) == 0)
            {
                data = insertAtEnd(data,lookup[0][1]);
            }
            else if (gpioRead(c3) == 0)
            {
                data = insertAtEnd(data,lookup[0][2]);
            }
        }
        else if (gpioRead(r2) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                data = insertAtEnd(data,lookup[1][0]);
            }
            else if (gpioRead(c2) == 0)
            {
                data = insertAtEnd(data,lookup[1][1]);
            }
            else if (gpioRead(c3) == 0)
            {
                data = insertAtEnd(data,lookup[1][2]);
            }
        }
        else if (gpioRead(r3) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                data = insertAtEnd(data,lookup[2][0]);
            }
            else if (gpioRead(c2) == 0)
            {
                data = insertAtEnd(data,lookup[2][1]);
            }
            else if (gpioRead(c3) == 0)
            {
                data = insertAtEnd(data,lookup[2][2]);
            }
        }
        else if (gpioRead(r4) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                break;
            }
            else if (gpioRead(c2) == 0)
            {
                data = insertAtEnd(data,lookup[3][1]);
            }
            else if (gpioRead(c3) == 0)
            {
                break;
            }
        }
        else
        {
            data[0] = 0;
        }
    }
    for (auto np : numpadcallback)
    {
        np->hasData(data);
    }

    gpioTerminate();
}

void NumpadDriver::stop()
{
    running = false;
}
