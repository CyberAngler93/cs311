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
// Item 
class InventoryItem {

// ***** InventoryItem: Ctors, dctor, op= *****
public:

    // Default ctor
    // Set Item to zero.
    InventoryItem()
    {
        setItem();
    }

    // Ctor from hours, minutes, seconds
    // Set Item to given # of hours, minutes, seconds past midnight.
    // Extreme values of hh, mm, ss are corrected by shifting some whole
    // number of days forward or backward.
    InventoryItem()
    {
        setItem();
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
    // Move Item .
    InventoryItem & operator++()
    {
        
    }

    // op++ [post]
    // Move Item .
    InventoryItem operator++([[maybe_unused]] int dummy)
    {
        
    }

    // op-- [pre]
    // Move Item .
    InventoryItem & operator--()
    {
       
    }

    // op-- [post]
    // Move Item 
    InventoryItem operator--([[maybe_unused]] int dummy)
    {
       
    }

// ***** InventoryItem: General public functions *****
public:

    // getItem
    // Return 
    void getItem() const;

    // setItem
    // Set Item to given
    void setItem();

// ***** InventoryItem: Data members *****
private:
    std::string _name; //Name of item
    int _count;  // Number of items in stock

};  // End class InventoryItem


// *********************************************************************
// class InventoryItem - Declarations of associated global operators
// *********************************************************************


// operator<< (ostream,InventoryItem)
// Prints given InventoryItem object as 
std::ostream & operator<<(std::ostream & out,
                          const InventoryItem & t);


#endif  //#ifndef FILE_INVENTORYITEM_H_INCLUDED
