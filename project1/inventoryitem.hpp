// InventoryItem.h
// Matthew Perry
// Started: 2019-09-09
// 
//
// For CS 311 Fall 2019
// Header for class InventoryItem


#ifndef FILE_INVENTORYITEM_H_INCLUDED
#define FILE_INVENTORYITEM_H_INCLUDED

#include <ostream>  // For std::ostream


// *********************************************************************
// class InventoryItem - Class definition
// *********************************************************************


// class InventoryItem
// Item is represented by a string for name and has a number of item.
//Invariants:
//      _name is a valid c++ string
//      0 <= _count 
class InventoryItem {

// ***** InventoryItem: Ctors, dctor, op= *****
public:

    // Default ctor
    // Set Count to zero.
    // Set Name to UNAMED
    InventoryItem()
    {
        setCount(0);
        setName("UNAMED");
    }

    // Ctor from name and count
    // Set Item to given name and count
    // count must be >= 0
    InventoryItem(int count, std::string name)
    {
        setCount(count);
        setName(name);
    }

    // Big 5: use compiler-generated versions
    ~InventoryItem() = default;
    InventoryItem(const InventoryItem & other) = default;
    InventoryItem(InventoryItem && other) = default;
    InventoryItem & operator=(const InventoryItem & other) = default;
    InventoryItem & operator=(InventoryItem && other) = default;

// ***** InventoryItem: General public operators *****
public:

    // op++ [pre]
    // Increment Item _count by 1.
    InventoryItem & operator++()
    {
        _count++;
        return *this;
        
    }

    // op++ [post]
    // Increment Item _count by 1.
    InventoryItem operator++([[maybe_unused]] int dummy)
    {
        auto save = *this;
        ++(*this);
        return save;
    }

    // op-- [pre]
    // Decrement Item _count by 1.
    // If count goes below zero set count to zero.
    InventoryItem & operator--()
    {
       _count--;
       if(_count < 0){
           _count = 0;
       }
       return *this;
    }

    // op-- [post]
    // Decrement Item _count by 1.
    InventoryItem operator--([[maybe_unused]] int dummy)
    {
       auto save = *this;
       --(*this);
       return save;
    }

// ***** InventoryItem: General public functions *****
public:

    // getCount
    // Return 
    int getCount() const;

    // getName
    // Returns a product name
    std::string getName() const;

    // setCount
    // Set Item to given
    void setCount(int count);

    // setName
    // Set Name to given
    void setName(std::string name);

    // toString 
    // returns a string representation of item
    std::string toString() const;

    //empty
    //returns a bool if inventory _count is zero
    bool empty() const;

// ***** InventoryItem: Data members *****
private:
    std::string _name; //Name of item
    int _count;  // Number of items in stock

};  // End class InventoryItem


// *********************************************************************
// class InventoryItem - Declarations of associated global operators
// *********************************************************************

//operator==
//compares two item obejcts for equivalance.
bool operator==(const InventoryItem &lhs, const InventoryItem &rhs);

//operator!=
//compare two item objects for non equivalance.
bool operator!=(const InventoryItem &lhs, const InventoryItem &rhs);

// operator<< (ostream,InventoryItem)
// Prints given InventoryItem object as 
std::ostream & operator<<(std::ostream & out,
                          const InventoryItem & t);


#endif  //#ifndef FILE_INVENTORYITEM_H_INCLUDED
