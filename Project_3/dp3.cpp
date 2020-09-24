// dp3.cpp  SKELETON
// Glenn G. Chappell
// 2020-09-17
//
// For CS 311 Fall 2020
// Source for Project 3 functions

/////////////////////////////////////

// Edited and completed by Luke Underwood
// 9/21/2020

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;


// didItThrow function for error handling
// THIS FUNCTION MAY THROW (keep reading for details)
// takes function pointer and bool
// returns bool by parameter reference
// returns true and re-throws exception if the given function throws an exception
// returns false otherwise
// Pre : function pointed to must not take parameters
//       function pointed to must have return type void
void didItThrow(const function<void()> & ff,
                bool & threw)
{
    try 
    {
        ff();       // call the function
    }
    catch(...)      // if any exception was thrown...
    {
        threw = true;
        throw;      // re-throws the caught exception
    }
    threw = false;  // this is set if nothing is caught
}


// gcd function to find greatest common denominator
// takes two integers
// returns gcd of parameters by value
// Pre : a != 0 || b != 0 (a and b cannot both be 0)
//       a >= 0 && b >= 0 (a and b must both be positive)
int gcd(int a,
        int b)
{
    // BASE CASE
    if(a == 0)
    {
        return b;
    }

    // RECURSIVE CASES

    // Appropriate ordering of a, b is neccessary for everything to work
    else if (a > b)
    {
        return gcd(b, a);
    }

    // Reduce the size of the problem
    else
    {
        return gcd(b%a, a);
    }
}