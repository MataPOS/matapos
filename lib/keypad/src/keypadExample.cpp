#include <opencv2\opencv.hpp>
#include"LoadCell.h"
#include<iostream>
#include<unistd.h>

using namespace cv;

using namespace std;


struct MyLoadCellCallback :LoadCellCallback {
public:
	void hasData(unsigned long weight) {

		std::cout << "Weight " << weight;

	}


};


void LoadCellMain()
{
	MyLoadCellCallback callback;

	LoadCell loadcell;

	loadcell.registerCallback(&callback);

	loadcell.start();

	std::cout << "Load Cell reading started";

	sleep(5);

	loadcell.stop();

	std::cout << "Load Cell Main thread finished";

}
