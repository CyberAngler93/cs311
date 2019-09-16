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

//algorithm included for std::copy
#include <algorithm>

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
    using size_type = std::size_t;
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

    /*  Copy ctor, preforms deep copy via std::copy from <algorithm>
        PRE: begin and end must be defined
        POST: deallocates rhs, creats new KSArray object equal to rhs
    */   
   KSArray(const KSArray & rhs): _size(rhs.size()), _ptr(new value_type[rhs.size()])
   {
       std::copy(rhs.being(), rhs.end(), _ptr);
   }

	/* dtor for KSArray
	 * PRE: None
	 * POST: Memory pointed to by _ptr is deallcated
	 */ 
	~KSArray()
	{ 
		delete [] _ptr;
	}

   //Memeber Functions for KSArray

   /*   Memeber function size(). No parameters
        PRE: N/A
        POST: Returns a size_type for the size of KSArray
   */
    size_type size() const
    {
        return _size;
    }

   /*   Memeber function begin(). No parameters
        PRE: Must be called on a non const KSArray object
        POST: Returns the address of first element of KSArray Object
   */
    value_type *being()
    {
        return _ptr;
    }

    /*  Memeber function end(). No parameters
        PRE: Must be called on a non const KSArray object
        POST: Returns the address of last element of KSArray Object
   */
    value_type *end()
    {
        return(begin() + _size);
    }

   /*   Memeber function begin(). No parameters
        PRE: Must be called on a const KSArray object
        POST: Returns the address of first element of KSArray Object
   */
    const value_type *being() const
    {
        return _ptr;
    }

    /*  Memeber function end(). No parameters
        PRE: Must be called on a const KSArray object
        POST: Returns the address of last element of KSArray Object
   */
    const value_type *end() const
    {
        return(begin() + _size);
    }

    //Operators for KSArray

    /*  []operator
        PRE: Calling object must be non const 
        POST: Returns address of index
    */
   value_type & operator[](const size_type & index)
   {
       return _ptr[index];
   }

    /*  const []operator
        PRE: Calling object must be const 
        POST: Returns address of index
    */
    const value_type & operator[](const size_type & index) const
   {
       return _ptr[index];
   }

    /*  Copy assignment
        PRE: operator, being , end, size must be defined. rhs must be a KSArray obj.
        POST: assigns rhs to *this
    */
   KSArray & operator=(const KSArray & rhs)
   {
       if(this != &rhs)
       {
           delete[] _ptr;
           _ptr = new value_type[rhs.size()];
           _size = rhs.size();
           std::copy(rhs.begin(), rhs.end(), _ptr);
       }
       return *this;
   }

};
#endif