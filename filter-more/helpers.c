#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
        for (int j = 0, k = width; j < k; j++)
        {
            RGBTRIPLE temptrip = image[i][j];
            BYTE btemp;
            float temp = (temptrip.rgbtBlue + temptrip.rgbtGreen + temptrip.rgbtRed)/3; // need to round this please

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
 for (int i = 0; i < height; i++)
 {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE temptrip;
            temptrip.rgbtBlue = 0;
            temptrip.rgbtGreen = 0;
            temptrip.rgbtRed = 0;
            BYTE btemp;
         //   float temp = (temptrip.rgbtBlue + temptrip.rgbtGreen + temptrip.rgbtBlue)/3; // need to round this please

            // find average
            int avecount = 0;
            for (int k = i - 1, n = i + 2; k < n; k++)
            {
                if ((k > -1) && (k < height))
                {
                    for (int l = j - 1, m = j + 2; l < m; l++)
                    {
                        if ((j > -1) && (j < width))
                        {
                            avecount++;
                            temptrip.rgbtBlue += image[k][l].rgbtBlue;
                            temptrip.rgbtGreen += image[k][l].rgbtGreen;
                            temptrip.rgbtRed += image[k][l].rgbtRed;
                        }
                    }
                }
            }
            image[i][j].rgbtBlue = temptrip.rgbtBlue/avecount;
            image[i][j].rgbtGreen = temptrip.rgbtGreen/avecount;
            image[i][j].rgbtRed = temptrip.rgbtRed/avecount;

            printf("Blue[%i][%i] is %i, averagecount of %i\n",i ,j , image[i][j].rgbtBlue, avecount);
        }
/*
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
*/
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
