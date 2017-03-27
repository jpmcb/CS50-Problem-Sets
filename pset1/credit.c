#include <cs50.h>
#include <stdio.h>

bool returnArr(long long x, int y); //function that returns true or false if card is valid or not

int main(void)
{
    printf("Number: ");
    long long card = get_long_long();
    
    if (card < 5000000000000 && card > 3999999999999) // Visa 13 digit starting with a 4
    {
        bool truth = returnArr(card, 13);
        if(truth)
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else if (card < 5000000000000000 && card > 3999999999999999) // Visa 16 digit starting with a 4
    {
        bool truth = returnArr(card, 16);
        if(truth)
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else if(card < 1000000000000000 && card > 99999999999999) // American Express 
    {
        bool truth = returnArr(card, 15);
        if(truth)
        {
            printf("AMEX\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else if(card < 10000000000000000 && card > 999999999999999) // MasterCard
    {
        bool truth = returnArr(card, 16);
        if(truth)
        {
            printf("MASTERCARD\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else //if number is not a 13, 15, or 16 digits long
    {
        printf("INVALID\n");
    }
}

bool returnArr(long long x, int y)
{
    int count = 0;
    long long card = x;
    int cardArr[y];
    
    while(card > 0) //split card number into individual digits
    {
        int digit = (card % 10);
        cardArr[count] = digit;
        card /= 10;
        count++;
    }
    
    int addingDig = 0; //integer to hold number and be added to
    
    for(int i = 1; i < y; i += 2) // loop through every other number starting with the second to last
    {
        cardArr[i] = cardArr[i] * 2; //multiply each by 2
        if(cardArr[i] > 9) //if greater than 10, divide into digits and add add to running total
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
    
    for(int i = 0; i < y; i += 2) //loop through cardArr again for other numbers in card to be added to total
    {
        addingDig += cardArr[i]; //add them to the ongoing count
    }
    
    if((addingDig % 10) != 0) //check if remainder divided by 10 is zero and return to main function
    {
        return false;
    }
    else
    {
        return true;
    }
}