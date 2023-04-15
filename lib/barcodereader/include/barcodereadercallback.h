#ifndef BARCODEREADERCALLBACK_H
#define BARCODEREADERCALLBACK_H

/**
*Callback interface to be implemented by client
**/



class BarcodeReaderCallback {

	public:
		virtual void uniqueIdAvailable(std::string, std::string flow) = 0;
};

#endif
