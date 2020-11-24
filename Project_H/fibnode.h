// Luke Underwood
// 11/19/2020
// Project_H
// fibheap.h
// header file for class FibNode

// multiple-inclusion guards
#ifndef FIBNODE_H
#define FIBNODE_H

// Standard Library Inclusions
#include <utility>
    // For std::pair
#include <memory>
    // For std::unique_ptr, std::make_unique
#include <cstddef>
    // For std::size_t

// Forward declaration of FibHeap for friend declaration
template<typename K, typename V>
class FibHeap;

// comments
// comments
// comments comments comments
// comments comments comments comments
// comments comments comments comments
template<typename K, typename V>
class FibNode
{
// FibNode : type declarations
public:

    // key_type will be used to represent the comparative value of this node 
    using key_type = K;

    // value_type will be used to store information useful to the client code
    // that is associated with this node
    using value_type = V;

    // size_type will be used to keep track of the number of children
    using size_type = std::size_t;

// FibNode : friend declaration
public:

    // FibHeap needs access to FibNode's priavate members
    friend FibHeap<key_type, value_type>;


// FibNode : friend declaration
public:

    // Default Constructor
    FibNode() = delete;

    // Two-Parameter Constructor
    FibNode(const key_type& key, const value_type& value) 
        : key_(key), value_(value), marked_(false), childCount_(0),
          next_(this), prev_(this), parent_(nullptr), child_(nullptr) {}

    // Move and Copy Constructors and Assignment Operators
    FibNode(const FibNode& other) = delete;
    FibNode operator=(const FibNode& other) = delete;
    FibNode(FibNode&& other) = delete;
    FibNode operator=(FibNode && other) = delete;

    // Destructor
    ~FibNode() = default;


// FibNode : friend declaration
public:

    key_type getKey()
    {
        return key_;
    }

    value_type getValue()
    {
        return value_;
    }

// FibNode : member variables
private:

    ////////// DATA ///////////

    // key of this node
    key_type key_;

    // data stored in this node
    value_type value_;

    // COMMENT HERE
    bool marked_;

    // keeps track of the number of children this node has
    size_type childCount_;

    ////////// RELATED NODES ///////////

    // pointers to adjacent sibling nodes
    FibNode* next_;
    FibNode* prev_;

    // pointers to one of the child nodes
    FibNode* parent_;
    FibNode* child_;
};

#endif // #ifndef FIBNODE_H