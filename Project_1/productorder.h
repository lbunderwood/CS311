// productorder.h
// Luke Underwood
// September 3, 2020
// Header for class ProductOrder

#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include<string>

// A Product Order holds the name and quantity of a product being ordered
// Invariants: quantity_ >= 0
class ProductOrder
{
public:

	// Default Constructor
	ProductOrder();

	// Copy Constructor
	ProductOrder(const ProductOrder& other) = default;

	// Move Constructor
	ProductOrder(ProductOrder&& other) = default;

	// Copy Assignment Operator
	ProductOrder& operator=(const ProductOrder& other) = default;

	// Move Assignment Operator
	ProductOrder& operator=(ProductOrder&& other) = default;

	// Destructor
	~ProductOrder() = default;

	// Two parameter constructor. Takes a product name as a string and a quantity as an int
	ProductOrder(std::string product, int quantity);

	// Getter function for the product name
	std::string getName() const;

	// Getter function for the quantity
	int getNumber() const;

	// Setter function for the product name
	void setName(std::string product);

	// Setter function for the quantity
	void setNumber(int quantity);

	// Returns whether the quantity is 0 or not
	bool empty() const;

	// Returns a string output of the order information
	std::string toString() const;

	// Pre-increment operator overload
	ProductOrder& operator++();

	// Post-increment operator overload
	ProductOrder& operator++(int);

	// Pre-decrement operator overload
	ProductOrder& operator--();

	// Post-decrement operator overload
	ProductOrder& operator--(int);


private: // Data Members

	// Holds the name of the product being ordered
	std::string product_;

	// Holds the quantity of the product to order
	int quantity_;

};

// Comparison operator, returns true if both product_ and quantity_ are equal
bool operator==(const ProductOrder& left, const ProductOrder& right);

// Comparison operator, returns true if product_ or quantity_ is not equal
bool operator!=(const ProductOrder& left, const ProductOrder& right);

// Stream insertion operator, which inserts the results of toString
std::ostream& operator<<(std::ostream& os, const ProductOrder& order);

#endif //PRODUCTORDER_H