// Luke Underwood
// 11/19/2020
// Project_H
// main.cpp
// source file containing function main to test prim's algorithm

// standard library inclusions
#include <iostream>

// file inclusions
#include "prim.h"
#include "fibheap.h"
#include "fibnode.h"

int main()
{
    FibHeap<long, long> heap;

    for(int i = 0; i < 10000; ++i)
    {
        heap.insert(10000-i, i);
    }

    for(int i = 0; i < 10000; i++)
    {
        if(i%10 == 0)
        {
            std::cout << heap.getMin()->getKey() << " " << heap.getMin()->getValue() << std::endl;
        }
        heap.deleteMin();
    }

    return 0;
}