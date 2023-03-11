#define DEBUG

#include "camera/camera.h"

#include <thread>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <memory>
#include <thread>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <zbar.h>


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
	
	configureZbarScanner();
}


void Camera::runCamera() {
	
	while(isRunning){
		
		cv::Mat frame;
		videoCapture.read(frame);
		if(frame.empty()) {

			#ifdef DEBUG
				std::cerr << std::endl << "empty frame!" << std::endl;
			#endif
		}

		imshow("Video Player", frame);
		if (cv::waitKey(5) >= 0){
			stop();
		}
        
        // frame available callback
		frameAvailableCallback->decodeQRAndBarcode(frame);
 

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
	cameraThread = std::thread(&Camera::runCamera, this);

}

void Camera::stop() {
	isRunning = 0;
}

 
Camera::~Camera() {
	
	#ifdef DEBUG
		std::cout << std::endl << "Inside Camera destructor" << std::endl;
		std::cout << std::endl << "isRunning: " << isRunning << std::endl;
	#endif
	
	cameraThread.join();
}
