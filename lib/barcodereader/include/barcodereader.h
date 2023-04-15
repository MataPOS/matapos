#ifndef BARCODEREADER_H
#define BARCODEREADER_H

#include "camera.h"
#include "barcodereadercallback.h"
#include <string>

#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <zbar.h>

class BarcodeReader {

public:
	
	BarcodeReader();
	~BarcodeReader();
	
	
	
	struct Barcode
	{
	
	public:
	std::string barcodeType;
	std::string decodedData;
	
	};

	void decodeQRAndBarcode(cv::Mat &frame);
	void configureZbarScanner();
	void registerBarcodereaderCallback(BarcodeReaderCallback* clientCallbackPtr);
	
	/**
	* Implement Camera callback interface
	**/
	struct FrameAvailableCallback:CameraCallback {
		BarcodeReader* barcodeReaderPtr = nullptr;
		virtual void frameAvailable(cv::Mat& frame) {
			if(nullptr != barcodeReaderPtr) {
				barcodeReaderPtr -> decodeQRAndBarcode(frame);
			}
		}
	}; 


	zbar::ImageScanner zbarImageScanner;
	BarcodeReaderCallback* barcodeReaderCallbackPtr;
	FrameAvailableCallback frameAvailableCallback;
	
	cv::Mat grayImage;
	std::vector<Barcode> barcodes;
	Camera& camera = Camera::getCamera();
	
};



#endif
