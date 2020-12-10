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
    // large test graph, manually assigned so I can check output
    auto output = prim( std::vector<std::vector<int>>
                        ({
                            std::vector<int>({-1, 10, -1, -1, -1, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({10, -1,  3, -1, -1, -1, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1,  3, -1,  9, -1, -1, -1, 27, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1,  9, -1,  5, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1,  5, -1, -1, -1, -1, -1, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({18, -1, -1, -1, -1, -1, 26, -1, -1, -1, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, 15, -1, -1, -1, 26, -1, -1, -1, -1, -1, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, 27, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, 19, -1, -1, -1, -1, -1, 32, -1, -1,  7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, 20, -1, -1, -1, 32, -1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, 11, -1, -1, -1, -1, -1,  4, -1, -1, -1, 30, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  4, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, 25, 35,  7, -1, -1, 16, -1, 36, -1, -1,  6, 34, 24, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 36, -1, 21, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, 14, -1, -1, -1, 21, -1, -1, -1, -1, -1, 17, -1, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 30, -1, -1, -1, -1, -1, 28, -1, -1, -1, 12, -1, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  6, -1, -1, 28, -1, -1, -1, -1, -1, 23, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 34, -1, -1, -1, -1, -1, -1, -1, -1, -1, 33, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, 31, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 17, -1, -1, -1,  2, -1, -1, -1, -1, -1,  8}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, -1, -1, 29, -1, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 23, -1, -1, -1, 29, -1, 13, -1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 33, -1, -1, -1, 13, -1,  1, -1}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 31, -1, -1, -1,  1, -1, 22}),
                            std::vector<int>({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  8, -1, -1, -1, 22, -1}),
                        }),
                        std::vector<std::vector<int>>
                        ({
                            std::vector<int>({1, 5}),
                            std::vector<int>({0, 2, 6}),
                            std::vector<int>({1, 3, 7}),
                            std::vector<int>({2, 4, 8}),
                            std::vector<int>({3, 9}),
                            std::vector<int>({0, 6, 10}),
                            std::vector<int>({1, 5, 12}),
                            std::vector<int>({2, 12}),
                            std::vector<int>({3, 9, 12}),
                            std::vector<int>({4, 8, 14}),
                            std::vector<int>({5, 11, 15}),
                            std::vector<int>({10, 12}),
                            std::vector<int>({6, 7, 8, 11, 13, 16, 17, 18}),
                            std::vector<int>({12, 14}),
                            std::vector<int>({9, 13, 19}),
                            std::vector<int>({10, 16, 20}),
                            std::vector<int>({12, 15, 21}),
                            std::vector<int>({12, 22}),
                            std::vector<int>({12, 19, 23}),
                            std::vector<int>({14, 18, 24}),
                            std::vector<int>({15, 21}),
                            std::vector<int>({16, 20, 22}),
                            std::vector<int>({17, 21, 23}),
                            std::vector<int>({18, 22, 24}),
                            std::vector<int>({19, 23})
                        }), 12);

    for(auto n : output)
    {
        std::cout << n.first << " " << n.second << std::endl;
    }
    std::cout << std::endl;

    // two-node test graph
    output = prim( std::vector<std::vector<int>>
                        ({
                            std::vector<int>({-1, 10}),
                            std::vector<int>({10, -1}),
                        }),
                        std::vector<std::vector<int>>
                        ({
                            std::vector<int>({1}),
                            std::vector<int>({0}),
                        }), 0);

    for(auto n : output)
    {
        std::cout << n.first << " " << n.second << std::endl;
    }
    std::cout << std::endl;

    // single-node test graph
    output = prim( std::vector<std::vector<int>>
                        ({
                            std::vector<int>({-1})
                        }),
                        std::vector<std::vector<int>>
                        ({
                            std::vector<int>(),
                        }), 0);

    for(auto n : output)
    {
        std::cout << n.first << " " << n.second << std::endl;
    }
    std::cout << std::endl;

    // setup for a 100-node fully-connected graph, weights are arbitrary
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> list;
    for(int i = 0; i < 10; ++i)
    {
        std::vector<int> mrow;
        std::vector<int> lrow;
        for(int j = 0; j < 10; ++j)
        {
            if(i == j) 
            {
                mrow.push_back(INF);
            }
            else
            {
                mrow.push_back(i+j+1);
                lrow.push_back(j);
            }
        }
        matrix.push_back(mrow);
        list.push_back(lrow);
    }
    // test 100-node fully-connected graph
    output = prim(matrix, list, 0);

    for(auto n : output)
    {
        std::cout << n.first << " " << n.second << std::endl;
    }
    std::cout << std::endl;

    return 0;
}