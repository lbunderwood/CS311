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
// Invariants : size_ >= 0
// Template Type Restrictions : T must have a default constructor
template <typename T>
class MSArray
{
public:

	// define some types to help keep things straight
	using size_type = std::size_t;
	using value_type = T;

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
	MSArray(size_type size)
		: size_(size), array_(new value_type[size]) {}

	// two-parameter constructor - sets desired array size and an item to fill it with
	// Pre : size >= 0, item must be of the same type as given in the <> operators (MSArray<int> arr(1, "hello") is not allowed)
	MSArray(size_type size, value_type item)
		: MSArray(size)
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
	// Pre : 0 <= index < this->size() - 1
	value_type& operator[](size_type index)
	{
		return array_[index];
	}

	// const bracket operator - returns the element stored at the given index, but not modifyable
	// Pre : 0 <= index < this->size() - 1
	const value_type& operator[](size_type index) const
	{
		return array_[index];
	}

	/////////////////////////////
	// Public Member Functions //
	/////////////////////////////

	// size function - returns the number of elements in the array
	// Pre : none
	size_type size() const
	{
		return size_;
	}

	// begin iterator - returns a pointer to the first element in the array
	// Pre : none
	value_type* begin()
	{
		return array_;
	}

	// const begin iterator - returns a const pointer to the first element in the array
	// Pre : none
	const value_type* begin() const
	{
		return array_;
	}

	// end iterator - returns a pointer to just past the end of the array
	// Pre : none
	value_type* end()
	{
		return begin() + size();
	}
	
	// const end iterator - returns a const pointer to just past the end of the array
	// Pre : none
	const value_type* end() const
	{
		return begin() + size();
	}

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

	// The actual array
	value_type* array_;

	// keeps track of the size
	size_type size_;
};

///////////////////////////////
// Global Operator Overloads //
///////////////////////////////

// Equality comparison operator - returns true if every element is identical, false otherwise
// Pre : none
// Template Type Restrictions : T must have == operator
template <typename T>
bool operator==(const MSArray<T>& left, const MSArray<T>& right)
{
	return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

// Inequality comparison operator - returns false if every element is identical, true otherwise
// Pre : none
// Template Type Restrictions : T must have == operator
template <typename T>
bool operator!=(const MSArray<T>& left, const MSArray<T>& right)
{
	return !(left == right);
}

// Strictly less than comparison operator - returns true if the left array has values that are smaller, lexicographically
// Pre : none
// Template Type Restrictions : T must have < operator
template <typename T>
bool operator<(const MSArray<T>& left, const MSArray<T>& right)
{
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

// Less than or equal to comparison operator - returns true if the left array has values that are smaller, lexicographically, or equal
// Pre : none
// Template Type Restrictions : T must have < operator
template <typename T>
bool operator<=(const MSArray<T>& left, const MSArray<T>& right)
{
	return !(right < left);
}

// Strictly greater than comparison operator - returns true if the left array has values that are greater, lexicographically
// Pre : none
// Template Type Restrictions : T must have < operator
template <typename T>
bool operator>(const MSArray<T>& left, const MSArray<T>& right)
{
	return right < left;
}

// Greater than or equal to comparison operator - returns true if the left array has values that are greater, lexicographically, or equal
// Pre : none
// Template Type Restrictions : T must have < operator
template <typename T>
bool operator>=(const MSArray<T>& left, const MSArray<T>& right)
{
	return !(left < right);
}

#endif // MSARRAY_H
