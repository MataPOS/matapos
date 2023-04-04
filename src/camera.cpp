#define DEBUG

#include "camera/camera.h"
#include <iostream>


Camera::Camera(int deviceId, int apiId) {
	deviceId = deviceId;
	apiId = apiId;
}

Camera::Camera() {
	deviceId = 0;
	apiId = cv::CAP_ANY;
	
	#ifdef DEBUG
		std::cout << "deviceId: " << deviceId << std::endl;
		std::cout << "apiId: " << apiId << std::endl;
	#endif	
	
}


void Camera::runCamera() {
	
	
		
		if(nullptr == cameraCallBackPtr)
		return;
		
		cv::Mat frame;
		videoCapture.read(frame);
		if(frame.empty()) {

			#ifdef DEBUG
				std::cerr << std::endl << "empty frame!" << std::endl;
			#endif
		}

        
		cameraCallBackPtr->frameAvailable(frame);
 

	
}


void Camera::threadloop()
{

	while(isRunning)
	{
		
		runCamera();
		
	}

}


void Camera::start() {
	
	videoCapture.open(deviceId, apiId);
	

	if(videoCapture.isOpened()) {
		
		#ifdef DEBUG
			std::cout << std::endl << "Camera opened successfully!" << std::endl;
		#endif
		
		isRunning = 1;
	}
	else {
		
		#ifdef DEBUG
			std::cerr << std::endl << "Error occured...Unable to open camera..." << std::endl;
		#endif

		return;
	}
	
	// run camera in a separate thread
	cameraThread = std::thread(&Camera::threadloop, this);
	
	
}

void Camera::stop() {
	isRunning = 0;
	cameraThread.join();
}

 
Camera::~Camera() {
	
	#ifdef DEBUG
		std::cout << std::endl << "Inside Camera destructor" << std::endl;
		std::cout << std::endl << "isRunning: " << isRunning << std::endl;
	#endif
}
