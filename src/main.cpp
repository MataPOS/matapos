#include "camera/camera.h"


int main() {
	

	std::unique_ptr<Camera> camera = std::make_unique<Camera>();
	camera->start();

	return 0;
}
