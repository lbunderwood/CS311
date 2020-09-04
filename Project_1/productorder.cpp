// productorder.cpp
// Luke Underwood
// September 3, 2020
// Source file for class ProductOrder

#include "productorder.h"
#include <string>
#include <sstream>

// Default Constructor
ProductOrder::ProductOrder()
{
	setName("UNSPECIFIED");
	setNumber(0);
}
/*
// Copy Constructor
ProductOrder::ProductOrder(const ProductOrder& other)
{

}

// Move Constructor
ProductOrder::ProductOrder(ProductOrder&& other)
{

}

// Copy Assignment Operator
ProductOrder& ProductOrder::operator=(const ProductOrder& other)
{

}

// Move Assignment Operator
ProductOrder& ProductOrder::operator=(ProductOrder&& other)
{

}

// Destructor
ProductOrder::~ProductOrder()
{

}
*/
// Two parameter constructor. Takes a product name as a string and a quantity as an int
ProductOrder::ProductOrder(std::string product, int quantity)
{
	setName(product);
	setNumber(quantity);
}

// Getter function for the product name
std::string ProductOrder::getName() const
{
	return product_;
}

// Getter function for the quantity
int ProductOrder::getNumber() const
{
	return quantity_;
}

// Setter function for the product name
void ProductOrder::setName(std::string product)
{
	product_ = product;
}

// Setter function for the quantity
// If a negative value is given, it is set to 0
void ProductOrder::setNumber(int quantity)
{
	if (quantity > 0)
	{
		quantity_ = quantity;
	}
	else
	{
		quantity_ = 0;
	}
}

// Returns whether the quantity is 0 or not
bool ProductOrder::empty() const
{
	return quantity_;
}

// Returns a string output of the order information
std::string ProductOrder::toString() const
{
	return product_ + " (" + std::to_string(quantity_) + ")";
}

// Pre-increment operator overload
// Increases quantity_ by 1
ProductOrder& ProductOrder::operator++()
{
	quantity_++;
	return *this;
}

// Post-increment operator overload
// Increases quantity_ by 1
ProductOrder ProductOrder::operator++(int)
{
	return ++*this;
}

// Pre-decrement operator overload
// Decreases quantity_ by 1
// Does nothing if quantity is 0
ProductOrder& ProductOrder::operator--()
{
	if (quantity_ > 0)
	{
		quantity_--;
	}
	return *this;
}

// Post-decrement operator overload
// Decreases quantity_ by 1
// Does nothing if quantity is 0
ProductOrder ProductOrder::operator--(int)
{
	return --*this;
}

// Comparison operator, returns true if both product_ and quantity_ are equal
bool operator==(const ProductOrder& left, const ProductOrder& right)
{
	return left.getName() == right.getName() && left.getNumber() == right.getNumber();
}

// Comparison operator, returns true if product_ or quantity_ is not equal
bool operator!=(const ProductOrder& left, const ProductOrder& right)
{
	return !(left == right);
}

// Stream insertion operator, which inserts the results of toString
std::ostream& operator<<(std::ostream& os, const ProductOrder& order)
{
	os << order.toString();
	return os;
}