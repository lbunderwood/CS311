// Luke Underwood
// 12/8/2020
// Project_H
// prim.h
// Source file for implementing Prim's algorithm using FibHeap

// Header file inclusions
#include "prim.h"
#include "fibheap.h"

// Standard Libary Inclusions
#include <vector>
    // For std::vector
#include <utility>
    // For std::pair

// ADD COMMENTS HERE
std::vector<Edge> prim(const std::vector<std::vector<int>>& adjMtrx,
                       const std::vector<std::vector<int>>& adjList,
                       int startVtx)
{
    // Initialize some data structures
    FibHeap<int, Edge> edges;   // int is weight, Edge contains endpoints of edge
    std::vector<Edge> spanTree; // this will be the vector<Edge> that is returned

    // when the number of edges in the tree is equal to the number
    // of nodes - 1, we are done
    while(spanTree.size() == adjMtrx.size() - 1)
    {
        spanTree.push_back({startVtx, startVtx + 1}); // DUMMY CODE
    }

    return spanTree;
}