/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in sorted array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //set the range for search window. Also to be used to initialize middle of window being searched
    int maxIndex = (n - 1);
    int minIndex = 0;
    
    
    if(n < 0) //searched array must be larger than zero
    {
        return false;
    }
    
    while((maxIndex - minIndex) > 1) //while window to search is large enough, contniue to narrow down index of result
    {
        int mid = maxIndex - minIndex;
        
        if(values[mid] == value)
        {
            return true; //we got lucky this time!
        }
        else if(values[mid] > value)
        {
            maxIndex = mid - 1; //reset max index, min index remains the same
        }
        else if(values[mid] < value)
        {
            minIndex = mid + 1; //reset min index, max index remains the same
        }
        
    }
    
    if (maxIndex - minIndex == 1) //only two values remain so check both. If not ether value, return false
    {
        if (values[maxIndex] == value)
        {
            return true;
        }
        else if (values[minIndex] == value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    return false; //default case
}


/**
 * Sorts array of n values.
 */
 
void sort(int values[], int n)
{
    // loop over every element of the array to buuble up largest ints
    for(int i = n; i > 0; i--)
    {
        for(int bubble = 0, j = 1; j < i; j++, bubble++) //second loop for each pair checking if bubble value is larger than test value
        {
            //set first and second value of bubble pair
            int bubVal = values[bubble]; 
            int testVal = values[j]; 
            
            if (values[bubble] > values[j])
            {
                //if first value in pair is larger, rearrange their positions in the array. Otherwise, continue through loops and on to next bubble pair
                values[j] = bubVal;
                values[bubble] = testVal;
            }
        }
    }
}
