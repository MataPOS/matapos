#include<keypad.h>
#include<stdio.h>
#include<vector>
//#include<unistd.h>
#include<fcntl.h>


#include<iostream>
#include<thread>
#include<pigpio.h>

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
//NumpadDriver::NumpadDriver(){//Setting GPIO Pins as Input
    
    //int r1 = 7 ,r2 = 9 ,r3 = 11, r4 = 13 ,c1 = 15,c2 = 17 ,c3 = 19;
    
    //if (gpioInitialize()<0)
    //{
        //std::cout << "Keypad cannot be initialised";
        
    //}
    
    //gpioSetMode(r1, PI_INPUT);
    //gpioSetMode(r2, PI_INPUT);
    //gpioSetMode(r3, PI_INPUT);
    //gpioSetMode(r4, PI_INPUT);
    //gpioSetMode(c1, PI_INPUT);
    //gpioSetMode(c2, PI_INPUT);
    //gpioSetMode(c3, PI_INPUT);

    ////Setting Pull Up Resistor
    //gpioSetPullUpDown(r1, PI_PUD_UP);
    //gpioSetPullUpDown(r2, PI_PUD_UP);
    //gpioSetPullUpDown(r3, PI_PUD_UP);
    //gpioSetPullUpDown(r4, PI_PUD_UP);
    //gpioSetPullUpDown(c1, PI_PUD_UP);
    //gpioSetPullUpDown(c2, PI_PUD_UP);
    //gpioSetPullUpDown(c3, PI_PUD_UP);


//}
//vector<int> NumpadDriver::insertAtEnd(vector<int> v, int x){
 //   v.push_back(x);
 //   return v;
//}

void NumpadDriver::readNumpad()
{
    std::vector<long unsigned int> data;

    long unsigned int lookup[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,0,11}};
    int r1 = 7 ,r2 = 9 ,r3 = 11, r4 = 13 ,c1 = 15,c2 = 17 ,c3 = 19;
    
    if (gpioInitialise()<0)
    {
        std::cout << "Keypad cannot be initialised";
       // return(0);
    }
    
    gpioSetMode(7, PI_INPUT);
    gpioSetMode(9, PI_INPUT);
    gpioSetMode(11, PI_INPUT);
    gpioSetMode(13, PI_INPUT);
    gpioSetMode(15, PI_INPUT);
    gpioSetMode(17, PI_INPUT);
    gpioSetMode(19, PI_INPUT);

    //Setting Pull Up Resistor
    gpioSetPullUpDown(7, PI_PUD_UP);
    gpioSetPullUpDown(9, PI_PUD_UP);
    gpioSetPullUpDown(11, PI_PUD_UP);
    gpioSetPullUpDown(13, PI_PUD_UP);
    gpioSetPullUpDown(15, PI_PUD_UP);
    gpioSetPullUpDown(17, PI_PUD_UP);
    gpioSetPullUpDown(19, PI_PUD_UP);

    

    while (1){
        if (gpioRead(7) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                data.push_back(lookup[0][0]);
            }
            else if (gpioRead(c2) == 0)
            {
                data.push_back(lookup[0][0]);
            }
            else if (gpioRead(c3) == 0)
            {
                data.push_back(lookup[0][0]);
            }
        }
        else if (gpioRead(r2) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                data.push_back(lookup[0][0]);
            }
            else if (gpioRead(c2) == 0)
            {
                data.push_back(lookup[0][0]);
            }
            else if (gpioRead(c3) == 0)
            {
                data.push_back(lookup[0][0]);
            }
        }
        else if (gpioRead(r3) == 0)
        {
            if (gpioRead(c1) == 0)
            {
                data.push_back(lookup[0][0]);
            }
            else if (gpioRead(c2) == 0)
            {
                data.push_back(lookup[0][0]);
            }
            else if (gpioRead(c3) == 0)
            {
                data.push_back(lookup[0][0]);
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
                data.push_back(lookup[0][0]);
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
    for (int i =0; i < data.size(); i++){
        std::cout << data.at(i);
    }

    gpioTerminate();
}
int NumpadDriver::wake(int data_pin)
{
    //int gpioInitialise();
    std::thread t(&NumpadDriver::readNumpad, this);
        //Initialising GPIO Pins
     
    t.join();
    return(1);
}


void NumpadDriver::registerCallback(NumpadCallback *np)
{
    numpadcallback.push_back(np);
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

    return 0;
}

//Add function to go back and forward. 
