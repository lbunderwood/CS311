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

// function prim
//
// provided with an adjacency matrix, adjacency list, and starting vertex,
// runs prim's algorithm on a graph and returns std::vector<Edge> that makes up
// the minimum weight spanning tree. Edge is defined above as std::pair<int, int>,
// where the integers are the vertices that the edge connects.
//
// Preconditions :
//      adjMtrx :
//          Must be a valid std::vector<std::vector<int>>
//          The inner vectors must all be of equal size, and the outer
//            vector must have the same size as all of the inner ones.
//          Each entry at given array position [x][y] must have a value corresponding
//            to the weight of the edge between vertices x and y
//          If x, y are not adjacent, then the value at [x][y] must be -1, which
//            is stored in global variable INF above for convenience.
//
//      adjList :
//          Must be a valid std::vector<std::vector<int>>
//          The outer vector must have size equal to that of adjMtrx, which is the number of vertices
//          Each inner vector [x] must contain a list of vertices adjacent to vertex x
//          
//      startVtx:
//          0 <= startVtx < the number of vertices
//
// Exception Guaruntee :
//      Strong Guraruntee - parameters are never modified
//
// See prim.cpp for function definition
std::vector<Edge> prim(const std::vector<std::vector<int>>& adjMtrx,
                       const std::vector<std::vector<int>>& adjList,
                       int startVtx); 

#endif // #ifndef PRIM_H