// Luke Underwood
// 9/23/2020
// Project_H
// Graph.h
// Header for Graph class
// a data structure designed to handle graph-theoretical problems

#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include<utility>

#include"GNode.h"

//ADD COMMENTS
template <typename label, typename data>
class Graph
{
public:

    Graph();

private:

    std::vector<GNode<label, data>> nodes_;

};

#endif // GRAPH_H