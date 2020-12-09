// Luke Underwood
// 11/19/2020
// Project_H
// main.cpp
// source file containing function main to test prim's algorithm

// standard library inclusions
#include <iostream>
#include <cstdlib>

// file inclusions
#include "prim.h"
#include "fibheap.h"
#include "fibnode.h"

int main()
{
    // Dummy 5-node fully connected graph
    auto output = prim(std::vector<std::vector<int>>(5, std::vector<int>(5, 1)), 
                       std::vector<std::vector<int>>(5, std::vector<int>({0, 1, 2, 3, 4})), 
                       0);

    for(auto n : output)
    {
        std::cout << n.first << " " << n.second << std::endl;
    }

    return 0;
}