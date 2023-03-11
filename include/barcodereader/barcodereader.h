#ifndef BARCODEREADER_H
#define BARCODEREADER_H

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

	void decodeQRAndBarcode(cv::Mat &frame);

	void configureZbarScanner();

	struct BarcodeReaderCallback: Camera::CameraCallback {
		BarcodeReader* barcodeReaderPtr = nullptr;
		virtual void frameAvailable(cv::Mat& frame) {
			if(nullptr != barcodeReaderPtr) {
					barcodeReaderPtr -> decodeQRAndBarcode(frame);
			}
		}
	};
	

	BarcodeReaderCallback barcodeReaderCallback;

	std::unique_ptr<Camera> cameraPtr;

	std::unique_ptr<BarcodeReaderCallback> uniqueIdAvailableCallback = nullptr;

	zbar::ImageScanner zbarImageScanner;
	
	cv::Mat grayImage;
	
	std::vector<Barcode> barcodes;
	
};

#endif
