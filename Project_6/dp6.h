// Luke Underwood
// 11/2/2020
// CS311
// Project_6
// dp6.h
// header for all project_6 code

#ifndef DP6_H
#define DP6_H

// stl inclusions
#include <utility>
#include <cstddef>
#include <memory>
#include <iostream>

// file inclusions
#include "llnode2.h"


/////////////////////////////////////////////////////
//      EXERCISE A — Reversing a Linked List
/////////////////////////////////////////////////////


// Global template function reverseList
// reverses an LLNode2 list
// Parameters : 
//     unique_ptr to LLNode2 of templated ValType
//         - this should be the head of the list to reverse
// Preconditions : 
//     head must be an lvalue and point to a valid LLNode2<ValType>, or be nullptr
// Exception Guaruntee : 
//     Strong Guaruntee
//         - New is called in creation of unique ptr, but only before changes are made to data
//         - The only other operations are move operations, which do not throw.
// Requirements on types :
//     none, no operations are performed on ValType
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>>& head)
{
    // newHead is used to store the new beginning of the list at each iteration
    std::unique_ptr<LLNode2<ValType>> newHead = nullptr;
    // placeHolder is used to facilitate the three-pointer rotate by storing newHead's old value
    std::unique_ptr<LLNode2<ValType>> placeHolder = nullptr;

    // until head == nullptr, keep rotating the pointers
    // head will be nullptr when we reach the end of the list
    while(head)
    {
        placeHolder = std::move(newHead);
        newHead = std::move(head);
        head = std::move(newHead->_next);
        newHead->_next = std::move(placeHolder);
    }

    // make the original head = the new head, completing the reversal
    head = std::move(newHead);
}




/////////////////////////////////////////////////////
//  EXERCISE B — Associative Dataset Class Template
/////////////////////////////////////////////////////


// template class LLMap
// associative node-based data structure
// Class Invariants : 
//     no two nodes may have the same key
//     data_ must either be nullptr or point to a nullptr-terminated linked list of LLNode2
// Requirements on Types : 
//     K (key_type) must have operator==
template <typename K, typename D>
class LLMap
{

/////////// LLMap : Types
public:

    // key_type is the type used to index, sort, find, etc an item
    using key_type = K;

    // data_type is the type used to store the information 
    // associated with an object of key_type
    using data_type = D;

    // kv_type (key-value type) is the type used to associate the 
    // object of key_type with the object of data_type
    using kv_type = std::pair<key_type, data_type>;

    // nodeptr_type is the type used to refer to an LLNode2 pointer.
    // data_ will be of this type
    using nodeptr_type = std::unique_ptr<LLNode2<kv_type>>;

    // size_type is used only to describe the number of objects of kv_type
    // stored in the LLMap
    using size_type = std::size_t;


/////////// LLMap : Constructors & Destructor
public:

    // Default constructor
    // creates an empty dataset
    // Exception Guaruntee : 
    //     Strong Guaruntee
    //         - creation of data_ calls new, which can throw
    //         - no data will be changed
    LLMap() : data_(nullptr) {}

    // Move & copy constructors & assignment operators - all deleted
    LLMap(const LLMap& other) = delete;
    LLMap& operator=(const LLMap& other) = delete;
    LLMap(LLMap&& other) = delete;
    LLMap& operator=(LLMap&& other) = delete;

    // Destructor - written by compiler
    // Exception Guaruntee : 
    //     No-throw Guaruntee
    ~LLMap() = default;


/////////// LLMap : Member functions
public:

    // Member function LLMap::size
    // returns the size of the dataset
    // returns 0 if data_ == nullptr
    // Preconditions : 
    //     none
    // Exception Guaruntee : 
    //     No-throw Guaruntee
    //     size(const std::unique_ptr<LLNode2<ValType>>&) is no-throw
    size_type size() const noexcept
    {
        // I tried to simply do
        // return size(data_);
        // calling function size from llnode2.h, but for some reason the compiler wouldn't
        // recognize the function call, so I elected to simply copy it's design.
        // I recognize that this violates the SRP and DRY principle, but it's what works

        // THIS CODE COPIED FROM llnode2.h WRITTEN BY GLENN CHAPPELL
        auto p = data_.get();      // Iterates through list
        std::size_t counter = 0;  // Number of nodes so far
        while (p != nullptr)
        {
            ++counter;
            p = p->_next.get();
        }
        return counter;
    }

