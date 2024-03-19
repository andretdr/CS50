#include "helpers.h"
#include <math.h>
#include <stdio.h>

RGBTRIPLE gxyfunction(int height, int width, int i, int j, RGBTRIPLE image[height][width]);

int cap(int n);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
        for (int j = 0, k = width; j < k; j++)
        {
            RGBTRIPLE temptrip = image[i][j];
            int temp = round((temptrip.rgbtBlue + temptrip.rgbtGreen + temptrip.rgbtRed)/3.0); // need to round this please

            image[i][j].rgbtBlue = temp;
            image[i][j].rgbtGreen = temp;
            image[i][j].rgbtRed = temp;
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
            // swap
            RGBTRIPLE temptrip = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temptrip;
            j++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float tempblue = 0;
            float tempgreen = 0;
            float tempred = 0;

            // find average
            int avecount = 0;
            for (int k = i - 1, n = i + 2; k < n; k++)
            {
                if ((k > -1) && (k < height))
                {
                    for (int l = j - 1, m = j + 2; l < m; l++)
                    {
                        if ((l > -1) && (l < width))
                        {
                            avecount++;
                            tempblue += image[k][l].rgbtBlue;
                            tempgreen += image[k][l].rgbtGreen;
                            tempred += image[k][l].rgbtRed;
                        }
                    }
                }
            }

            tempimage[i][j].rgbtBlue = round(tempblue / avecount);
            tempimage[i][j].rgbtGreen = round(tempgreen / avecount);
            tempimage[i][j].rgbtRed = round(tempred / avecount);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimage[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // find gx, fx
            RGBTRIPLE tempgxy = gxyfunction(height, width, i, j, image);
            tempimage[i][j] = tempgxy;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimage[i][j];
        }
    }

    return;
}

RGBTRIPLE gxyfunction(int height, int width, int i, int j, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    float tempxBlue = 0;
    float tempxGreen = 0;
    float tempxRed = 0;
    float tempyBlue = 0;
    float tempyGreen = 0;
    float tempyRed = 0;

    float gxmatrix[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    float gymatrix[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int k = 0; k < 3; k++)
    {
        int n = (i + k - 1);
        if ((n >= 0) && (n < height)) // if its not the edges
        {
            for (int l = 0; l < 3; l++)
            {
                int m = (j + l - 1);
                if ((m >= 0) && (m < width)) // if its not the edges
                {
                    tempxBlue += gxmatrix[k][l] * (float) image[n][m].rgbtBlue;
                    tempxGreen += gxmatrix[k][l] * (float) image[n][m].rgbtGreen;
                    tempxRed += gxmatrix[k][l] * (float) image[n][m].rgbtRed;

                    tempyBlue += gymatrix[k][l] * (float) image[n][m].rgbtBlue;
                    tempyGreen += gymatrix[k][l] * (float) image[n][m].rgbtGreen;
                    tempyRed += gymatrix[k][l] * (float) image[n][m].rgbtRed;
                }
            }
        }
    }
    temp.rgbtBlue = cap(round(sqrt(tempxBlue * tempxBlue + tempyBlue * tempyBlue)));
    temp.rgbtGreen = cap(round(sqrt(tempxGreen * tempxGreen + tempyGreen * tempyGreen)));
    temp.rgbtRed = cap(round(sqrt(tempxRed * tempxRed + tempyRed * tempyRed)));
    return temp;
}

int cap(int n)
{
    if (n > 255)
    {
        return 255;
    }
    else
    {
        return n;
    }
}
