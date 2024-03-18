#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
        for (int j = 0, k = width; j < k; j++)
        {
            BYTES temp = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtBlue)
            rgbtBlue
            rgbtGreen
            rgbtRed

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
