#include <keypad.h>
#include <stdio.h>
#include <vector>


#include <iostream>
#include <thread>
#include <pigpio.h>

//Setup interupts
//Linked to * button
// void NumpadDriver::backITR(int gpio, int level, unsigned int tick, void *userdata)
// {
//     if (level == 0)
//     {
        
//     }
// }
// //linked to # button
// void NumpadDriver::forwardITR(int gpio, int level, unsigned int tick, void *userdata)
// {
//     if (level == 0)
//     {
       
//     }
// }

//Class Contructor
NumpadDriver::NumpadDriver(){//Setting GPIO Pins as Input
    int r1 = 7 ,r2 = 9 ,r3 = 11, r4 = 13 ,c1 = 15,c2 = 17 ,c3 = 19;
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


}
void NumpadDriver::readNumpad()
{
    vector<int> data;

    int lookup[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,0,11}};

    while (1){
        if (gpioRead(r1) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                data = NumpadDriver::insertAtEnd(data,lookup[0][0]);
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
int NumpadDriver::wake(int data_pin)
{
    std::thread t(&NumpadDriver::readNumpad, this);
        //Initialising GPIO Pins
    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }
    t.join();
}


void NumpadDriver::registerCallback(NumpadCallback *np)
{
    numpadcallback.push_back(np);
}

vector<int> NumpadDriver::insertAtEnd(vector<int> v, int x){
    v.push_back(x);
    return v;
}

void NumpadDriver::stop()
{
    t.detach();
}

int main()
{
    NumpadDriver npd;

    npd.wake(0);
    npd.readNumpad();
    stdout::cout << NumpadDriver::data;

    return 0;
}

//Add function to go back and forward. 