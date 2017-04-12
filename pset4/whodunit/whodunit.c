#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

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
        return 3;
    }
    
    //read the passed input file fileheader and write the data to bf
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, input);
    
    //read the passed input file infoheader and write the data to bi
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, input);
    
    //check to ensure input is a valid BMP file
    if(bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
       bi.biBitCount != 24 || bi.biCompression != 0)
       {
           fclose(output);
           fclose(input);
           fprintf(stderr, "File format not supported, please provide valid BMP file.\n");
           return 4;
       }
    
    //write the output's fileheader & infoheader
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, output);
    
    //sets padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //iterate over input's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;
            fread(&triple, sizeof(RGBTRIPLE), 1, input);
            fwrite(&triple, sizeof(RGBTRIPLE), 1, output);
        }
        
        fseek(input, padding, SEEK_CUR);
        
        for(int k = 0; k < padding; k++)
        {
            fputc(0x00, output);
        }
    }
    
    fclose(input);
    fclose(output);
    return 0;
}