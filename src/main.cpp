#include<iostream>
#include "simplecameralib/printhello.h"
#include "simplecameralib/Camera_reader.h"

int main() {
	printhello();

	Mat frame;
	string window_name = "Captured Image";

	CameraReader C;
	frame = C.FeedCapture();
	namedWindow(window_name);

	imshow(window_name, frame);
	waitKey(0);

	return 0;
}
