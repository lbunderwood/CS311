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

    // check for end of list
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


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);


template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
    return false;  // Dummy return
    // TODO: Write this!!!
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

