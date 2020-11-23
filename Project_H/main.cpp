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
    heap.insert(0, 1);
    heap.insert(1, 1);

    for(int i = 0; i < 4; ++i)
    {
        std::cout << heap.getMin()->getKey() << " " << heap.getMin()->getValue() << std::endl;
        heap.deleteMin();
    }
/*
    heap.insert(4, 20);
    heap.insert(7, 31);
    heap.insert(18, 11);
    heap.insert(-5, 13);
    heap.insert(82, 24);
    heap.insert(13, 35);
    heap.insert(0, 6);
    heap.insert(3000, 17);

    for(int i = 0; i < 6; ++i)
    {
        std::cout << heap.getMin()->getKey() << " " << heap.getMin()->getValue() << std::endl;
        heap.deleteMin();
    }
*/
    return 0;
}