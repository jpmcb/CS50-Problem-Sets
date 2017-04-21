#include <cs50.h>
#include <stdio.h>

const int BLOCK = 512;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s", argv[1]);
    }
    
    for(int i = 0, int j = 0; i < sizeof(input); i++)
    {
        fread(void *buffer, 1, 512, input);
        
        if(buffer[i] == 0xff &&
           buffer[i + 1] == 0xd8 &&
           buffer[i + 2] == 0xff &&
           (buffer[i + 3] & 0xf0) == 0xe0)
       {
           i += 4;
           sprintf()
       }
    }
}