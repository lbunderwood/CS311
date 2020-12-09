// Luke Underwood
// 12/8/2020
// Project_H
// prim.h
// Source file for implementing Prim's algorithm using FibHeap

// Header file inclusions
#include "prim.h"
#include "fibheap.h"
#include "fibnode.h"

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
    // holds the number of nodes
    int N = adjMtrx.size();

    // int is weight, Edge contains endpoints of edge
    // holds prospective edges that may be added to spanTree
    FibHeap<int, Edge> edges;

    // this will be the vector<Edge> that is returned,
    // representing the min-weight spanning tree
    std::vector<Edge> spanTree;

    // this keeps track of which nodes are connected to the spanning tree
    std::vector<int> reachable(N, 0);
    reachable[startVtx] = 1;

    // node most recently added to the spanning tree
    int current = startVtx;

    // number of nodes added to the spanning tree
    int treeSize = 1;

    // when the number of edges in the tree is equal to the number
    // of nodes - 1, we are done
    while(spanTree.size() < N - 1)
    {
        // add edges to nodes adjacent to the one most recently added
        for(auto n : adjList[current])
        {
            // only add it if they are connected in the graph and it is not already a part of the tree
            if(reachable[n] == 0)
            {
                // add its weight from the adjMtrx and the endpoints to represent the edge
                edges.insert(adjMtrx[current][n], {current, n});
            }
        }

        // loop until something has been added to the tree
        while(true)
        {
            // get the edge and the potentially unreachable node
            Edge minEdge = edges.getMin()->getValue();
            int farNode = minEdge.second;

            // at this point, we have all the information we need,
            // so its time to delete the edge
            edges.deleteMin();

            // check that it hasn't been added a different way
            if(!reachable[farNode])
            {
                // add it to the tree
                reachable[farNode] = 1;
                spanTree.push_back(minEdge);

                // make it the next node to add edges from
                current = farNode;

                // update the count of nodes in the tree
                ++treeSize;

                // leave the loop
                break;
            }
        }
    }

    // return the min-weight spanning tree
    return spanTree;
}