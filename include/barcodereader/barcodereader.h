#ifndef BARCODEREADER_H
#define BARCODEREADER_H


class BarcodeReader: public Camera {

public:
	
	BarcodeReader();
	
	~BarcodeReader();

	void decodeBarcode(cv::Mat &frame);
	
	virtual void queryCustomerDetails(std::string customerId) = 0;

	virtual void queryItemDetails(std::string itemDetails) = 0;

}

#endif