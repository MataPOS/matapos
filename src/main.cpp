#include "simplecameralib/printhello.h"
#include "simplecameralib/Camera_reader.h"
#include "camera/camera.h"

#include <iostream>
#include <memory>

int main() {
	

	std::unique_ptr<Camera> camera = std::make_unique<Camera>(0,1);
	camera->start();


	/*printhello();

	Mat frame;
	string window_name = "Captured Image";

	CameraReader C;
	frame = C.FeedCapture();
	namedWindow(window_name);

	imshow(window_name, frame);
	waitKey(0); */

	return 0;
}
