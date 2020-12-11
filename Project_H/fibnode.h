// Luke Underwood
// 11/19/2020
// Project_H
// fibheap.h
// header file for class FibNode

// multiple-inclusion guards
#ifndef FIBNODE_H
#define FIBNODE_H

#include <cstddef>
    // For std::size_t

// Forward declaration of FibHeap for friend declaration
template<typename K, typename V>
class FibHeap;

// class FibNode
// 
// Node class for being used in Fibonacci Heap defined in fibheap.h
// Stores a key, value, count of how many children this node has, and pointers
// to siblings in a doubly-linked circular list, as well as this node's parent and 
// one of its children, as the rest can be accessed via the sibling list.
//
// Class Invariants :
//      If the node has no siblings, both prev_ and next_ must point to this node
//      If the node has no children, child_ must be nullptr
//      If the node has no parent (it is a root), parent_ must be nullptr
//      childCount_ must be updated whenever the child list is modified
//
// Template Type Requirements :
//      K and V must have copy constructors - required by 2-parameter constructor
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


// FibNode : constructors and destructor
public:

    // Default Constructor - should not be used
    FibNode() = delete;


    // Two-Parameter Constructor
    //
    // takes key and value, assigning them to key_ and value_,
    // sets childCount to 0, since there are not yet any children,
    // sets prev_ and next_ to this, and parent_ and child_ to nullptr, 
    // as required by invariants since there are not yet any related nodes
    //
    // Preconditions :
    //      key and value must be valid objects of the types given in template declaration
    //
    // Exception Guaruntee :
    //      Strong Guaruntee - data are not modified, merely copied
    FibNode(const key_type& key, const value_type& value) 
        : key_(key), value_(value), childCount_(0),
          next_(this), prev_(this), parent_(nullptr), child_(nullptr) {}


    // Move and Copy Constructors and Assignment Operators - should not be used
    FibNode(const FibNode& other) = delete;
    FibNode operator=(const FibNode& other) = delete;
    FibNode(FibNode&& other) = delete;
    FibNode operator=(FibNode && other) = delete;

    // Destructor - writen automatically, nothing special to do
    ~FibNode() = default;


// FibNode : public member functions
public:

    // member function getKey
    // returns the key
    // Preconditions : 
    //      none
    // Exception Guaruntee : 
    //      Strong Guraruntee - function is const so data cannot be modified
    key_type getKey() const
    {
        return key_;
    }

    // member function getValue
    // returns the value
    // Preconditions : 
    //      none
    // Exception Guaruntee : 
    //      Strong Guraruntee - function is const so data cannot be modified
    value_type getValue() const
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