// ksarray.h
// Matthew Perry
// Started: 2019-09-15
// Finished: 2019-9-17
//
// For CS 311 Fall 2019
// Header for class KSArray

#ifndef KSARRAY_H
#define KSARRAY_H
//cstdlib included for std::size_t
#include <cstdlib> 

//algorithm included for std::copy, std::min, std::equal, std::swap
#include <algorithm>

/*  class KSArray
    Simple RAII Class holding dynamic types and sizes via array
    A const KSArray does not allow modification of elements
    No source file 
    Invariants:
        _ptr points to memory allocated with new[]: owner *this
        Requirements of types:
            K must have these opperators: ==, !=, <, <=, >, >=, []
            K must have copy ctor, copy assignment(=), begin, end, size, dtor
            size_type must be non negative
    
*/
template <typename T>
class KSArray
{  
public:
    typedef T value_type;
    typedef size_t size_type;

private:
    size_type _size;
    value_type *_ptr;
    
    /*  Swap func for KSArray
        PRE: None
        POST: None
    */
   void mswap(KSArray & other)
    {
        std::swap(_size, other._size);
        std::swap(_ptr, other._ptr);
    }

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
   KSArray(const KSArray &rhs): _size(rhs.size()), _ptr(new value_type[rhs.size()])
   {
       std::copy(rhs.begin(), rhs.end(), _ptr);
   }
    /*  Move Constructor
        PRE:swap must be defined for object
        POST:returns swapped KSArray object with valid empty object
    */
   KSArray(KSArray && other)noexcept 
        :_size(0),_ptr(nullptr){mswap(other);}

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
    value_type *begin()
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
    const value_type *begin() const
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
        POST: Returns address of index wihin KSArray
    */
   value_type & operator[](const size_type & index)
   {
       return _ptr[index];
   }

    /*  const []operator
        PRE: Calling object must be const 
        POST: Returns address of index wihin KSArray
    */
    const value_type & operator[](const size_type & index) const
   {
       return _ptr[index];
   }

    /*  Copy assignment
        PRE: Swap must be defined
        POST: assigns rhs to *this
    */
   KSArray<T> & operator=(const KSArray &other)
   {
       if(this != &other)
    {
        KSArray copyOfother(other);
        mswap(copyOfother);
    }
       return *this;
   }
    /*  Move Assignment
        PRE:Swap must be defined
        POST:Returns the moved object to *this
    */
   KSArray<T> & operator=(KSArray &&other) noexcept
   {
        if(this != &other)
            mswap(other);
        return *this;
   }

};

//Non Class Memeber Functions

/*  operator == for KSArray.
    Parameters: Two KSArray objects
    PRE: operator != must be defined for value_type
    POST: returns bool true if lhs == rhs else false
*/
template <typename T>
bool operator==(const KSArray<T> &lhs, const KSArray<T> &rhs)
{
   return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

/*  operator != for KSArray.
    Parameters: Two KSArray objects
    PRE: operator == must be defined for value_type
    POST: returns bool true if lhs != rhs else false
*/
template <typename T>
bool operator!=(const KSArray<T> &lhs, const KSArray<T> &rhs)
{
    return !(lhs == rhs); //canonical representation
}

/*  operator < for KSArray.
    Paramerters: Two KSArray objects.
    PRE: The following must be defined for value_type Operator(s) ==,[],<,> and member function size.
    POST: Returns true if lhs < rhs else false
 */
template <typename T>
bool operator<(const KSArray<T> &lhs, const KSArray<T> &rhs)
{
    size_t mSize = std::min(lhs.size(), rhs.size());

    for(size_t i = 0; i < mSize; ++i)
    {
        if(lhs[i] < rhs[i])
            return true;
        else if(rhs[i] < lhs[i])
            return false;
    }
    return lhs.size() < rhs.size();
}

/*  operator > for KSArray.
    Paramerters: Two KSArray objects.
    PRE: The following must be defined for value_type Operator(s) <=
    POST: Returns true if lhs > rhs else false
 */
template <typename T>
bool operator>(const KSArray<T> &lhs, const KSArray<T> &rhs)
{
	return !(lhs <= rhs); //canonical representation
}

/*  operator <= for KSArray.
    Paramerters: Two KSArray objects.
    PRE: The following must be defined for value_type Operator(s) <, ==
    POST: Returns true if lhs <= rhs else false
 */
template <typename T>
bool operator<=(const KSArray<T> &lhs, const KSArray<T> &rhs)
{
	return !(rhs < lhs); //canonical representation
}

/*  operator >= for KSArray.
    Paramerters: Two KSArray objects.
    PRE: The following must be defined for value_type Operator(s) >, ==
    POST: Returns true if lhs >= rhs else false
 */
template <typename T>
bool operator>=(const KSArray<T> &lhs, const KSArray<T> &rhs)
{
	return !(lhs < rhs); //canonical representation
}

#endif