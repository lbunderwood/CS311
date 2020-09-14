// Luke Underwood
// 9/13/2020
// CS311 - Data Structures and Algorithms
// msarray.h
// Header and implementation for template class MSArray

#ifndef MSARRAY_H
#define MSARRAY_H

#include<utility>

// Template Class MSArray (moderately smart array)
// A class meant to weakly imitate std::vector
// Invariants : 
// Template Type Restrictions : 
template <typename T>
class MSArray
{
public:

	// Default Constructor
	MSArray()
	{

	}

	////////////////////////////////////////////////
	// Big Five Constructors - defined explicitly //
	////////////////////////////////////////////////

	// Copy Constructor
	MSArray(const MSArray& old)
	{

	}

	// Move Constructor
	MSArray(MSArray&& old)
	{

	}

	// Copy Assignment Operator
	MSArray operator=(const MSArray& old)
	{

	}

	// Move Assignment Operator
	MSArray operator=(MSArray&& old)
	{

	}

	/////////////////////////////
	// Public Member Functions //
	/////////////////////////////

private:

	//////////////////////////////
	// Private Member Functions //
	//////////////////////////////

	void mswap(MSArray& other)
	{
		std::swap(this->arr, other.arr);
	}

	//////////////////////////////
	// Private Member Variables //
	//////////////////////////////

	T arr;
};

#endif // MSARRAY_H
