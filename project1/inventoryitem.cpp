// InventoryItem.cpp
// Matthew Perry
// Started: 2019-09-09
// 
//
// For CS 311 Fall 2019
// Source for class InventoryItem

#include "inventoryitem.h"
#include <ostream>
using std::string;
using std::ostream;

//********************************************************
// Class InventoryItem - Definitions of member functions
//********************************************************

// IventoryItem::getNumber
// (See header for docs.)
int InventoryItem::getNumber()const{
    return _count;
}

//InventoryItem::getName
// (See header for docs.)
string InventoryItem::getName()const{
    return _name;
}


// InventoryItem::setNumber
// (See header for docs.)
void InventoryItem::setNumber(int count){
    if(count < 0){
        _count = 0;
    }
    else
    {
        _count = count;
    }
    
}

//InvnetoryItem::setName
//(See header for docs.)
void InventoryItem::setName(string name){
    _name = name;
}

//toString
//(See header for docs.)
string InventoryItem::toString()const{
    return _name + " (" + std::to_string(_count) + ")";
}

//empty
//(See header for docs.)
bool InventoryItem::empty() const{
    if(_count == 0){
        return true;
    }
    else
    {
        return false;
    }
    
}

//operator== for InventoryItem
//(See header for docs.)
bool operator== (const InventoryItem &lhs, const InventoryItem &rhs)
{
	string name1, name2;
	int count1,count2;
	name1 = lhs.getName();
	count1 = lhs.getNumber();
	name2 = rhs.getName();
	count2 = rhs.getNumber();
	
	return ((name1 == name2) && (count1 == count2));
}

//operator!= for InventoryItem
//(See header for docs.)
bool operator!= (const InventoryItem &lhs, const InventoryItem &rhs)
{
	return !(lhs == rhs);
}

//operator<< for InventoryItem
//(See header for docs.)
ostream &operator<< (ostream &os, const InventoryItem &i)
{
	os << i.toString();
	return os;
}