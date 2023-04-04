#ifndef CAMERA_H
#define CAMERA_H

#define DEBUG

#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include<iostream>

struct CameraCallback {
		
		// Callback to be implemented by client to make use of available frame	
		virtual void frameAvailable(cv::Mat &frame) = 0;
	};

class Camera {

public:

	// Constructor with default settings
	Camera();

	// Constructor
	Camera(int deviceId, int apiId);

	// destructor
	~Camera();

	// starts frame acquisition process
	void start();

	// stops frame acquisition
	void stop();

	// start running camera and acquiring frames
	void runCamera();
	
	void threadloop();

	

	// method to register client with the callback to make use of it
	void registerFrameAvailableCallback(CameraCallback* clientCallbackPtr) {
		cameraCallBackPtr = clientCallbackPtr;
		#ifdef DEBUG
			std::cout << std::endl << "inside register callback method" << std::endl;
		#endif
	}


private:
	
	int isRunning = 0;
	int deviceId;
	int apiId;

	cv::VideoCapture videoCapture;
	
	std::thread cameraThread;
	//std::vector<CameraCallback*> cameraCallBackPtr; // A list for storing different callback functions for multiple classes using the camera.

	CameraCallback* cameraCallBackPtr = nullptr; // Single callback
};

#endif
