#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc == 2) //arguments list must contain one keyword
    {
        string a = argv[1];
        int a_len = strlen(argv[1]);
        
        for(int i = 0; i < a_len; i++) //is keyworkd a valid lowercase or uppercase alphabetical char?
        {
            
            if(a[i] < 65 || a[i] > 90)
            {
                if(a[i] < 65)
                {
                   printf("Please provide valide alphabetic word to be used for the cipher \n");
                   return 1; 
                }
                else if(a[i] < 97 || a[i] > 122)
                {
                    printf("Please provide valide alphabetic word to be used for the cipher \n");
                    return 1;
                }
            }    
            
            else if(a[i] < 97 || a[i] > 122)
            {
                if(a[i] > 122)
                {
                    printf("Please provide valide alphabetic word to be used for the cipher \n");
                    return 1;
                }
                else if(a[i] < 65 || a[i] > 90)
                {
                    printf("Please provide valide alphabetic word to be used for the cipher \n");
                    return 1;
                }
            }

        }
        
        printf("plaintext: ");
        string s = get_string(); //get text to be encrpyted
        int s_len = strlen(s);
        
        printf("ciphertext: ");
        for (int i = 0, j = 0; i < s_len; i++) //
        {
            if (j >= a_len) //rest keyword to first char if couter has exceeded word length
            {
                j = 0;
            }
            
            if (s[i] >= 65 && s[i] <= 90) //uppercase letters
            {
                printf("%c", 65 + (((s[i] - 65) + (tolower(a[j]) - 97)) % 26) ); //algo to increment by keyword
                j++;
            }
            else if (s[i] >= 97 && s[i] <= 122) //lowercase letters 
            {
                printf("%c", 97 + (((s[i] - 97) + (tolower(a[j]) - 97)) % 26) ); //algo to increment by keyword
                j++;
            }
            else
            {
                printf("%c", s[i]); //print spaces, other non alphabetical char
            }
            
            
        }
        
        printf("\n");
        return 0;
    }
    
    else //if provided argument is more than one word
    {
        printf("Please provide one word to be used for the cipher \n");
        return 1;
    }
    
    string s = get_string();
    printf("%s", s);
}