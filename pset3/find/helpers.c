/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

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
    
    return false;
}

/**
 * Sorts array of n values.
 */
 
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
        for(int i = n; i > 0; i--)
        {
            
            printf("Im in the first loop, n is %d\n", n);
            
            for(int bubble = 0, j = 1; j < i; j++, bubble++)
            {
                int bubVal = values[bubble];
                int testVal = values[j];
                
                if (values[bubble] > values[j])
                {
                    printf("In the sort deepest loop\n");
                
                    values[j] = bubVal;
                    values[bubble] = testVal;
                }
            }
        }
}
