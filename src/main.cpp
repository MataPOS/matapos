#include "simplecameralib/printhello.h"
#include "simplecameralib/Camera_reader.h"

#include <iostream>
#include <camera.h>

int main() {

	CameraSettings cameraSettings;
	Camera camera(cameraSettings);
	
	camera.start();
	
	return 0;
	
}
