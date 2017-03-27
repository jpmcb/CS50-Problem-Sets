#include <cs50.h>
#include <stdio.h>

bool returnArr(long long x, int y);

int main(void)
{
    printf("Number: ");
    long long card = get_long_long();
    
    if(card < 1000000000000000 && card > 99999999999999) // American Express 
    {
        bool truth = returnArr(card, 15);
        if(truth)
        {
            printf("AMERICAN EXPRESS \n");
        }
        else 
        {
            printf("INVALID \n");
        }
    }
    else if(card < 10000000000000000 && card > 999999999999999) // MasterCard
    {
        bool truth = returnArr(card, 16);
        if(truth)
        {
            printf("MASTERCARD \n");
        }
        else 
        {
            printf("INVALID \n");
        }
    }
    else if(card < 10000000000000 && card > 999999999999) // Visa
    {
        bool truth = returnArr(card, 13);
        if(truth)
        {
            printf("VISA \n");
        }
        else 
        {
            printf("INVALID \n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool returnArr(long long x, int y)
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
    
    int addingDig = 0;
    
    for(int i = 1; i < y; i += 2) // PRINT OUT THE ARRAY
    {
        cardArr[i] = cardArr[i] * 2; //multiply each by 2
        if(cardArr[i] > 9)
        {
            int oneDigit = (cardArr[i] % 10);
            int twoDigit = ((cardArr[i] / 10) % 10);
            
            addingDig += oneDigit;
            addingDig += twoDigit;
        }
        else
        {
            addingDig += cardArr[i];
        }
    }
    
    for(int i = 0; i < y; i += 2) //loop through cardArr again for other numbers in card
    {
        addingDig += cardArr[i]; //add them to the ongoing count
    }
    
    if((addingDig % 10) != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}