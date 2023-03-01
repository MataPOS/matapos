#include "camera.h"

#include <thread>

Camera::~camera() {
	stop();
}

Camera::start(int deviceId, int apiId) {
	running = 1;
	videoCapture.open(deviceId, apiId);
	cameraThread = new std::thread(exec,this);
}

Camera::stop() {
	running = 0;
	cameraThread = nullptr;
}

Camera::registerCallback(FrameCallback* callback){
	callback = frameCallback;
}

Camera::unregisterCallback() {
	cameraCallback = nullptr;
}
