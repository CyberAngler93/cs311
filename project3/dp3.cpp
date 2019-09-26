// dp3.cpp  
// Matt Perry
// Started: 2019-09-25
// Finished: 2019-09-25
// For CS 311 Fall 2019
// Source for Project 3 Functions
// Skeleton file supplied by Glenn G. Chapell 

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;

/* didItThrow:Takes a function and bool paramters and checks for thrown exception
** PRE:ff must be a function threw must be a boolean type
** POST:Runs funtion ff. If exception is thrown set threw=true and rethrows exception
** TYPES:None
** ERROR:None
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

/*gcd:Recursive function to calcualte the gcd of 2 ints
**PRE:a and b must be >= 0, also a and b can not both be 0.
**POST:Returns an int that is the GCD of the two ints passed
**TYPES:None
**ERRORS:None
*/
int gcd(int a,
        int b)
{
   if (a == 0)
   {
       return b;
   }
   if(a > b){
       return gcd(b,a);
   }
   return gcd((b%a),a);
}

