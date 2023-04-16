#ifndef CART_H
#define CART_H

#include "cartitem.h"

#include <iostream>

class Cart {

	public:
		Cart();
		
		std::string customerId;
		std::vector<CartItem> itemList;
		float totalCost;

};	

#endif
