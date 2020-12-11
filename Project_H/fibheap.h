// Luke Underwood
// 11/19/2020
// Project_H
// fibheap.h
// header file for class FibHeap

#ifndef FIBHEAP_H
#define FIBHEAP_H

// Standard Library Inclusions
#include <vector>
    // For std::vector
#include <cstddef>
    // For std::size_t
#include <cmath>
    // For log, ciel

// Other File Inclusions
#include "fibnode.h"


// class FibHeap
//
// Manages a fibonacci heap of fibNodes, defined in fibnode.h, with a public interface
// that only allows the client to insert nodes, view the minimum node, and delete the minimum node.
// Other functionality that is often given to fibonacci heaps has been omitted, since the sole
// purpose of this implementation is to serve an implementation of prim's which does not require
// any further functionality. (see prim.h & prim.cpp)
//
// Class Invariants :
//      The key of a child node must always be >= the key of the parent
//      min_ must always point to the minimum-key node, except briefly during insert and deleteMin
//      After performing deleteMin, there must not be any two roots (siblings of min_) with the same
//        degree (number of children), leaving a number of roots logarithmic to the number of nodes.
// 
// Template Type Requirements :
//      K and V must have copy constructors - required by insert
//      K must have operator<
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
    FibHeap() : min_(nullptr), nodeCount_(0) {}

    // Move and Copy Constructors and Assignment Operators
    FibHeap(const FibHeap& other);
    FibHeap operator=(const FibHeap& other);
    FibHeap(FibHeap&& other);
    FibHeap operator=(FibHeap && other);

    // Destructor
    ~FibHeap()
    {
        while(min_) // CHANGE THIS - DESTRUCTOR CAN THROW
        {
            deleteMin();
        }
    }


// FibHeap : private member functions
private:

    // member function merge
    //
    // takes a FibNode pointer and adds it and its siblings to the list of roots,
    // changing their former parent to no longer have children, and updating the
    // new roots' parent pointers
    // if other is nullptr, nothing happens
    //
    // Preconditions :
    //      other must already be a part of the heap, in order to preserve nodeCount
    //
    // Exception Guaruntee :
    //      Basig Guaruntee - data is modified throughout
    void merge(FibNode<key_type, value_type>* other)
    {
        // we only want to do anything if other is not nullptr
        if(other)
        {
            // reset children of former parent
            (other->parent_)->childCount_ = 0;
            (other->parent_)->child_ = nullptr;

            // make sure all new roots no longer have parents
            auto current = other;
            do
            {
                current->parent_ = nullptr;
                current = current->next_;
            }while(current != other);

            // holds onto the end of the list being added
            auto placeHolder = other->prev_;

            // connect up the ends of this and the new list
            (min_->prev_)->next_ = other;
            placeHolder->next_ = min_;
            other->prev_ = min_->prev_;
            min_->prev_ = placeHolder;
        }
    }

    // member function makeChild
    //
    // takes two FibNode pointers and makes the second a child of the first, making it either
    // the child pointed to by parent->child_, if parent did not previously have children,
    // or inserting it between parent->child_ and parent->child_->next_ if it did have children.
    // child's parent pointer and parent's childCount_ are updated accordingly
    // if either parent or child is nullptr, nothing happens
    //
    // Preconditions :
    //      both parent and child must already be a part of the heap, in order to preserve nodeCount
    //
    // Exception Guaruntee :
    //      Basic Guaruntee - data is modified throughout
    void makeChild(FibNode<key_type, value_type>* parent, FibNode<key_type, value_type>* child)
    {
        // we only want to do anything if both are not nullptr
        if(parent && child)
        {
            // there are other children
            if(parent->child_)
            {
                // insert node between parent->child_ and parent->child_->next_
                child->next_ = (parent->child_)->next_;
                child->prev_ = parent->child_;
                ((parent->child_)->next_)->prev_ = child;
                (parent->child_)->next_ = child;
            }
            // otherwise, it is the only child
            else
            {
                parent->child_ = child;
            }

            child->parent_ = parent;
            ++parent->childCount_;
        }
    }

    // member function isolate
    //
    // takes a node pointer and removes it from its sibling list, pointing it's prev_ and next_
    // pointers to itself, and it's former neighbors to each other.
    // node will keep any children.
    //
    // Precontions :
    //      node must be a member of the root list, since its parent pointer is not modified
    //      (the only cases in which we need such a function, this happens to be the case anyway)
    //
    // Exception Guaruntee :
    //      Basic Guaruntee - data is modified throughout
    void isolate(FibNode<key_type, value_type>* node)
    {
        // edit it out of its sibling list
        (node->next_)->prev_ = node->prev_;
        (node->prev_)->next_ = node->next_;

        // make the node point only to itself
        node->prev_ = node;
        node->next_ = node;
    }

    // member function combineTrees
    //
    // goes through the current root list, combining any roots that have the same degree until
    // they all have different numbers of children.
    // 
    // Preconditions :
    //      none
    // Exception Guaruntee :
    //      Basic Guaruntee - data is modified throughout
    void combineTrees()
    {
        // create array to keep track of the number of children each root has
        std::vector<FibNode<key_type, value_type>*> degrees((int)ceil(log(nodeCount_ + 1)/log(2)), nullptr);

        // use current to cycle through the nodes
        auto current = min_;
        
        do
        {
            // hold onto these for later use
            auto next = current->next_;

            // if another node has that degree already
            while(true)
            {
                auto currentDegree = current->childCount_;
                if(degrees[currentDegree])
                {
                    // make the larger one the child of the smaller one
                    if(current->key_ < degrees[currentDegree]->key_)
                    {
                        // make sure min_ will continue to point to a root
                        if(degrees[currentDegree] == min_)
                        {
                            min_ = min_->next_;
                        }

                        // make sure next is not about to be moved
                        if(degrees[currentDegree] == next)
                        {
                            next = next->next_;
                        }

                        // remove the other node from the root list
                        isolate(degrees[currentDegree]);

                        makeChild(current, degrees[currentDegree]);

                        // update degrees
                        degrees[currentDegree] = 0;
                        
                        // we might have just created a new conflict of degree values, 
                        //in which case we don't want to update this, but instead repeat this process
                        if(!degrees[current->childCount_])
                        {
                            degrees[current->childCount_] = current;
                            break;
                        }
                    }
                    else
                    {
                        // make sure min_ still contains a root
                        if(current == min_)
                        {
                            min_ = min_->next_;
                        }

                        // remove current from the root list
                        isolate(current);

                        makeChild(degrees[currentDegree], current);
                        
                        // update degrees
                        degrees[currentDegree] = 0;
                        if(!degrees[(current->parent_)->childCount_])
                        {
                            degrees[(current->parent_)->childCount_] = current->parent_;
                            break;
                        }

                        current = current->parent_;
                    }
                }
                // this is the first node we've found with that degree
                else
                {
                    // stick it in the array
                    degrees[current->childCount_] = current;
                    break;
                }
            }

            current = next;

        }while(current != min_);
    }

    // member function findMin
    // 
    // goes through the current list of roots and returns the one with the smallest key
    //
    // Preconditions :
    //      none
    // Exception Guaruntee :
    //      Strong Guaruntee - no data is modified
    FibNode<key_type, value_type>* findMin()
    {
        // use smallest to keep track of the min found
        auto smallest = min_;
        // use current to cycle through the nodes
        auto current = min_->next_;
        
        // cycle through all root nodes
        while(current != min_)
        {
            // if the current one is smaller, make it the new smallest
            if(current->key_ < smallest->key_)
            {
                smallest = current;
            }

            // advance current node
            current = current->next_;
        }

        // return the min
        return smallest;
    }

