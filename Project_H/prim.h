// Luke Underwood
// 11/19/2020
// Project_H
// prim.h
// Header file for implementing Prim's algorithm using FibHeap

#ifndef PRIM_H
#define PRIM_H

// std lib inclusions
#include <utility>
    // For std::pair
#include <vector>
    // For std::vector


// define number to represent no connection in an adjacency matrix
const int INF = -1;

// for convenience in referring to edges
using Edge = std::pair<int, int>;

// ADD COMMENTS HERE
std::vector<Edge> prim(const std::vector<std::vector<int>>& adjMtrx,
                       const std::vector<std::vector<int>>& adjList,
                       int startVtx); 

#endif // #ifndef PRIM_H