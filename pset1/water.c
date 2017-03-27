#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many minutes was your shower? ");
    int minutes = get_int();
    
    printf("Minutes: %i\n", minutes);
    printf("Bottles: %i\n", (192 * minutes)/16); //equation to determine how much water is being used
}