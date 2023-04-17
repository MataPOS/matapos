#ifndef CART_H
#define CART_H

#include "stock.h"

#include <iostream>

class Cart {

	public:
		Cart() {};
		
		std::string customerId;
		std::vector<Stock> itemList;
		double totalCost;

};	

#endif
