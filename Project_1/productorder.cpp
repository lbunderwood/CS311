// productorder.cpp
// Luke Underwood
// September 3, 2020
// Source file for class ProductOrder

#include "productorder.h"
#include <string>
#include <ostream>

// Default Constructor
ProductOrder::ProductOrder()
{
	setName("UNSPECIFIED");
	setNumber(0);
}

// Two parameter constructor. Takes a product name as a string and a quantity as an int
// Precondition : see setNumber precondition
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
// Precondition : Number passed in must be >= 0 and less than the max integer ammount.
//				  Otherwise, it will be set to 0.
void ProductOrder::setNumber(int quantity)
{
	if (quantity > 0 && quantity < pow(2, 8 * sizeof(int) - 1) - 1)
	{
		quantity_ = quantity;
	}
	else
	{
		quantity_ = 0;
	}
}

// Returns true when quantity is 0, false if not
bool ProductOrder::empty() const
{
	return !quantity_;
}

// Returns a string output of the order information
std::string ProductOrder::toString() const
{
	return product_ + " (" + std::to_string(quantity_) + ")";
}

// Pre-increment operator overload
// Increases quantity_ by 1
// Precondition : quantity_ value must not be so great that incrementing it causes overflow.
//				  If this is the case, it will be capped at integer capacity, and it will not increment
ProductOrder& ProductOrder::operator++()
{
	if (quantity_ < pow(2, 8 * sizeof(int) - 1) - 1)
	{
		quantity_++;
	}
	return *this;
}

// Post-increment operator overload
// Increases quantity_ by 1
// Precondition : quantity_ value must not be so great that incrementing it causes overflow.
//				  If this is the case, it will be capped at integer capacity, and it will not increment.
ProductOrder ProductOrder::operator++(int)
{
	auto save = *this;
	++*this;
	return save;
}

// Pre-decrement operator overload
// Decreases quantity_ by 1
// Precondition : quantity_ > 0
//				  If quantity <= 0, it will not decrement
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
// Precondition : quantity_ > 0
//				  If quantity <= 0, it will not decrement
ProductOrder ProductOrder::operator--(int)
{
	auto save = *this;
	--*this;
	return save;
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