#define DEBUG

#include "camera.h"
#include "barcodereader.h"

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



//Modify this constructor to differentiate whether the object is created to read customer data, or the item data - 12 April 2023
BarcodeReader::BarcodeReader() {

	
	time(&start);
	frameAvailableCallback.barcodeReaderPtr = this;
	camera.registerFrameAvailableCallback(&frameAvailableCallback);
	
}

BarcodeReader::~BarcodeReader() {
	
}

void BarcodeReader::configureZbarScanner() {
	zbarImageScanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);
}

void BarcodeReader::registerBarcodereaderCallback(BarcodeReaderCallback* clientCallbackPtr) {
	barcodeReaderCallbackPtr = clientCallbackPtr;
}

void BarcodeReader::decodeQRAndBarcode(cv::Mat& frame) {
	configureZbarScanner();
	
	// convert frame to grayscale image
	cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY);
	 
	// wrap frame into a zbar image
	zbar::Image zbarImageWrapper(frame.cols, frame.rows, "Y800", (uchar *)grayImage.data, frame.cols * frame.rows);
	 
	// Scan for barcodes
	zbarImageScanner.scan(zbarImageWrapper);
	
	
	for(zbar::Image::SymbolIterator symbol = zbarImageWrapper.symbol_begin(); symbol != zbarImageWrapper.symbol_end(); ++symbol){
		
		time(&end);
		
		int duration = difftime(end, start);
		std::cout<<" "<<difftime(end, start)<<" ";
		
		time(&start);
		Barcode barcode;
		
		barcode.barcodeType = symbol->get_type_name();
		barcode.decodedData = symbol->get_data();
				 
		/*
		#ifdef DEBUG
			std::cout << std::endl << "Type : " << barcode.barcodeType << std::endl;
			std::cout << std::endl << "Data : " << barcode.decodedData << std::endl;
		#endif
		*/
		if(duration > 2){
		barcodeReaderCallbackPtr -> uniqueIdAvailable(barcode.decodedData, "customer_identification");	// Replace the term "customer_identification" with the suitable variable name depending on the customer or item identification - 12 April 2023	
		}
	}
}
