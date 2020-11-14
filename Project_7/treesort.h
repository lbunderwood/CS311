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
#include <deque>
// For std::deque

// *******************************************************
// * YOU MIGHT WANT TO GET RID OF THE FOLLOWING INCLUDES *
// *******************************************************

#include <algorithm>
// For std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance

// template class BSNode
// 
//
//
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
    friend void insert(const BSNode<value_type>& head, const value_type& data);
    friend std::deque<value_type> inorder(const BSNode<value_type>& head);

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
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename value_type>
void insert(const BSNode::ptr_type& head, const value_type& data)
{
    // TODO : Write this
}

// inorder
// Returns an inorder traversal of a BSNode tree given the root pointer
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename value_type>
std::deque<value_type> inorder(const BSNode::ptr_type& head)
{
    return std::deque<value_type>();
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
    BSNode::ptr_type<Value> root = std::make_unique<Value>;;
    
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

