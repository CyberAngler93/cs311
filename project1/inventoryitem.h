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
        setNumber(0);
        setName("UNNAMED");
    }

    // Ctor from name and count
    // Set Item to given name and count
    // count must be >= 0
    InventoryItem(std::string name, int count)
    {
        setNumber(count);
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
    InventoryItem operator++(int number)
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
    InventoryItem operator--(int number)
    {
       auto save = *this;
       --(*this);
       return save;
    }

// ***** InventoryItem: General public functions *****
public:

    // getNumber
    // Post: returns the number of an item.
    int getNumber() const;

    // getName
    // Post: Returns a product name.
    std::string getName() const;

    // setNumber
    //This will take care of negative ints passed by user.
    // Post: Sets a the _count to count or 0.
    void setNumber(int count);

    // setName
    // Post: Set _name to name
    void setName(std::string name);

    // toString 
    // Post: returns a string representation of item in format "_name (_count)
    std::string toString() const;

    //empty
    //Post: returns a bool if inventory _count is zero
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
//Post: Returns True for equivalance False for non.
bool operator==(const InventoryItem &lhs, const InventoryItem &rhs);

//operator!=
//compare two item objects for non equivalance by using == operator 
//Post: Returns True for non equivalance and False for Equivalance
bool operator!=(const InventoryItem &lhs, const InventoryItem &rhs);

// operator<< (ostream,InventoryItem)
//Post: Prints given InventoryItem object by using toString.
std::ostream & operator<<(std::ostream & os,
                          const InventoryItem & i);


#endif  //#ifndef FILE_INVENTORYITEM_H_INCLUDED
