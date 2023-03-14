#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class CameraReader
{
public:

	Mat FeedCapture()
	{
		Mat frame1 = Mat::zeros(Size(100, 100), CV_8UC1);
		VideoCapture cap(0); // open camera with id '0'
		if (cap.isOpened() == false)
		{
			cout << "Cannot open the video camera" << endl;
			cin.get(); //wait for any key press
			return frame1;
		}
		string window_name = "Camera Feed";
		namedWindow(window_name);

		Mat frame;
		while (true)
		{
			
			bool bSuccess = cap.read(frame); // read a new frame from video 

			//Breaking the while loop if the frames cannot be captured
			if (bSuccess == false)
			{
				cout << "Video camera is disconnected" << endl;
				cin.get(); //Wait for any key press
				break;
			}


			if ((char) waitKey(1) == 'q')
			{
				destroyWindow(window_name);
				return(frame);
			}

			
			imshow(window_name, frame);

			
			if (waitKey(10) == 27)
			{
				cout << "Esc key is pressed by user. Stoppig the video" << endl;
				break;
			}
		}



	}
	
	
};