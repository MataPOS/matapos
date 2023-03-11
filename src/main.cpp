#include "camera/camera.h"


int main() {
	

	std::unique_ptr<Camera> camera = std::make_unique<Camera>();
	std::unique_ptr<BarcodeReader> barcodeReader = std::make_unique<BarcodeReader>();
	
	camera->start();
	
	return 0;
}
