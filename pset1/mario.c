#include <cs50.h>
#include <stdio.h>

void checkInt(void);

int main(void)
{
    printf("Height: ");
    checkInt(); //function to check for valid number 
}

void checkInt(void)
{
    int height = get_int();
    char pound = '#';
    
    if (height > 0 && height < 23) //check if numbers within given range
    {
        for (int i = 0; i < height; i++) //loop for each row of pyramid
        {
            for (int j = 0; j < height; j++) //first half of pyramid
            {
                if ((j + 1) >= (height - i)) //determines spacing of pound
                {
                    printf("%c", pound);
                }
                else 
                {
                    printf(" ");
                }
            }
            
            printf("  "); //add double space pipe for mario to go find coins
            
            for (int j = 0; j < height; j++) //second half of pyramid 
            {
                if(j <= i)
                {
                    if(j == (height - 1))
                    {
                        printf("%c\n", pound);
                        break;
                    }
                    else 
                    {
                        printf("%c", pound);
                    }
                }
                else if(j > i && j < height)
                {
                    printf(" \n");
                    break;
                }
            }
        }
    }
    
    else
    {
        printf("Retry: ");
        checkInt(); //recall function if number invalid
    }
}