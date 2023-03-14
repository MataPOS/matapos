#IFNDEF LOAD_CELL
#DEFINE LOAD_CELL

#include<iostream>
#include<thread>
#include<vector>

struct LoadCellCallback {
	public virtual void hasData(unsigned long weight) = 0;
};

class LoadCell {

private:
	fd = 0;
	bool running;
	std::thread t;
	int isReady(int);
	void ReadLoadCell();
	std::vector<LoadCellCallback*> loadcellcallback;

public:
	void registerCallback(LoadCellCallback* lc);
	void start();
	void stop();

};