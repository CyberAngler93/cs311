// dp6.h
// Matt Perry
// Started : 11/1/2019
// Finished:
// For CS311 Project6
// dp6.h is a header file for Reversing a Linked List
// As well as Associative Dataset Class Template



#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"

////////////////////////////////////////////////////////
// Exercise A Reversing a Linked List
// Function template named reverseList
// PRE:
// POST:
// ERROR:
// TYPE REQUIREMENTS:
// DISC:
////////////////////////////////////////////////////////
template<typename ValType>
void reverseList(unique_ptr<LLNode2<ValType>> & head);




////////////////////////////////////////////////////////
// Exercise B Associative Dataset Class Template
// PRE:
// POST:
// ERROR:
// TYPE REQUIREMENTS:
// DISC:
// Invariants: 
////////////////////////////////////////////////////////

template<typename KVType>
class LLMap
{
////////////////////////////////////////////////////////
// Data Memeber
private:
    std::unique_ptr<LLNode2<KVType>> _data;
////////////////////////////////////////////////////////
// Deleted functions
public:
    //Copy Ctor
    LLMap(const LLMap & other) = delete;
    //Copy Assigment
    LLMap & operator =(const LLMap & other) = delete;
    //Move Ctor
    LLMap(LLMap && other) = delete;
    //Move Assignment
    LLMap & operator =(LLMap && other) = delete;


////////////////////////////////////////////////////////
// Member Functions
public:
    //Default Constuctor
    //
    LLMap();

    //Destructor
    ~LLMaop();

    //Size of 
    int size();

    //Empty check
    bool empty();

    //Find key in const set & non const
    const KVType * find(value_type key);
    KVType * find(value_type key);

    //Inserts a key and value into set as long as no key exsist
    insert(value_type key, size_type value);

    //Erase
    //Erases a key and vlaue pair by key
    erase(value_type key);

    template<typename T>
    traverse();

////////////////////////////////////////////////////////


};


#endif //#ifndef FILE_DP6_H_INCLUDED
