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
    // test graph
    auto output = prim( std::vector<std::vector<int>>
                        ({
                            std::vector<int>({-1,  3, -1,  7,  4}),
                            std::vector<int>({ 3, -1,  2, -1,  5}),
                            std::vector<int>({-1,  2, -1,  6,  8}),
                            std::vector<int>({ 7, -1,  6, -1,  1}),
                            std::vector<int>({ 4,  5,  8,  1, -1})
                        }),
                        std::vector<std::vector<int>>
                        ({
                            std::vector<int>({1, 3, 4}),
                            std::vector<int>({0, 2, 4}),
                            std::vector<int>({1, 3, 4}),
                            std::vector<int>({0, 2, 4}),
                            std::vector<int>({0, 1, 2, 3})
                        }), 0);

    for(auto n : output)
    {
        std::cout << n.first << " " << n.second << std::endl;
    }

    return 0;
}