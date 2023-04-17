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



/**

Constructor of BarcodeReader class


*/
BarcodeReader::BarcodeReader() {


	
	time(&start);
	frameAvailableCallback.barcodeReaderPtr = this;
	camera.registerFrameAvailableCallback(&frameAvailableCallback);


}

BarcodeReader::~BarcodeReader() {
	
}


/**

Configures the zbar library image scanner


*/

void BarcodeReader::configureZbarScanner() {
	zbarImageScanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);
}


/**

Registers the client callback for the barcode reader


*/

void BarcodeReader::registerBarcodereaderCallback(BarcodeReaderCallback* clientCallbackPtr) {
	barcodeReaderCallbackPtr = clientCallbackPtr;
}


/**

Decodes the barcode image recieved and pushes the decoded data to the registered callbacks


*/

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
		
		// 15 April 2023 - Move the check condition to the database class preferebly
		
		if(barcode.decodedData.substr(0,4) == "cust") // checks if the id detected is customer
		{
		
		barcodeReaderCallbackPtr -> uniqueIdAvailable(barcode.decodedData, "customer_identification");
		}
		
		else if(barcode.decodedData.substr(0,5) == "stock") // checks if the id detected is stock
		{
		
		barcodeReaderCallbackPtr -> uniqueIdAvailable(barcode.decodedData, "stock_identification");
		
		}
		
		}

	}
}
