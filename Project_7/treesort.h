// treesort.h  SKELETON
// Glenn G. Chappell
// 2020-11-09
//
// For CS 311 Fall 2020
// Header for function template treesort
// There is no associated source file.

////////////////////////////////////////////////
// 
// Modified 11/10/2020
// Luke Underwood
// Project_7
// CS311

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <iterator>
// For std::iterator_traits
#include <memory>
// For std::unique_ptr, std::make_unique

// template class BSNode
//  Binary Search Tree Node - contains a piece of information and pointers to left and right child nodes
//  Nodes should only be reffered to via smart pointers
//  If a child node is nullptr, it does not exist
//  There are two helper functions for this class that have been made friends - insert and inorder
//  The only valid constructor is one-parameter, given the data it is to store
//  This constructor should not be called directly, but via make_unique
// Class Invariants :
//     All values stored in the left subtree (the node pointed to by left_ and all of it's decendants)
//      must be < the value stored in this node.
//     All values stored in the right subtree (see above definition, but with right_) must be >= the value
//      stored in this node.
// Restrictions on Types : 
//     None
//     This is not true for helper functions
template <typename T>
class BSNode
{
////////// BSNode : Types
public:

    // value_type will be used to refer to the type stored in each node
    using value_type = T;

    // ptr_type will be used to point to other nodes
    using ptr_type = std::unique_ptr<BSNode<value_type>>;

////////// BSNode : Constructors & Destructor
public:

    BSNode(const value_type& value) : data_(value), right_(nullptr), left_(nullptr) {}

    // Default Constructor
    // Deleted, so we don't have to require that value_type have a default constructor
    BSNode() = delete;

    // Copy and Move Constructors and Assignment Operators
    // Deleted, because these operations should only be done by pointer manipulation
    BSNode(const BSNode&) = delete;
    BSNode operator=(const BSNode&) = delete;
    BSNode(BSNode&&) = delete;
    BSNode operator=(BSNode&&) = delete;

    // Destructor
    // Written by compiler
    ~BSNode() = default;

////////// BSNode : Friend Helper Functions
public:

    // see documentation below
    template<typename V>
    friend void insert(const std::unique_ptr<BSNode<V>>& root, const V& data);
    template<typename V>
    friend std::deque<V> inorder(const std::unique_ptr<BSNode<V>>& root);

////////// BSNode : Member Variables
public:

    // the piece of information stored in this node
    value_type data_;

    // the left and right children of this node
    ptr_type left_;
    ptr_type right_;

};

///////////////////////////////////////////////////////
/////////   BSNode Helper Functions
///////////////////////////////////////////////////////

// insert
// Inserts an item into a BSNode tree given the root pointer and the item
// Pre:
//     root must either be nullptr or a pointer to the root of a valid BSNode tree
//     data must be an lvalue
// Requirements on Types:
//     V must be comparable via <
// Exception safety guarantee:
//     Strong guaruntee - final operation is the only one that changes data
template<typename V>
void insert(std::unique_ptr<BSNode<V>>& root, const V& data)
{
    // if this node doesn't exist
    if(!root)
    {
        // create the node
        root = std::make_unique<BSNode<V>>(data);
    }
    // if the data is < the current node's data
    else if(data < root->data_)
    {
        // recurse with left subtree
        insert(root->left_, data);
    }
    // data >= root->data_ (since this is the only other possibility)
    else
    {
        // recurse with right subtree
        insert(root->right_, data);
    }
}

// inorder
// Returns an inorder traversal of a BSNode tree given the root pointer and an iterator to write to
// Pre:
//     ???
// Requirements on Types:
//     The type reffered to by iter must have a copy assignment operator
//     Iter must have a prefix operator++
// Exception safety guarantee:
//     Basic Guaruntee - data is changed throughout the process, so the strong guaruntee cannot be offered
template<typename Iter>
void inorder(std::unique_ptr<BSNode<typename std::iterator_traits<Iter>::value_type>>& root, Iter& iter)
{
    // if this node does not exist, get us out of here
    if(!root) return;
    
    // traverse left subtree
    inorder(root->left_, iter);

    // write current node's data to position of iterator
    *iter = root->data_;
    ++iter;

    // traverse right subtree
    inorder(root->right_, iter);
}

// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;

    // create root node
    std::unique_ptr<BSNode<Value>> root = nullptr;

    // create binary search tree
    for(FDIter i = first; i != last; ++i)
    {
        insert(root, *i);
    }

    // write inorder traversal to the given range
    inorder(root, first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

