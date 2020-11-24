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
    FibHeap<int, int> heap;

    heap.insert(2, 2);
    heap.insert(3, 3);
    heap.insert(0, 0);
    heap.insert(1, 1);

    for(int i = 0; i < 2; ++i)
    {
        std::cout << heap.getMin()->getKey() << " " << heap.getMin()->getValue() << std::endl;
        heap.deleteMin();
    }

    heap.insert(11, 11);
    heap.insert(6, 6);
    heap.insert(8, 8);
    heap.insert(9, 9);
    heap.insert(5, 5);
    heap.insert(10, 10);
    heap.insert(7, 7);
    heap.insert(4, 4);

    for(int i = 0; i < 6; ++i)
    {
        std::cout << heap.getMin()->getKey() << " " << heap.getMin()->getValue() << std::endl;
        heap.deleteMin();
    }

    return 0;
}