// FibHeap : public member functions
public:

    // member function getMin
    // returns a pointer to node with the smallest key
    // Preconditions : 
    //      none
    // Exception Guaruntee :
    //      Strong Guaruntee - no data modified
    FibNode<key_type, value_type>* getMin() const
    {
        return min_;
    }

    // member function insert
    // 
    // Takes a key and value, inserts a node with that key and value into the heap
    // New nodes are created using new, and aresimply added as roots, between min_ and min_->next
    // nodeCount is increased by 1
    //
    // Preconditions : 
    //      key and value must be valid objects of the correct types
    //
    // Exception Guaruntee :
    //      Basic Guaurntee - data are modified throughout
    //          key and data are never modified, only internal data of fibHeap
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

    // member function deleteMin
    // 
    // deletes the minimum node, combines roots into trees of differing degrees
    // to make finding the new min logarithmic-time, and then finds and sets the new min
    //
    // Preconditions :
    //      none
    // Exception Guaruntee :
    //      Basic Guaruntee - data are modified throughout
    void deleteMin()
    {
        // if there are no more nodes, we don't want to double-delete
        if(nodeCount_ <= 0)
        {
            return;
        }

        // make any children of min_ into roots
        merge(min_->child_);

        // a temporary value so we dont lose the rest of the roots
        auto newMin = min_->prev_;

        // edit out the old min_ 
        isolate(min_);

        // delete the old min_
        delete min_;

        min_ = newMin;

        // consolidate existing trees to make finding the new min_ logarithmic time
        combineTrees();

        // if we just deleted the last node, we want to make sure its obvious
        // that there are no more nodes
        if(nodeCount_ <= 1)
        {
            min_ = nullptr;
        }
        // otherwise, proceed as usual
        else
        {
            // change min_ to the new min
            min_ = findMin();
        }

        --nodeCount_;
    }

// FibHeap : member variables
private:

    // always points to the minimum-key node
    FibNode<key_type, value_type>* min_;

    // keeps track of the total number of nodes
    size_type nodeCount_;

};


#endif // #ifndef FIBHEAP_H