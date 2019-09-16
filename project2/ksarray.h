// ksarray.h
// Matthew Perry
// Started: 2019-09-15
// 
//
// For CS 311 Fall 2019
// Header for class KSArray

#ifndef KSARRAY_H
#define KSARRAY_H
//cstdlib included for std::size_t
#include <cstdlib> 
using std::size_t;

//algorithm included for std::copy
#include <algorithm>
using std::copy;

/*  class KSArray
    Simple RAII Class holding dynamic types and sizes via array
    A const KSArray does not allow modification of elements
    No source file 
    Invariants:
        _ptr points to memory allocated with new[]: owner *this
        Requirements of types:
            K must have these opperators: ==, !=, <, <=, >, >=, []
            K must have copy ctor, copy assignment(=), being, end, size, dtor
            size_type must be non negative
    
*/
template <typename K>
class KSArray
{
public:
    using size_type = size_t;
    using value_type = K;

private:
    size_type _size;
    value_type *_ptr;

public:
    /*  Default ctor
        PRE: None
        POST: Creates new array of size 8 wth element of type value_type, all elements are defualt constructed
    */
    KSArray():_size(8), _ptr(new value_type[8])
    {}

    /*  1 param ctor
        PRE: Size must be of type size_type. Non negative
        POST: Creates new array with type "value_type" of size with new[], all elements are defualt constructed
    */
   explicit KSArray(size_type size):_size(size), _ptr(new value_type[size])
   {}

    /*  2 param ctor
        PRE: Size must be of type size_type. Non negative, value must be of value_type
        POST: Creates new array with type "value_type" of size with new[], all elements are set to value
    */
   KSArray(size_type size, const value_type & value): _size(size), _ptr(new value_type[size])
   {
       for(int i = 0; i < _size; i++)
       {
           _ptr[i] = value;
       }
   }
};
#endif