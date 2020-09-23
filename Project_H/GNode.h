// Luke Underwood
// 9/23/2020
// Project_H
// GNode.h
// Header for Gnode class
// a node class used in Graph

#ifndef GNODE_H
#define GNODE_H

#include<vector>
#include<utility>

//ADD COMMENTS HERE
template <typename label, typename data>
class GNode
{
public:

    GNode();

private:

    label name_;
    data info_;
    
    int color_;

    std::vector<std::pair<GNode<label, data>*, double>> edges_;

};

#endif // GNODE_H