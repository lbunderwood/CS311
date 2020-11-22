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
#include <cstddef>
    // For std::size_t
#include <cmath>
    // For log

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

    // size_type will be used to keep track of the number of children
    using size_type = std::size_t;

// FibHeap : constructors and destructors
public:

    // Default Constructor
    FibHeap() : min_(nullptr), rootCount_(0) {}

    // Move and Copy Constructors and Assignment Operators
    FibHeap(const FibHeap& other);
    FibHeap operator=(const FibHeap& other);
    FibHeap(FibHeap&& other);
    FibHeap operator=(FibHeap && other);

    // Destructor
    ~FibHeap()
    {
        while(min_)
        {
            deleteMin();
        }
    }


// FibHeap : private member functions
private:

    // makeChild function
    // takes two FibNode pointers and makes the second a child of the first
    // both must already be a part of the heap, in order to preserve nodeCount
    void makeChild(FibNode<key_type, value_type>* parent, FibNode<key_type, value_type>* child)
    {
        // we only want to do anything if both are not nullptr
        if(parent && child)
        {
            // there are other children
            if(parent->child_)
            {
                // insert node between parent->child_ and parent->child_->next_
                child->next_ = min_->next_;
                child->prev_ = min_;
                ((parent->child_)->next_)->prev_ = child;
                (parent->child_)->next_ = child;
            }
            // otherwise, it is the only child
            else
            {
                parent->child_ = child
            }
        }
    }

    // combineTrees function
    //
    void combineTrees()
    {
        // create array to keep track of the number of children each root has
        std::vector<FibNode<key_type, value_type>*> degrees((int)(log(nodeCount_)/log(2)), nullptr);

        // use current to cycle through the nodes
        auto current = min_;
        
        do
        {
            // hold onto this so our spot is not lost
            auto next = current->next_;

            // if another node has that degree already
            if(degrees[current->childCount_])
            {
                // edit current out of the existing root list
                (current->next_)->prev_ = current->prev_;
                (current->prev_)->next_ = current->next_;

                // make the larger one the child of the smaller one
                if(current->key_ < degrees[current->childCount_]->key_)
                    makeChild(current, degrees[current->childCount_]);
                else
                    makeChild(degrees[current->childCount_], current);
            }
            // this is the first node we've found with that degree
            else
            {
                // stick it in the array
                degrees[current->childCount_] = current;
            }

            current = next;

        }while(current != min_)
    }

// FibHeap : public member functions
public:

    // findMin function
    // 
    FibNode<key_type, value_type>* findMin()
    {
        return min_;
    }

    // merge function
    // takes a FibNode pointer and adds it and its siblings to the list of roots
    // must already be a part of the heap, in order to preserve nodeCount
    void merge(FibNode<key_type, value_type>* other)
    {
        // we only want to do anything if other is not nullptr
        if(other)
        {
            // holds onto the end of the list being added
            auto placeHolder = other->prev_;

            // connect up the ends of this and the new list
            (min_->prev_)->next_ = other;
            placeHolder->next_ = min_;
            other->prev_ = min_->prev_;
            min_->prev_ = placeHolder;

            // make sure that min_ is still correct
            if(other->key_ < min_->key_)
            {
                min_ = other;
            }
        }
    }

    // insert function
    // 
    void insert(const key_type& key, const value_type& value)
    {
        // create a new node
        FibNode<key_type, value_type>* node = new FibNode<key_type, value_type>(key, value);
        
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

        // increase the number of roots
        ++nodeCount_;
        
    }

    // deleteMin function
    // 
    void deleteMin()
    {
        // make any children of min_ into roots
        merge(min_->child_);

        // set min_ to be something else
        min_ = min_->next_;

        // delete the old min_
        delete min_->prev_;

        // consolidate existing trees to make finding the new min_ logarithmic time
        combineTrees();
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

    // keeps track of the number of roots (siblings of min_, including min_)
    size_type nodeCount_;

};


#endif // #ifndef FIBHEAP_H