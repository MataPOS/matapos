#ifndef CAMERA_H
#define CAMERA_H

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

/*
 * Barcodes are of 1D and 2D.
 * 1D barcode is also called QR code.
 */
typedef struct{
  std::string barcodeType;
  std::string decodedData;
} Barcode;


class Camera {

public:

	// Constructor with default settings
	Camera();

	// Constructor
	Camera(int deviceId, int apiId);

	// destructor
	~Camera();

	// starts frame acquisition process
	void start();

	// stops frame acquisition
	void stop();

	// start running camera and acquiring frames
	void runCamera();

	void qrDecoderCallback(cv::Mat frame);

	void decodeQRAndBarcode(cv::Mat &frame);
	
	void configureZbarScanner();

	// callback whenever a frame is available for use
	virtual void frameAvailable(cv::Mat &frame) = 0;

private:
	
	zbar::ImageScanner zbarImageScanner;
	
	cv::Mat grayImage;
	
	std::vector<Barcode> barcodes;
	
	int isRunning = 0;
	int deviceId;
	int apiId;

	cv::VideoCapture videoCapture;
	
	std::thread cameraThread;
};

#endif
