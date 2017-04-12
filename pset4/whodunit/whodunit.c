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
    
    //open the input file
    FILE *input = fopen(infile, "r");
    if(input == NULL) //unable to open the input file
    {
        fprintf(stderr, "Could not open %s, please check the file \n", infile);
        return 2;
    }
    FILE *output = fopen(outfile, "w");
    if(output == NULL)
    {
        fclose(input);
        fprintf(stderr, "Could not write %s, please check your syntax \n", outfile);
        return 3
    }
    
    //testing purposes / understand pointers
    // printf("%s \n", infile);
    // printf("%i \n", *outfile);
    
    return 0;
}