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
//     head must point to a valid LLNode2<ValType>, or be nullptr
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
//
// Requirements on Types : 
//     must have operator==
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
        return size(data_);
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
    // Preconditions : 
    // 
    // Exception Guaruntee : 
    data_type* find(const key_type& key)
    {
        std::unique_ptr<LLNode2<kv_type>> current = nullptr;
        return &data_->_data.second; //dummy
    }

    // Member function LLMap::find (const version)
    // Preconditions : 
    // 
    // Exception Guaruntee : 
    const data_type* find(const key_type& key) const
    {
        // TODO : Write this
        return &data_->_data.second; //dummy
    }

    // Member function LLMap::insert
    // Preconditions : 
    // 
    // Exception Guaruntee : 
    void insert(const key_type& key, const data_type& data)
    {
        // TODO : Write this
    }

    // Member function LLMap::erase
    // Preconditions : 
    // 
    // Exception Guaruntee : 
    // 
    void erase(const key_type& key)
    {
        // TODO : Write this
    }

    // Member function LLMap::traverse
    // Preconditions : 
    // 
    // Exception Guaruntee : 
    //
    // Requirements on Types : 
    //
    template <typename function_type>
    void traverse(const function_type& func)
    {
        // TODO : Write this
    }

/////////// LLMap : Private data members
private:

    // head pointer for an LLNode2 data structure (see llnode2.h)
    std::unique_ptr<LLNode2<kv_type>> data_;

};


#endif // #ifndef DP6_H