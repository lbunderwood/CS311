// productorder.h
// Luke Underwood
// September 3, 2020
// Header for class ProductOrder

#ifndef PRODUCTORDER_H
#define PRODUCTORDER_H

#include<string>

// A ProductOrder holds the name and quantity of a product being ordered
// Invariants: quantity_ >= 0
class ProductOrder
{
public:

	// Default Constructor
	ProductOrder();

	// Big Five, all set to be written by the compiler
	ProductOrder(const ProductOrder& other) = default;
	ProductOrder(ProductOrder&& other) = default;
	ProductOrder& operator=(const ProductOrder& other) = default;
	ProductOrder& operator=(ProductOrder&& other) = default;
	~ProductOrder() = default;

	// Two parameter constructor. Takes a product name as a string and a quantity as an int
	// Precondition : see setNumber precondition
	ProductOrder(std::string product, int quantity);

	// Getter function for the product name
	std::string getName() const;

	// Getter function for the quantity
	int getNumber() const;

	// Setter function for the product name
	void setName(std::string product);

	// Setter function for the quantity
	// Precondition : Number passed in must be >= 0 and less than the max integer ammount.
	//				  Otherwise, it will be set to 0.
	void setNumber(int quantity);

	// Returns true when quantity is 0, false if not
	bool empty() const;

	// Returns a string output of the order information
	std::string toString() const;

	// Pre-increment operator overload
	// Increases quantity_ by 1
	// Precondition : quantity_ value must not be so great that incrementing it causes overflow.
	//				  If this is the case, it will be capped at integer capacity, and it will not increment
	ProductOrder& operator++();

	// Post-increment operator overload
	// Increases quantity_ by 1
	// Precondition : quantity_ value must not be so great that incrementing it causes overflow.
	//				  If this is the case, it will be capped at integer capacity, and it will not increment
	ProductOrder operator++(int);

	// Pre-decrement operator overload
	// Decreases quantity_ by 1
	// Precondition : quantity_ > 0
	//				  If quantity <= 0, it will not decrement
	ProductOrder& operator--();

	// Post-decrement operator overload
	// Decreases quantity_ by 1
	// Precondition : quantity_ > 0
	//				  If quantity <= 0, it will not decrement
	ProductOrder operator--(int);


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