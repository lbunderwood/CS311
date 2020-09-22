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


void didItThrow(const function<void()> & ff,
                bool & threw)
{
    try
    {
        ff();
    }
    catch(...)
    {
        threw = true;
        throw;
    }
    threw = false;
}


int gcd(int a,
        int b)
{
    if(a == 0)
    {
        return b;
    }
    else if (a > b)
    {
        return gcd(b, a);
    }
    else
    {
        return gcd(b%a, a);
    }
}

