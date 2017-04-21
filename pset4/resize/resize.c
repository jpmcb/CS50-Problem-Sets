#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *args[])
{
    if(argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n original.bmp resized.bmp\n");
        return 1;
    }
    
    int sizeFac = atoi(args[1]); //dose this need to be a floating point?
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
        fclose(output);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //write to change up the headers of the resize??
    BITMAPFILEHEADER outbf = bf;
    BITMAPINFOHEADER outbi = bi;
    
    outbi.biWidth = bi.biWidth * sizeFac;
    outbi.biHeight = bi.biHeight * sizeFac;
    
    int inpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //calculate the image size
    outbf.bfSize = bf.bfSize * sizeFac;
    outbi.biSizeImage = bi.biSizeImage * sizeFac;
    
    fwrite(&outbf, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&outbi, sizeof(BITMAPINFOHEADER), 1, output);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        
        for(int n = 0; n < sizeFac; n++)
        {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, input);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, output);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < out_padding; k++)
        {
            fputc(0x00, outptr);
        }
    }
    }

    // success
    fclose(inptr);
    fclose(outptr);
    return 0;
}