    // Member function LLMap::empty
    // returns true if data_ == nullptr, false otherwise
    // Preconditions : 
    //     none
    // Exception Guaruntee :
    //     No-throw Guaruntee
    bool empty() const 
    {
        return !data_;
    }

    // Member function LLMap::find (non-const version)
    // returns a pointer to the data associated with the provided key,
    // or nullptr if the key is not in the dataset
    // Preconditions : 
    //     key must be a valid lvalue of type key_type
    // Exception Guaruntee : 
    //     Strong Guaruntee
    //         - data is never modified, so if an exception is thrown,
    //           there will be no change visible to the caller
    data_type* find(const key_type& key)
    {
        data_type* output = nullptr;

        // traverse the list, checking for keys matching the one given
        traverse([&](const key_type& currentKey, data_type& currentData)
        {
            if(key == currentKey)
            {
                // if we find a match, set output to currentData's address
                output = &currentData;
            }
        });

        return output;
    }

    // Member function LLMap::find (const version)
    // returns a const pointer to the data associated with the provided key,
    // or nullptr if the key is not in the dataset
    // Preconditions : 
    //     key must be a valid lvalue of type key_type
    // Exception Guaruntee : 
    //     Strong Guaruntee
    //         - data is never modified, so if an exception is thrown,
    //           there will be no change visible to the caller
    const data_type* find(const key_type& key) const
    {
        data_type* output = nullptr;

        // traverse the list, checking for keys matching the one given
        traverse([&](const key_type& currentKey, data_type& currentData)
        {
            if(key == currentKey)
            {
                // if we find a match, set output to currentData's address
                output = &currentData;
            }
        });

        return output;
    }

    // Member function LLMap::insert
    // adds a node with the given key value pair
    // if another node has the same key, that node is deleted
    // Preconditions : 
    //     key and data must be valid lvalues of key_type and data_type 
    // Exception Guaruntee : 
    //     Basic Guaruntee
    //         - it is possible that a node could be erased, then push_front throws,
    //           leaving the data in a modified state
    void insert(const key_type& key, const data_type& data)
    {
        // if find(key) does not return nullptr, delete the old node
        if(find(key))
        {
            erase(key);
        }

        // add the new node
        push_front(data_, std::make_pair(key, data));        
    }

    // Member function LLMap::erase
    // erases a node with the given key
    // does nothing if no such node exists
    // Preconditions : 
    //     key must be a valid lvalue of key_type
    // Exception Guaruntee : 
    //     Strong Guaruntee
    //         - the only modification made to the data would be the final operation performed,
    //           so the function will either throw before modifying or succeed
    void erase(const key_type& key)
    {
        auto current = data_.get(); // raw pointer to current node
        auto previous = &data_;     // raw pointer to unique_ptr to previous node

        while(current)
        {
            // when we find the key, set the previous unique_ptr to skip the deleted node
            if(current->_data.first == key)
            {
                *previous = std::move(current->_next);
                break;
            }

            // move up both pointers for the next iteration
            previous = &(current->_next);
            current = current->_next.get();
        }
    }

    // Member function LLMap::traverse
    // calls a function on every node in the list
    // Preconditions : 
    //     function passed in must take parameters of key_type and data_type and return void
    // Exception Guaruntee : 
    //     Basic Guaruntee
    //         - func may modify data and throw
    // Requirements on Types : 
    //     function_type must be a callable object that takes parameters as listed above
    template <typename function_type>
    void traverse(const function_type& func) const
    {
        auto current = data_.get();

        // cycle through the list
        while(current)
        {
            // call the function on every node
            func(current->_data.first, current->_data.second);
            current = current->_next.get();
        }
    }

/////////// LLMap : Private data members
private:

    // head pointer for an LLNode2 data structure (see llnode2.h)
    nodeptr_type data_;

};


#endif // #ifndef DP6_H