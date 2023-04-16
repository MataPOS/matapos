#ifndef KEYPAD_H
#define KEYPAD_H

#include <iostream>
#include <thread>
#include <vector>


struct NumpadCallback{
    public virtual void hasData(unsigned long number) = 0;
};


class NumpadDriver{


    public:

    std::thread t;
    int wake(int);
    std::vector<NumpadCallback*>numpadcallback;
    std::vector<int>data;


    NumpadDriver();
        
    vector<int> insertAtEnd(vector<int> v, int x);

    void registerCallback(NumpadCallback* np);
    //Interupts
    static void backITR(int gpio, int level, unsigned int tick, void *userdata);
        //
    static void forwardITR(int gpio, int level, unsigned int tick, void *userdata); 

    void start();

    void readNumpad();
    void stop();

}

























#endif

