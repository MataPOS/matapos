#include<LoadCell.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#include<iostream>
#include<thread>
#include<pigpio.h>


int LoadCell::isReady(int data_pin) // checks if the HX711 is ready to provide data
{
	return(!gpioRead(data_pin)); // if data pin is low then the HX711 is ready to read the data
}


void LoadCell::ReadLoadCell() // define code to read the data from the Load Cell ADC converter HX711
{
	
	int data = 0; // the data variable will store the data gathered from the read operation

	// selecting the PI pins for data and clock signals
	int data_pin = 5;
	int clock_pin = 6;
	uint32_t t1 = 100,t3 = 30, t4 = 50, tout = 0; // t1 is initial delay of clock signal, t3 is the delay for high input (max 50 micro sec), t4 is delay for low input
	
	//initializing the gpio
	if (gpioInitialize() < 0)
	{
		std::cout << "GPIO cannot be initialized";
		return();
	}
	
	// setting the pin modes
	gpioSetMode(data_pin, PI_INPUT);
	gpioSetMode(clock_pin, PI_OUTPUT);

	while (!isReady(data_pin) && running) // waiting for the load cell to be ready to give data
	{
		std::cout << "Waiting for load cell to be ready with data";

	}
	

	//sending 25 clock pulses to set the gain to 128 in the following for loop

	for (int i = 0; i < 25; i++)
	{
		//added gpio delay to simulate wave between both writes 

		tout = gpioDelay(t4);

		gpioWrite(clock_pin, 1);

		tout = gpioDelay(t3);

		gpioWrite(clock_pin, 0);

	}

	


	//reading the 24 bit data and transmitting via callback hasData()
	while (running)
	{
		tout = gpioDelay(t1);
		
		for (int i = 0; i < 24; i++)
		{

			tout = gpioDelay(t4);

			gpioWrite(clock_pin, 1);

			data = data + gpioRead(data_pin);
			data = data << 1;

			tout = gpioDelay(t3);

			gpioWrite(clock_pin, 0);

		}

		tout = gpioDelay(t4);

		gpioWrite(clock_pin, 1);

		tout = gpioDelay(t3);

		gpioWrite(clock_pin, 0);

		//convert data from 2s complement to integer

		data = (data ^ 16777215) | 1; // 16777215 is decimal of 0xFFFFFF, which is high bits in 24 digits
		
		
		
		//Send the data via hasData function

		for (auto lc : loadcellcallback)
		{
			lc->hasData(data);
		}
			

	}

	

	gpioTerminate();
}

void LoadCell::registerCallback(LoadCellCallback* lc)
{
	loadcellcallback.push_back(lc);

}

void LoadCell::start()
{
	t = thread::(&LoadCell::ReadLoadCell, this);
}

void LoadCell::stop()
{
	running = false;
	t.join();

}