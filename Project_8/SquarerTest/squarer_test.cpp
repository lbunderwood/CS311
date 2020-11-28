// squarer_test.cpp  !SKELETON
// Glenn G. Chappell
// 2020-11-20
//
// For CS 311 Fall 2020
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

///////////////////////////////////////////////////
// Modified by Luke Underwood - 11/27/2020
// Wrote all test cases

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <cmath>
using std::pow;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
    "class Squarer"
    " - CS 311 Proj 8, Ex B";


// *********************************************************************
// Test Cases
// *********************************************************************



// This test case handles non-const int testing of Squarer.
// The values 0, 1, and -1 will be tested, 
//  along with a variety of larger values, both negative and positive.
TEST_CASE("Squaring Integers")
{
    // Checks that Squarer works for 0, 1, and -1
    SUBCASE("Special Interest Cases")
    {
        Squarer sq;

        INFO("Square of -1");
        REQUIRE(sq(-1) == 1);

        INFO("Square of 0");
        REQUIRE(sq(0) == 0);

        INFO("Square of 1");
        REQUIRE(sq(1) == 1);
    }

    // Checks that Squarer works for 10000 and -10000
    SUBCASE("Very Large Values")
    {
        Squarer sq;

        INFO("Square of 10000");
        REQUIRE(sq(10000) == 100000000);
        
        INFO("Square of -10000");
        REQUIRE(sq(-10000) == 100000000);
    }

    // Checks that Squarer works for every third value between 100 and 200
    // as well as -100 to -200
    SUBCASE("Variety of Random Values")
    {
        Squarer sq;

        for(int i = 100; i <= 200; i += 3)
        {
            INFO("Square of "+std::to_string(i));
            REQUIRE(sq(i) == pow(i, 2));

            INFO("Square of -"+std::to_string(i));
            REQUIRE(sq(i*-1) == pow(i, 2));
        }
    }
}



// This test case handles non-const double testing of Squarer.
// The values 0, 1, and -1 will be tested, along with a number of non-integer values,
//  and a variety of larger values, both negative and positive.
TEST_CASE("Squaring Doubles")
{
    // Checks that Squarer works for 0, 0.000001, 1, -0.000001, and -1
    SUBCASE("Special Interest Cases")
    {
        Squarer sq;

        INFO("Square of -1");
        REQUIRE(sq(-1.0) == 1.0);

        INFO("Square of -0.000001");
        REQUIRE(sq(-0.000001) == pow(-0.000001, 2));

        INFO("Square of 0");
        REQUIRE(sq(0.0) == 0.0);

        INFO("Square of 0.000001");
        REQUIRE(sq(0.000001) == pow(0.000001, 2));

        INFO("Square of 1");
        REQUIRE(sq(1.0) == 1.0);
    }

    // Checks that Squarer works for 10000.5 and -10000.5
    SUBCASE("Very Large Values")
    {
        Squarer sq;

        INFO("Square of 10000.5");
        REQUIRE(sq(10000.5) == pow(10000.5, 2));
        
        INFO("Square of -10000.5");
        REQUIRE(sq(-10000.5) == pow(10000.5, 2));  
    }

    // Checks that Squarer works for multiples of 0.3 + 100 from 100 to 130,
    // as well as -100 to -130
    SUBCASE("Variety of Random Values")
    {
        Squarer sq;

        for(double i = 100; i <= 130; i += 0.3)
        {
            INFO("Square of "+std::to_string(i));
            REQUIRE(sq(i) == pow(i, 2));

            INFO("Square of -"+std::to_string(i));
            REQUIRE(sq(i*-1) == pow(i, 2));
        }
    }
}



// This test case handles const int and double testing of Squarer.
// Only a few values of each will be tested, since a broader variety
//  were tested in the previous two cases.
TEST_CASE("Const Squarer Objects")
{
    // Checks that Squarer works for const ints
    SUBCASE("Const Ints")
    {
        Squarer sq;
        const int zero = 0;
        const int one = 1;
        const int none = -1;
        const int ten = 10;
        const int nten = -10;
        const int tenk = 10000;
        const int ntenk = -10000;

        INFO("Square of -10000");
        REQUIRE(sq(ntenk) == pow(-10000, 2));

        INFO("Square of -10");
        REQUIRE(sq(nten) == 100);

        INFO("Square of -1");
        REQUIRE(sq(none) == 1);

        INFO("Square of 0");
        REQUIRE(sq(zero) == 0);

        INFO("Square of 1");
        REQUIRE(sq(one) == 1);

        INFO("Square of 10");
        REQUIRE(sq(ten) == 100);

        INFO("Square of 10000");
        REQUIRE(sq(tenk) == pow(10000, 2));
    }

    // Checks that Squarer works for const doubles
    SUBCASE("Const Doubles")
    {
        Squarer sq;
        const double zero = 0;
        const double one = 1;
        const double none = -1;
        const double small = 0.00001;
        const double nsmall = -0.00001;
        const double tenk = 10000;
        const double ntenk = -10000;

        INFO("Square of -10000");
        REQUIRE(sq(ntenk) == pow(-10000, 2));

        INFO("Square of -1");
        REQUIRE(sq(none) == 1);

        INFO("Square of -0.00001");
        REQUIRE(sq(nsmall) == pow(-0.00001, 2));

        INFO("Square of 0");
        REQUIRE(sq(zero) == 0);

        INFO("Square of 0.00001");
        REQUIRE(sq(small) == pow(0.00001, 2));

        INFO("Square of 1");
        REQUIRE(sq(one) == 1);

        INFO("Square of 10000");
        REQUIRE(sq(tenk) == pow(10000, 2));
    }
}



// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

