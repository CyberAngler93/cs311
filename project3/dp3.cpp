// dp3.cpp  
// Matt Perry
// Started: 2019-09-25
// Finished: 
// For CS 311 Fall 2019
// Source for Project 3 Functions
// Skeleton file supplied by Glenn G. Chapell 

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;

/* didItThrow: Takes a function and bool paramters and checks for thrown exception
** PRE: ff must be a function threw must be a boolean type
** POST: Runs funtion ff. If exception is thrown set threw=true and rethrows exception
** TYPES: No requirements on types.
*/
void didItThrow(const function<void()> & ff,
                bool & threw)
{
    threw = false;
    try
    {
        ff();
    }
    catch(...)
    {
        threw = true;
        throw;
    }
    
}


int gcd(int a,
        int b)
{
    return 42;  // Dummy return
    // TODO: Write this!!!
}

