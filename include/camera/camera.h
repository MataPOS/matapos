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

using namespace std;
using namespace cv;

typedef struct
{
  string type;
  string data;
  vector <Point> location;
} decodedObject;


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

	// qrcode decode callback
	void qrDecoderCallback(cv::Mat frame);

	void decode(Mat &im, vector<decodedObject>&decodedObjects);

private:
	
	int isRunning = 0;
	int deviceId;
	int apiId;

	cv::VideoCapture videoCapture;
	std::thread cameraThread;
};

#endif
