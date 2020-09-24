// dp3.h  SKELETON
// Glenn G. Chappell
// 2020-09-17
//
// For CS 311 Fall 2020
// Header for Project 3 functions

/////////////////////////////////////

// Edited and completed by Luke Underwood
// 9/21/2020

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function


// lookup function for LLNode
// THIS FUNCTION MAY THROW (see preconditions)
// takes head pointer for an LLNode, and an index
// returns the term at the given index
// Pre : list must not be empty (head != nullptr)
//       0 <= index < size of list
//       std::out_of_range will be thrown otherwise
// type restrictions : none (other than those required by LLNode)
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    // check for negative input
    if(index < 0)
    {
        throw std::out_of_range("lookup was called with bad parameters.\n"
            "The specified index must not be negative.");
    }

    // check for empty list
    if(head == nullptr)
    {
        throw std::out_of_range("lookup was called with bad parameters.\n"
            "The given LLNode was empty.");
    }

    // advance list until desired index is reached
    for(size_t i = 0; i < index; ++i)
    {
        // advance
        head = head->_next;

        // check for end of list
        if(head == nullptr)
        {
            throw std::out_of_range("lookup was called with bad parameters.\n"
                "The specified index does not exist in the given LLNode.");
        }
    }

    // return data from that index
    return head->_data;
}


// didItThrow function for error handling
// takes function pointer and bool
// returns bool by parameter reference
// returns true and re-throws exception if the given function throws an exception
// returns false otherwise
// Pre : function pointer must not take parameters and have return type void
void didItThrow(const std::function<void()> & ff,
                bool & threw);


// checkSorted function for arrays
// takes two iterators
// returns bool by value
// returns true if the array is in ascending order
// returns false otherwise
// Pre : first < last
//       first and last must be forward iterators specifying a continuous range
// type restrictions : items in array must be comparable by <
template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
    // create "next" iterator to compare with the current value
    auto next = first;
    ++next;

    // first != last checks for empty arrays
    // next != last checks for end of array
    while(first != last && next != last)
    {
        // if something is out of order, return false
        if(*next < *first)
        {
            return false;
        }

        // iterate to check next term
        ++first;
        ++next;
    }

    // if we made it this far, the range is sorted
    return true;
}


// gcd function to find greatest common denominator
// takes two integers
// returns gcd of parameters by value
// Pre : a != 0 || b != 0 (a and b cannot both be 0)
//       a >= 0 && b >= 0 (a and b must both be positive)
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED