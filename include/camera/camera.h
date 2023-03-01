#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/core.hpp>
#include <opencv2videoio.hpp>

#include <stdlib.h>
#include <thread>

class frameCallback {
	virtual void hasFrame(float frame) = 0;
};

sruct CameraSettings {
	int deviceId = 0;
};

class Camera{

public:
	// Constructor
	camera() = default;
	
	// destructor
	~camera();
	
	void registerCallback(CameraCallback* callback);
	
	void unregisterCallback();
	
	// start frame acquisition
	void start();

	// stop frame aqcuisition
	void stop();

private:
	int running = 0; // camera status
	CameraSettings cameraSettings;
	
	FrameCallback* frameCallback = nullptr;
	std::thread* cameraThread = nullptr;
	cv::VideoCapture videoCapture;
};

#endif
