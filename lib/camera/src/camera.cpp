#define DEBUG

#include "camera.h"
#include <iostream>


/**

This function should be called is someone wants to get the camera object to access camera. It is created as part of singleton pattern.


*/

Camera& Camera::getCamera()
{

	static Camera singleCamera;
	return singleCamera;
}

/**

This function should be called is someone wants to get the camera object to access camera. It is created as part of singleton pattern. Only it facilitates to use custom device ID if available.


*/

Camera& Camera::getCamera(int deviceId, int apiId)
{


		
		static Camera singleCamera(deviceId,apiId);
		return singleCamera;


}

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

/**

This function is called by the camera thread function threadloop. It reads the frame from camera and sends the frame to all registered callbacks


*/

void Camera::runCamera() {
	
	
		
		if(cameraCallBackPtr.empty())
		return;
		
		cv::Mat frame;
		videoCapture.read(frame);
		
		if(frame.empty()) {

			#ifdef DEBUG
				std::cerr << std::endl << "empty frame!" << std::endl;
			#endif
		}

        	cv::cvtColor(frame,frame,cv::COLOR_BGR2RGB);
		
		for(auto cc: cameraCallBackPtr)
		{
		
		
		cc->frameAvailable(frame);
		
		}

 

	
}


/**

Camera thread function


*/

void Camera::threadloop()
{

	while(isRunning)
	{
		
		runCamera();
		
	}

}

/**

Used to initialize and start the camera, and initialize the camera thread


*/
void Camera::start() {
	
	if(camera_open)
	return;
	
	camera_open = 1;
	
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

/**

Stops the camera


*/

void Camera::stop() {
	isRunning = 0;
	camera_open = 0;
	cameraThread.join();
}

 
Camera::~Camera() {


		
	
	#ifdef DEBUG
		std::cout << std::endl << "Inside Camera destructor" << std::endl;
		std::cout << std::endl << "isRunning: " << isRunning << std::endl;
	#endif
	
	this->stop();
}

/**

Registers the client callback to recieve the frames


*/


void Camera::registerFrameAvailableCallback(CameraCallback* clientCallbackPtr) {
		

		cameraCallBackPtr.push_back(clientCallbackPtr);
		#ifdef DEBUG
			std::cout << std::endl << "inside register callback method" << std::endl;
		#endif
	}


