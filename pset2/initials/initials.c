#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void getInitials(string);

int main(void) 
{
    //get & set variable for string of person's name
    string myString = get_string();
    //call function to print out given initials & pass given string
    getInitials(myString);
}

void getInitials(string s)
{
    int slength = strlen(s); //set the string length
    
    for (int i = 0; i < slength; i ++) //loop through each character of given string
    {
        if (i == 0 && s[i] >= 65 && s[i] <= 119) //if first char is a letter, print it out, otherwise ...
        {
            printf("%c", toupper(s[i]));
        }
        
        //print any char that is followed by a space & is a letter
        else if (s[i] != ' ' && s[i - 1] == ' ' && s[i] >= 65 && s[i] <= 119) 
        {
            printf("%c", toupper(s[i]));
        }
    }
    
    printf("\n");
}