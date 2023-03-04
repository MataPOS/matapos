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



Camera::Camera(int deviceId, int apiId) {
	deviceId = deviceId;
	apiId = apiId;
	videoCapture = std::make_unique<cv::VideoCapture>();
}

void Camera::qrDecoderCallback(cv::Mat frame) {
	cv::QRCodeDetector qrDecoder = cv::QRCodeDetector();
	std::string data = qrDecoder.detectAndDecode(frame);
	if(data.length() > 0) {
		std::cout << "Decoded QR code = " << data;
	} 
}

void Camera::runCamera() {
	while(isRunning) {
		cv::Mat frame;
		videoCapture->read(frame);
		if(frame.empty()) {
			std::cerr << "empty frame!";
		}
		qrDecoderCallback(frame);

	}
}


void Camera::start() {
	isRunning = 1;
	videoCapture->open(deviceId, apiId);
	cameraThread = std::thread(&Camera::runCamera, this);

}

void Camera::stop() {
	isRunning = 0;
}

Camera::~Camera() {
	
}