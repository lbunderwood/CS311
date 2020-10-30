// Luke Underwood
// 10/28/2020
// CS311
// Project_5
// TFS_Array
// tfsarray.h
// header file for templated frighteningly smart array (tfsarray)

#ifndef TFSARRAY_H
#define TFSARRAY_H

// fsarray.h  INCOMPLETE
// VERSION 5
// Glenn G. Chappell
// Started: 2020-10-14
// Updated: 2020-10-21
//
// For CS 311 Fall 2020
// Header for class FSArray
// Frightfully smart array of int
// Preliminary to Project 5

// History:
// - v1:
//   - Skeleton only: header & source files, #ifndef, #include, empty
//     class definition.
// - v2:
//   - Add member types value_type, size_type, iterator, const_iterator.
//   - Add dummy versions (at least) of all member functions, including
//     dummy return statements for non-void functions. Package compiles.
//   - Add data members.
//   - Add class invariants.
//   - Write (untested versions of) the following member functions:
//     default ctor, ctor from size (these two are single func), dctor,
//     op[], size, empty, begin, end, push_back, pop_back.
// - v3:
//   - Document exception-safety guarantees for most functions.
//   - Write copy ctor.
// - v4:
//   - Revise class invariants to allow for _data being nullptr if _size
//     is zero.
//   - Write move ctor.
//   - Mark various functions as noexcept.
//   - Put definitions of copy & move functions, resize, insert, erase,
//     swap in source file.
// - v5:
//   - Add _capacity data member.
//   - Add constant DEFAULT_CAP and use it in setting the capacity in
//     default ctor/ctor from size.


#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max


// *********************************************************************
// class TFSArray - Class definition
// *********************************************************************


// class TFSArray
// Frightfully Smart Array of int.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.
// Type Restrictions : T, or value_type, must have a default constructor
template <typename T>
class TFSArray {

// ***** TFSArray: types *****
public:

    // value_type: type of data items
    using value_type = T;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** TFSArray: internal-use constants *****
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };

// ***** TFSArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit TFSArray(size_type size=0)
        :_capacity(std::max(size, size_type(DEFAULT_CAP))),
            // _capacity must be declared before _data
         _size(size),
         _data(_capacity == 0 ? nullptr : new value_type[_capacity])
    {}

    // Copy ctor
    // Strong Guarantee
    TFSArray(const TFSArray & other)
    :_capacity(other._capacity),
     _size(other.size()),
     _data(other._capacity == 0 ? nullptr
                                : new value_type[other._capacity])
    {
        std::copy(other.begin(), other.end(), begin());
    }

    // Move ctor
    // No-Throw Guarantee
    TFSArray(TFSArray && other) noexcept
    :_capacity(other._capacity),
     _size(other._size),
     _data(other._data)
    {
        other._capacity = 0;
        other._size = 0;
        other._data = nullptr;
    }

    // Copy assignment
    // Strong Guarantee
    TFSArray & operator=(const TFSArray & other)
    {
        TFSArray<value_type> copy(other);
        swap(copy);
        return *this;
    }

    // Move assignment
    // No-Throw Guarantee
    TFSArray & operator=(TFSArray && other) noexcept
    {
        swap(other);
        return *this;
    }

    // Dctor
    // No-Throw Guarantee
    ~TFSArray()
    {
        delete [] _data;
    }

// ***** TFSArray: general public operators *****
public:

    // operator[] - non-const & const
    // Pre:
    //     0 <= index < size()
    // No-Throw Guarantee
    value_type & operator[](size_type index) noexcept
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const noexcept
    {
        return _data[index];
    }

// ***** TFSArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // strong Guarantee
    void resize(size_type newsize)
    {
        // if the current array is too small, reallocate and copy
        if(newsize > _capacity)
        {
            // Create new array with the appropriate size
            TFSArray<value_type> newArray(std::max(_capacity*2, newsize));
            // copy the data
            std::copy(begin(), end(), newArray.begin());
            // commit our changes, to meet strong guaruntee
            swap(newArray);
        }
        
        // the array will be big enough at this point, so assign _size
        // in case the size is set to twice the old capacity instead of newsize
        _size = newsize;
    }

    // insert
    // basic Guarantee - 
    // chose not to write it with strong guaruntee because it is much less efficient
    iterator insert(iterator pos,
                    const value_type & item)
    {
        // The size must be increased by 1
        resize(size() + 1);

        // Shift all of our data down by 1
        // std::move_backward(pos, end() - 1, end());
        for(iterator i = end() - 1; i > pos; --i)
        {
            *i = *(i - 1);
        }

        //insert the item
        *pos = item;
        return pos;
    }

    // erase
    // strong Guarantee
    iterator erase(iterator pos)
    {
        // shift all data back one to overwrite *pos
        std::move(pos + 1, end(), pos);

        // decrease the size by 1
        resize(size() - 1);
        return pos;
    }

    // push_back
    // basic Guarantee
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }

    // pop_back
    // basic Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(TFSArray & other) noexcept
    {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }

// ***** TFSArray: data members *****
private:

    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class TFSArray


#endif // #ifndef TFSARRAY