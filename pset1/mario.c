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
    
    if (height > 0 && height <= 23)
    {
        
        for (int i = 0; i < height; i++) //loop for each row
        {
            for (int j = 0; j < height; j++)
            {
                if ((j + 1) >= (height - i))
                {
                    printf("%c", pound);
                }
                else 
                {
                    printf(" ");
                }
            }
            
            printf("  "); //add double space
            
            for (int j = 0; j < height; j++)
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
        checkInt();
    }
}