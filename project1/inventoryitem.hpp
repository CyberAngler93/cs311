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
    // Increment Item _count pre increment.
    InventoryItem & operator++()
    {
        
    }

    // op++ [post]
    // Increment Item _count post increment.
    InventoryItem operator++([[maybe_unused]] int dummy)
    {
        
    }

    // op-- [pre]
    // Decrement Item _count pre decrement.
    InventoryItem & operator--()
    {
       
    }

    // op-- [post]
    // Decrement Item _count post decrement.
    InventoryItem operator--([[maybe_unused]] int dummy)
    {
       
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
