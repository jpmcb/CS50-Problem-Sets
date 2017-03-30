#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    
    if(argc == 2) // ensure there is just one argument after executable code
    {
        printf("plaintext: ");
    
        string myString = get_string(); // get string from user to encrypt
        
        int myLength = strlen(myString); //string length
        int cyph = atoi(argv[1]); // string to int from given arguments
        
        printf("ciphertext: ");
        
        for (int i = 0; i < myLength; i++) // loop through string
        {
            if (myString[i] >= 65 && myString[i] <= 90) //Cap letter characters
            {
                printf("%c", 65 + (((myString[i] - 65) + cyph) % 26) );
            }
            
            else if (myString[i] >= 97 && myString[i] <= 122) //lowercase letter characters
            {
                printf("%c", 97 + (((myString[i] - 97) + cyph) % 26) );
            }
            
            else
            {
                printf("%c", myString[i]); //everything else
            }
        }
        
        printf("\n");
        return 0;
    }
    
    else 
    {
        printf("Please provide one command line argument\n");
        return 1;
    }
}