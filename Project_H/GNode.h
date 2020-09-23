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

    //////////////////////
    // Type Definitions //
    //////////////////////

    // define some container types to represent the edges of the graph
    // edge consists of pointer to adjacent node and weight of the edge
    using Edge = std::pair<GNode<label, data>*, double>
    using EdgeArray = std::vector<Edge> 

    //////////////////
    // Constructors //
    //////////////////

    // Default Constructor
    // This should never be called
    GNode();

    // Big Five, written automatically
    GNode(const GNode & old)            = default;
    GNode operator=(const GNode & old)  = default;
    GNode(GNode && old)                 = default;
    GNode operator=(GNode && old)       = default;
    ~GNode()                            = default;


    //// Actually useful constructors ////

    // Single-parameter constructor
    GNode(const label& name) 
        : name_(name) {};

    // Two-parameter constructor
    // Takes the name and information for the node
    GNode(const label& name, const data& info) 
        : name_(name), info_(info) {};

    // Two-parameter constructor
    // Takes the name and edges
    GNode(const label& name, const EdgeArray& edges) 
        : name_(name), edges_(edges) {};

    // Three-parameter constructor
    // Takes the name, information, and edges
    GNode(const label& name, const data& info, const EdgeArray& edges) 
        : name_(name), info_(info), edges_(edges) {};

    /////////////////////////////
    // Public Member Functions //
    /////////////////////////////


    // Getter Functions //

    // getname function
    // returns the name of the node
    label getName() const
    {
        return name_;
    }

    // getinfo function
    // returns the info associated with the node
    label getInfo() const
    {
        return info_;
    }

    // getcolor function
    // returns the "color" of the node
    int getColor() const
    {
        return color_;
    }

    // push_back function
    // adds an edge to edges_
    void push_back(const Edge& edge)
    {
        edges.push_back(edge);
    }

    ///////////////////////////////
    // Member Operator Overloads //
    ///////////////////////////////

    // Square Bracket Operator Overload
    // Returns indicated Edge from edges_
    Edge& operator[](size_t index)
    {
        return edges_[index];
    }
    // const version
    const Edge& operator[](size_t index) const
    {
        return edges_[index];
    }

    /////////////////////////////
    // Allow Graph to access data members directly for convenience
    friend class Graph<label, data>;

private:

    // stores the name of the node
    // this is templated so that they can be named numerically, with char, string, etc
    label name_;

    // stores any info the client wants to associate with the node
    // templated to it can be made a struct or container to hold more than one piece of info as desired
    data info_;

    // stores a number representing the "color" assigned to the node - used for graph coloring problems
    int color_;

    // stores the edges connected to this node, represented by a pointer to the adjacent node and
    // a double representing the weight of the edge
    EdgeArray edges_;

};

#endif // GNODE_H