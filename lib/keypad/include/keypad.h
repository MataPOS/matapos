#ifndef KEYPAD_H
#define KEYPAD_H

#include <iostream>
#include <thread>
#include <vector>


struct NumpadCallback{
    public : virtual void nums(std::vector<long unsigned int>) = 0;
    public : virtual void backwards(int) = 0;
    public : virtual void forwards(int) = 0;

};


class NumpadDriver{

    public:
    void wake(int);

    void readNumpad();

    void stop();
    
        
    //register Callbacks
    void KeypadCallbacks(NumpadCallback* np);

    //Callback functions
    void backwards(int);

    //Interupt handler
    void interuptHandler(int gpio, int level, uint32_t tick);


 private:
    int back; //flag for back button
    int forward;//flag for forward button

    std::thread keypadthread;

    std::vector<NumpadCallback*> callbacks; // Storing the numpad callbacks

    Numpad(); //constructor
};
























#endif

