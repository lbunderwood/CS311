// Luke Underwood
// 11/19/2020
// Project_H
// fibheap.h
// header file for class FibHeap

#ifndef FIBHEAP_H
#define FIBHEAP_H

// Standard Library Inclusions
#include <utility>
    // For std::pair
#include <vector>
    // For std::vector
#include <memory>
    // For std::unique_ptr, std::make_unique

// Other File Inclusions
#include "fibnode.h"


// comments
// comments
// comments comments comments
// comments comments comments comments
// comments comments comments comments
template<typename K, typename V>
class FibHeap
{
// FibHeap : type declarations
public:

    // key_type will be used to represent the comparative value of each node
    using key_type = K;

    // value_type will be used to store information useful to the client code
    // that is associated with each node
    using value_type = V;

// FibHeap : constructors and destructors
public:

    // Default Constructor
    FibHeap() : min_(nullptr) {}

    // One-Parameter Constructor
    FibHeap(const FibNode<key_type, value_type>& node) : min_(&FibNode) {}

    // Move and Copy Constructors and Assignment Operators
    FibHeap(const FibHeap& other);
    FibHeap operator=(const FibHeap& other);
    FibHeap(FibHeap&& other);
    FibHeap operator=(FibHeap && other);

    // Destructor
    ~FibHeap();

// FibHeap : member functions
public:

    // findMin function
    // 
    FibNode<key_type, value_type>* findMin()
    {
        return min_;
    }

    // merge function
    // takes a FibNode and adds it and its siblings to the list of roots
    void merge(const FibNode<key_type, value_type>& other)
    {
        // holds onto the end of the list being added
        auto placeHolder = other.prev_;

        // connect up the ends of this and the new list
        (min_->prev_)->next_ = &other;
        placeHolder->next_ = min_;
        other.prev_ = min_->prev_;
        min->prev_ = placeHolder;

        // make sure that min_ is still correct
        if(other.min_->key_ < min_->key_)
        {
            min_ = other.min_;
        }
    }

    // merge function
    // this overload takes a FibHeap, then redirects to the FibNode-taking version
    void merge(const FibHeap& other)
    {
        merge(other.min_);
    }

    // insert function
    // 
    void insert(const key_type& key, const value_type& value)
    {
        // create a new node
        FibNode<key_type, value_type>* node = new node(key, value);
        
        // if there are already nodes in the heap
        if(min_)
        {
            // insert node between min_ and min_->next_
            node->next_ = min_->next_;
            node->prev_ = min_;
            (min_->next_)->prev_ = node;
            min_->next_ = node;

            if(key < min_->key_)
            {
                min_ = node;
            }
        }
        // otherwise, this is the first node
        else
        {
            min_ = node;
        }
        
    }

    // deleteMin function
    // 
    void deleteMin()
    {

    }

    // decreaseKey function
    //
    void decreaseKey();

    // erase function
    //
    void erase(const key_type& key);

// FibHeap : member variables
private:

    // always points to the minimum-key node
    FibNode<key_type, value_type>* min_;

};


#endif // #ifndef FIBHEAP_H