#ifndef CAMERA_H
#define CAMERA_H

#define DEBUG

#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include<iostream>
#include <opencv2/opencv.hpp>

/**

Callback structure to be implemented by the client class


*/

struct CameraCallback {
		
		// Callback to be implemented by client to make use of available frame	
		virtual void frameAvailable(cv::Mat &frame) = 0;
	};

/**

Camera class interacts with the camera and posts images. This implements the Singleton pattern to avoid conflict between separate threads accessing camera


*/
class Camera {

public:


	static Camera& getCamera();
	
	
	static Camera& getCamera(int deviceId, int apiId);
	
	
	~Camera(); // destructor

	
	void start(); // starts the camera thread frame acquisition process

	
	void stop(); // stops camera thread and frame acquisition process

	
	void runCamera(); // acquires the frames from camera and calls the registered callback functions from clients 
	
	
	void threadloop(); // function for the camera thread it calls runcamera()

	

	// method to register client with the callback to make use of it
	void registerFrameAvailableCallback(CameraCallback* clientCallbackPtr);
	

private:

	int camera_open = 0;
	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;
	
	
	int isRunning = 0; // flag for camera thread
	int deviceId;
	int apiId;
	
	cv::VideoCapture videoCapture;
	
	std::thread cameraThread;
	std::vector<CameraCallback*> cameraCallBackPtr; // A list for storing different callback functions for multiple classes using the camera.


	
	
	 Camera(); // Constructor with default settings
	 Camera(int deviceId, int apiId);

};

#endif
