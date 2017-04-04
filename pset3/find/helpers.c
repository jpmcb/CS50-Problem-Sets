/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    int maxIndex = (n - 1);
    int minIndex = 0;
    
    
    if(n < 0)
    {
        return false;
    }
    
    while((maxIndex - minIndex) > 1)
    {
        int mid = maxIndex - minIndex;
        
        if(values[mid] == value)
        {
            return true;
        }
        else if(values[mid] > value)
        {
            maxIndex = mid - 1;
        }
        else if(values[mid] < value)
        {
            minIndex = mid + 1;
        }
        
    }
    
    if (maxIndex - minIndex == 1)
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
}

/**
 * Sorts array of n values.
 */
 
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int index = 0;
    
    for(int i = (n - 1); i < 0; i--)
    {
        for(int j = 1; j < i; j++)
        {
            if (values[count] < values[j + 1])
            {
                
            }
        }
    }
    
    return;
}
