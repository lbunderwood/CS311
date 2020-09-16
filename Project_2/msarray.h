// Luke Underwood
// 9/13/2020
// CS311 - Data Structures and Algorithms
// msarray.h
// Header and implementation for template class MSArray

#ifndef MSARRAY_H
#define MSARRAY_H

#include<utility>
#include<algorithm>

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
		: MSArray(8) {}

	////////////////////////////////////////////////
	// Big Five Constructors - defined explicitly //
	////////////////////////////////////////////////

	// Copy Constructor
	MSArray(const MSArray& old) : MSArray(old.size())
	{
		std::copy(old.begin(), old.end(), this->begin());
	}

	// Move Constructor
	MSArray(MSArray&& old) noexcept : array_(old.array_), size_(old.size())
	{
		old.array_ = nullptr;
		old.size_ = 0;
	}

	// Copy Assignment Operator
	MSArray& operator=(const MSArray& old)
	{
		MSArray copy(old);
		mswap(copy);
		return *this;
	}

	// Move Assignment Operator
	MSArray& operator=(MSArray&& old) noexcept
	{
		mswap(old);
		return *this;
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
		: size_(size), array_(new T[size]) {}

	// two-parameter constructor - sets desired array size and an item to fill it with
	// Pre : size >= 0
	MSArray(size_t size, T item) : MSArray(size)
	{
		for (auto& m : *this)
		{
			m = item;
		}
	}

	///////////////////////////////
	// Member Operator Overloads //
	///////////////////////////////

	// bracket operator - returns the element stored at the given index
	// Pre : index < this->size()
	T& operator[](size_t index)
	{
		return array_[index];
	}

	// const bracket operator - returns the element stored at the given index, but not modifyable
	// Pre : index < this->size()
	const T& operator[](size_t index) const
	{
		return array_[index];
	}

	/////////////////////////////
	// Public Member Functions //
	/////////////////////////////

	// size function - returns the number of elements in the array
	// Pre : none
	size_t size() const
	{
		return size_;
	}

	// begin iterator - returns a pointer to the first element in the array
	// Pre : none
	T* begin()
	{
		return array_;
	}

	// const begin iterator - returns a const pointer to the first element in the array
	// Pre : none
	const T* begin() const
	{
		return array_;
	}

	// end iterator - returns a pointer to just past the end of the array
	// Pre : none
	T* end()
	{
		return begin() + size();
	}
	
	// const end iterator - returns a const pointer to just past the end of the array
	// Pre : none
	const T* end() const
	{
		return begin() + size();
	}

	// define some types that really don't make anything any less opaque
	using size_type = size_t;
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
		std::swap(this->size_, other.size_);
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
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

// Inequality comparison operator - returns false if every element is identical, true otherwise
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator!=(const MSArray<T>& left, const MSArray<T>& right)
{
	return !(left == right);
}

// Strictly less than comparison operator - returns true if the left array has values that are smaller, lexicographically
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator<(const MSArray<T>& left, const MSArray<T>& right)
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

// Less than or equal to comparison operator - returns true if the left array has values that are smaller, lexicographically, or equal
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator<=(const MSArray<T>& left, const MSArray<T>& right)
{
	return !(right < left);
}

// Strictly greater than comparison operator - returns true if the left array has values that are greater, lexicographically
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator>(const MSArray<T>& left, const MSArray<T>& right)
{
	return right < left;
}

// Greater than or equal to comparison operator - returns true if the left array has values that are greater, lexicographically, or equal
// Pre : none
// Template Type Restrictions : 
template <typename T>
bool operator>=(const MSArray<T>& left, const MSArray<T>& right)
{
	return !(left < right);
}

#endif // MSARRAY_H
