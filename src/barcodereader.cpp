#define DEBUG

#include "camera/camera.h"
#include "barcodereader/barcodereader.h"

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

BarcodeReader::BarcodeReader() {

	BarcodeReaderCallback.barcodeReader = this;

	camera.registerFrameAvailableCallback(barcodeReaderCallback);

	configureZbarScanner();

}

BarcodeReader::~BarcodeReader() {

}

void BarcodeReader::ConfigureZbarScanner() {
	zbarImageScanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);
}


void BarcodeReader::decodeQRAndBarcode(cv::Mat& frame) {
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