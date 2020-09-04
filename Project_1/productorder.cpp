// productorder.cpp
// Luke Underwood
// September 3, 2020
// Source file for class ProductOrder

#include "productorder.h"

// Default Constructor
ProductOrder::ProductOrder()
{

}

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

// Two parameter constructor. Takes a product name as a string and a quantity as an int
ProductOrder::ProductOrder(std::string product, int quantity)
{

}

// Getter function for the product name
std::string ProductOrder::getName() const
{

}

// Getter function for the quantity
int ProductOrder::getNumber() const
{

}

// Setter function for the product name
void ProductOrder::setName(std::string product)
{

}

// Setter function for the quantity
void ProductOrder::setNumber(int quantity)
{

}

// Returns whether the quantity is 0 or not
bool ProductOrder::empty() const
{

}

// Returns a string output of the order information
std::string ProductOrder::toString() const
{

}

// Pre-increment operator overload
ProductOrder& ProductOrder::operator++()
{

}

// Post-increment operator overload
ProductOrder& ProductOrder::operator++(int)
{

}

// Pre-decrement operator overload
ProductOrder& ProductOrder::operator--()
{

}

// Post-decrement operator overload
ProductOrder& ProductOrder::operator--(int)
{

}

// Comparison operator, returns true if both product_ and quantity_ are equal
bool operator==(const ProductOrder& left, const ProductOrder& right)
{

}

// Comparison operator, returns true if product_ or quantity_ is not equal
bool operator!=(const ProductOrder& left, const ProductOrder& right)
{

}

// Stream insertion operator, which inserts the results of toString
std::ostream& operator<<(std::ostream& os, const ProductOrder& order)
{

}