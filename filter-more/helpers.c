#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
        for (int j = 0, k = width; j < k; j++)
        {
            RGBTRIPLE temptrip = image[i][j];
            BYTE btemp;
            float temp = (temptrip.rgbtBlue + temptrip.rgbtGreen + temptrip.rgbtBlue)/3; // need to round this please

            // rounding
            if ((temp - (int)temp) >= 0.5)
            {
                btemp = (int)temp + 1;
            }
            else
            {
                btemp = (int)temp;
            }

            image[i][j].rgbtBlue = btemp;
            image[i][j].rgbtGreen = btemp;
            image[i][j].rgbtRed = btemp;

        }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
    {
        BYTE btemp;
        int j = 0;
        int k = width;
            // while j < width-j-1, swap image[i][j] w image[i][width-j-1] until
        while (j < (width - j - 1))
        {
            //swap
            RGBTRIPLE temptrip = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temptrip;
            j++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{



    
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
