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

    heap.insert(3, 3);
    heap.insert(4, 5);
    heap.insert(5, 8);

    
    std::cout << heap.findMin()->getKey() << " " << heap.findMin()->getValue() << std::endl;

    heap.insert(0, 1);
    heap.insert(1, 1);
    heap.insert(2, 2);

    std::cout << heap.findMin()->getKey() << " " << heap.findMin()->getValue() << std::endl;

    FibHeap<int, int> heap2;

    heap2.insert(6, 13);
    heap2.insert(-1, 1);

    heap.merge(heap2);
    
    std::cout << heap.findMin()->getKey() << " " << heap.findMin()->getValue() << std::endl;


    return 0;
}