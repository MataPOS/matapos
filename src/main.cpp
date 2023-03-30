#include "camera/camera.h"
#include "barcodereader/barcodereader.h"

#include "guiheaderfiles/window.h"

#include <QApplication>

int main(int argc, char* argv[]) {
	
	QApplication app(argc, argv);
	
	Window window;
	
	window.show();
	
	return app.exec();
}
