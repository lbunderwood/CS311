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
		this->MSArray(8);
	}

	////////////////////////////////////////////////
	// Big Five Constructors - defined explicitly //
	////////////////////////////////////////////////

	// Copy Constructor
	MSArray(const MSArray& old)
	{
		std::copy(old.begin(), old.end(), this->begin());
	}

	// Move Constructor
	MSArray(MSArray&& old)
	{
		mswap(*this, old);
	}

	// Copy Assignment Operator
	MSArray operator=(const MSArray& old)
	{
		std::copy(old.begin(), old.end(), this->begin());
	}

	// Move Assignment Operator
	MSArray operator=(MSArray&& old)
	{
		mswap(*this, old);
	}

	// Destructor
	~MSArray()
	{
		delete[] array_;
	}

	////////////////////////////////////
	// Parameter Passing Constructors //
	////////////////////////////////////

	// single-parameter constructor - sets desired array size
	// Pre : size >= 0
	MSArray(size_t size)
	{
		T* temp[size];
		array_ = temp;
	}

	// two-parameter constructor - sets desired array size and an item to fill it with
	// Pre : size >= 0
	MSArray(size_t size, T item)
	{
		T* temp[size] = { item };
		array_ = temp;
	}

	///////////////////////////////
	// Member Operator Overloads //
	///////////////////////////////

	// bracket operator - returns the element stored at the given index
	// Pre : index < this->size()
	T& operator[](size_t index)
	{
		return &array_[index];
	}

	// const bracket operator - returns the element stored at the given index, but not modifyable
	// Pre : index < this->size()
	const T& operator[](size_t index) const
	{
		return &array_[index];
	}

	/////////////////////////////
	// Public Member Functions //
	/////////////////////////////

	// size function - returns the number of elements in the array
	// Pre : none
	size_t size()
	{
		return size_;
	}

	// begin iterator - returns a pointer to the first element in the array
	// Pre : none
	T* begin()
	{

	}

	// const begin iterator - returns a const pointer to the first element in the array
	// Pre : none
	const T* begin() const
	{

	}

	// end iterator - returns a pointer to just past the end of the array
	// Pre : none
	T* end()
	{

	}
	
	// const end iterator - returns a const pointer to just past the end of the array
	// Pre : none
	const T* end() const
	{

	}

	// define some types that really don't make anything any less opaque
	typedef size_t size_type;
	using value_type = T;

private:

	//////////////////////////////
	// Private Member Functions //
	//////////////////////////////

	// just makes std::swap a little more convenient
	// Pre : none
	void mswap(MSArray& other)
	{
		std::swap(this->array_, other.array_);
	}

	//////////////////////////////
	// Private Member Variables //
	//////////////////////////////

	//The actual array
	T* array_;

	// keeps track of the size
	size_t size_;
};

///////////////////////////////
// Global Operator Overloads //
///////////////////////////////

// Equality comparison operator - returns true if every element is identical, false otherwise
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator==(const MSArray<T>& left, const MSArray<T>& right)
{

}

// Inequality comparison operator - returns false if every element is identical, true otherwise
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator!=(const MSArray<T>& left, const MSArray<T>& right)
{

}

// Strictly less than comparison operator - returns true if the left array has values that are smaller, lexicographically
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator<(const MSArray<T>& left, const MSArray<T>& right)
{

}

// Less than or equal to comparison operator - returns true if the left array has values that are smaller, lexicographically, or equal
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator<=(const MSArray<T>& left, const MSArray<T>& right)
{

}

// Strictly greater than comparison operator - returns true if the left array has values that are greater, lexicographically
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator>(const MSArray<T>& left, const MSArray<T>& right)
{

}

// Greater than or equal to comparison operator - returns true if the left array has values that are greater, lexicographically, or equal
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator>=(const MSArray<T>& left, const MSArray<T>& right)
{

}

#endif // MSARRAY_H
