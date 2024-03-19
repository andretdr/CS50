#include "helpers.h"
#include <stdio.h>
#include <math.h>

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
  //                          printf("originalimageBlue[%i][%i] is %i\n",k ,l , image[k][l].rgbtBlue);
                        }
                    }
                }
            }

            image[i][j].rgbtBlue = round(tempblue/avecount);
            image[i][j].rgbtGreen = round(tempgreen/avecount);
            image[i][j].rgbtRed = round(tempred/avecount);
    //        printf("averageBlue[%i][%i] is %i, totalBlue is %i, averagecount of %i\n",i ,j , image[i][j].rgbtBlue, (int)tempblue, avecount);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
for (int i = 0; i < height; i++)
 {
        for (int j = 0; j < width; j++)
        {
            // find gx, fx
            RGBTRIPLE tempgx = gxfunction(height, width, i, j, image);
            RGBTRIPLE tempgy = gyfunction(height, width, i, j, image);

            printf("gx values %i %i %i", tempgx.rgbtBlue, tempgx.rgbtGreen, tempgx.rgbtRed);


//            RGBTRIPLE tempgy = gyfunction(height, width, i, j, image);

//            image[i][j].rgbtBlue = round(tempblue/avecount);
//            image[i][j].rgbtGreen = round(tempgreen/avecount);
//            image[i][j].rgbtRed = round(tempred/avecount);
    //        printf("averageBlue[%i][%i] is %i, totalBlue is %i, averagecount of %i\n",i ,j , image[i][j].rgbtBlue, (int)tempblue, avecount);
        }
    }
    return;
}

RGBTRIPLE gxyfunction(int height, int width, int i, int j, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    int tempxBlue = 0;
    int tempxGreen = 0;
    int tempxRed = 0;
    int tempyBlue = 0;
    int tempyGreen = 0;
    int tempyRed = 0;

    int gxmatrix[3][3] = {{-1, 0, 1}, {-2, 0 , 2}, {-1, 0, 1}};
    int gymatrix[3][3] = {{-1, -2, -1}, {0, 0 , 0}, {1, 2, 1}};


    for (int k = 0; k < 3; k++)
    {
        int n = (i + k - 1);
        if ((n > 0) && (n < height)) // if its not the edges
        {
            for (int l = 0; l < 3; l++)
            {
                int m = (j + l - 1);
                if ((m > 0) && (m < width)) // if its not the edges
                {
                    tempxBlue += gxmatrix[k][l] * image[n][m].rgbtBlue;
                    tempxGreen += gxmatrix[k][l] * image[n][m].rgbtGreen;
                    tempxRed += gxmatrix[k][l] * image[n][m].rgbtRed;

                    tempyBlue += gymatrix[k][l] * image[n][m].rgbtBlue;
                    tempyGreen += gymatrix[k][l] * image[n][m].rgbtGreen;
                    tempyRed += gymatrix[k][l] * image[n][m].rgbtRed;
  //                printf("originalimageBlue[%i][%i] is %i\n",k ,l , image[k][l].rgbtBlue);
                }
            }
        }
    }

    temp.rgbtBlue = round(sqrt(tempxBlue*tempxBlue + tempyBlue*tempyBlue));
    temp.rgbtGreen = round(sqrt(tempxGreen*tempxGreen + tempyGreen*tempyGreen));
    temp.rgbtRed = round(sqrt(tempxRed*tempxRed + tempyRed*tempyRed));


    return temp;
}
