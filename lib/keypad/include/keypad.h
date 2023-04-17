#ifndef KEYPAD_H
#define KEYPAD_H

#include <iostream>
#include <thread>
#include <vector>


struct NumpadCallback{
    public : virtual void nums(std::vector<long unsigned int>) = 0;

};
struct forwardCallback{
    public : virtual void forwards(int) = 0;
};

struct backCallback{
    public : virtual void backwards(int) = 0;
};


class NumpadDriver{

    public:
    void wake(int);

    void readNumpad();

    void stop();
    backCallback* back;
    forwardCallback* forward;
        
    //register Callbacks
    void KeypadCallbacks(NumpadCallback* np);

    //Callback functions
    void forwards(forwardCallback* fwd);
    void backwards(backCallback* bck);

    ~NumpadDriver();

    //int back; //flag for back button
    //int forward;//flag for forward button

    std::thread keypadthread;

    std::vector<NumpadCallback*> callbacks; // Storing the numpad callbacks

    NumpadDriver(); //constructor

    //Interupt handler
    void static interuptHandler(int gpio, int level, uint32_t tick)
{
    static int state_1 = -1;//Forwards
    static int state_2 = -1;//Forwards
    static int state_3 = -1;//Backwards

    if (gpio == 13)
    {
        state_1 = level;

    } else if (gpio == 15)
    {
        state_2 = level;
    }else if (gpio == 19)
    {
        state_3 = level;}

    if (state_2 == 0 && state_1 == 0)
    {
        int back = 1;
        for (auto  back: backCallback)
        {
            back->backwards(0);
        }
    }
    else if (state_1 == 0 && state_3 == 0)
    {
        int forward = 1;
        for (auto  forward: forwardCallback)
        {
            forward->forwards(0);
        }
    }
}
};
























#endif

