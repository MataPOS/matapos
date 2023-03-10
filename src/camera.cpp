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

void Camera::decodeQRAndBarcode(cv::Mat &frame) {

	// convert frame to grayscale image
	cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY);
	 
	// wrap frame into a zbar image
	zbar::Image zbarImageWrapper(frame.cols, frame.rows, "Y800", (uchar *)grayImage.data, frame.cols * frame.rows);
	 
	// Scan for barcodes
	zbarImageScanner.scan(zbarImageWrapper);
	
	for(zbar::Image::SymbolIterator symbol = zbarImageWrapper.symbol_begin(); symbol != zbarImageWrapper.symbol_end(); ++symbol){
		
		Barcode barcode;
		
		barcode.barcodeType = symbol->get_type_name();
		barcode.decodedData = symbol->get_data();
		
		 
		#ifdef DEBUG
			std::cout << std::endl << "Type : " << barcode.barcodeType << std::endl;
			std::cout << std::endl << "Data : " << barcode.decodedData << std::endl;
		#endif
		
		barcodes.push_back(barcode);
	}
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
	
	configureZbarScanner();
}

void Camera::configureZbarScanner() {
	zbarImageScanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

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
        
        // QR decode callback
		decodeQRAndBarcode(frame);
 

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
