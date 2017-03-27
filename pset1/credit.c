#include <cs50.h>
#include <stdio.h>

void returnArr(long long x, int y);

int main(void)
{
    printf("Number: ");
    long long card = get_long_long();
    
    if(card < 1000000000000000 && card > 99999999999999) // American Express 
    {
        returnArr(card, 15);
    }
    else if(card < 10000000000000000 && card > 999999999999999) // MasterCard
    {
        returnArr(card, 16);
    }
    else if(card < 10000000000000 && card > 999999999999) // Visa
    {
        returnArr(card, 13);
    }
    else
    {
        printf("INVALID\n");
    }
}

void returnArr(long long x, int y)
{
    int count = 0;
    long long card = x;
    int cardArr[y];
    
    while(card > 0)
    {
        int digit = (card % 10);
        cardArr[count] = digit;
        card /= 10;
        count++;
    }
    
    for(int i = 1; i < y; i+= 2) // PRINT OUT THE ARRAY
    {
        cardArr[i] = cardArr[i] * 2;
        if(cardArr[i] > 9)
        {
            
        }
        printf("%d ", cardArr[i]);
    }
}