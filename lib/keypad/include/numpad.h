#ifndef NUMPAD
#define NUMPAD

#include <iostream>
#include <thread>
#include <vector>


struct NumpadCallback{
    public virtual void hasData(unsigned long number) = 0;
};


class NumpadDriver{


    private:

    std::thread t;
    int wake(int);
    std::vector<NumpadCallback*>numpadcallback;
    std::vector<int>data;
    std::vector<DeleteItemCall*>

    vector<int> insertAtEnd(vector<int> v, int x);

    public:

        NumpadDriver();

        void registerCallback(NumpadCallback* np);

     //   void start();

        void readNumpad();
        void stop();

}

























#endif

