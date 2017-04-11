#include <stdio.h>

int main(int argc, char *argv[])
{
    //ensure proper usage, throws this error if 2 command line arguments are not provided
    if(argc != 3)
    {
        fprintf(stderr, "usage: ./whodunit input_file.bmp output_file.bmp\n");
        return 1;
    }
    
    //remember the locations of the two file names in memory
    char *infile = argv[1];
    char *outfile = argv[2];
    
    //testing purposes / understand pointers
    // printf("%s \n", infile);
    // printf("%i \n", *outfile);
    
    return 0;
}