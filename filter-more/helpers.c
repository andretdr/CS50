#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
        for (int j = 0, k = width; j < k; j++)
        {
            RGBTRIPLE *temptrip = &image[i][j];
            BYTE temp = (*temptrip.rgbtBlue + *temptrip.rgbtGreen + *temptrip.rgbtBlue)/3; // need to round this please
     //       temptrip.rgbtBlue = temp;
     //       temptrip.rgbtGreen = temp;
     //       temptrip.rgbtRed = temp;
        }





    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
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
