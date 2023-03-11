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
	
	Camera camera;

	BarcodeReaderCallback barcodeReaderCallback;

	BarcodeReader();
	
	~BarcodeReader();

	void decodeQRAndBarcode(cv::Mat &frame);

	void configureZbarScanner();

	struct BarcodeReaderCallback: Camera::CameraCallback {
		BarcodeReader* barcodeReader = nullptr;

		virtual void frameAvailable(cv::Mat &frame) {
			if(nullptr != barcodeReader){
				BarcodeReader -> decodeQRAndBarcode(frame);
			}
		}

		// callback to be called when a unique id is available
		virtual void uniqueIdAvailable(std::string itemId) = 0;

	}

	void registerBarcodeReaderCallback(BarcodeReaderCallback* barcodeReaderCallback) {
		uniqueIdAvailableCallback = barcodeReaderCallback;
	}

private:

	BarcodeReaderCallback* uniqueIdAvailableCallback = nullptr;

	zbar::ImageScanner zbarImageScanner;
	
	cv::Mat grayImage;
	
	std::vector<Barcode> barcodes;
	
}

#endif