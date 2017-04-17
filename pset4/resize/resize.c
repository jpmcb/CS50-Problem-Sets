#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *args[])
{
    if(argc != 4)
    {
        fprintf(stderr, "Usage: ./resize f original.bmp resized.bmp\n");
        return 1;
    }
    
    int sizeFac = atof(args[1]);
    char *input = args[2];
    char *output = args[3];
    
    if(sizeFac > 100 || sizeFac < 0)
    {
        fprintf(stderr, "Usage: f must be between 0.0 and 100\n");
        return 1;
    }
    
    FILE *in = fopen(input, "r");
    if(in == NULL)
    {
        fprintf(stderr, "Please provide a valid input file.");
        return 2;
    }
    FILE *out = fopen(output, "w");
    if(out == NULL)
    {
        fclose(in);
        fprintf(stderr, "Please provide a valid output file.");
        return 3;
    }
    
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, in);
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, in);
    
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //write to change up the headers of the resize??
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, out);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, out);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // success
    fclose(inptr);
    fclose(outptr);
    return 0;
}