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
    std::vector<Edge> spanTree(N);

    // this keeps track of which nodes are connected to the spanning tree
    std::vector<int> reachable(N, 0);

    // node most recently added to the spanning tree
    int current = startVtx;

    // when the number of edges in the tree is equal to the number
    // of nodes - 1, we are done
    while(spanTree.size() < N - 1)
    {
        // add edges to nodes adjacent to the one most recently added
        for(int i = 0; i < N; ++i)
        {
            // only add it if they are connected in the graph and it is not already a part of the tree
            if(adjMtrx[current][i] != INF && reachable[i] == 0)
            {
                // add its weight from the adjMtrx and the endpoints to represent the edge
                edges.insert(adjMtrx[current][i], {current, i});
            }
        }

        // using this bool seems like poor style, but its the best I could think of
        bool nothingAdded = true;

        // loop until something has been added to the tree
        while(nothingAdded)
        {
            // get the edge and the potentially unreachable node
            Edge minEdge = edges.getMin()->getValue();
            int farNode = minEdge.second;

            // check that it hasn't been added a different way
            if(!reachable[farNode])
            {
                // add it to the tree
                reachable[farNode] = 1;
                spanTree[farNode] = minEdge;

                // make it the next node to add edges from
                current = farNode;

                // leave the loop after this iteration
                nothingAdded = false;
            }
            
            // at this point, both nodes are definitely in the tree
            // so it's time to delete the edge
            edges.deleteMin();
        }
    }

    // return the min-weight spanning tree
    return spanTree;
}