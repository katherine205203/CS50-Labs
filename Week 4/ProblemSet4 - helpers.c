#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.000);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create another image array to store reflected values
    RGBTRIPLE reflectedimage[height][width];

    // Reflected image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            reflectedimage[i][j] = image[i][width - 1 - j];
        }
    }

    // Copy to normal array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = reflectedimage[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create another image array to store blurred values
    RGBTRIPLE blurredimage[height][width];

    // Average value of surrounding cells
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int sumred = 0, sumgreen = 0, sumblue = 0, squaresum = 0;

            for (int row = (i - 1) ; row <= (i + 1) ; row++)
            {
                for (int column = (j - 1) ; column <= (j + 1) ; column++)
                {
                    // If trying to get value for non-existent pixel, skip
                    if (row == -1 || row == height || column == -1 || column == width)
                    {
                        continue;
                    }
                    sumred += image[row][column].rgbtRed;
                    sumgreen += image[row][column].rgbtGreen;
                    sumblue += image[row][column].rgbtBlue;

                    squaresum++;
                }
            }

            blurredimage[i][j].rgbtRed = round(sumred / (float)squaresum);
            blurredimage[i][j].rgbtGreen = round(sumgreen / (float)squaresum);
            blurredimage[i][j].rgbtBlue = round(sumblue / (float)squaresum);
        }
    }

    // Copy blurred image array to normal image array
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = blurredimage[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        int Red;
        int Blue;
        int Green;
    }
    temp;
    temp image2[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float GxR = 0;
            float GyR = 0;
            float GxG = 0;
            float GyG = 0;
            float GxB = 0;
            float GyB = 0;

            // 2
            if (i != 0)
            {
                GyR += (-2 * image[i - 1][j].rgbtRed);
                GyB += (-2 * image[i - 1][j].rgbtBlue);
                GyG += (-2 * image[i - 1][j].rgbtGreen);
            }

            //4
            if (j != 0)
            {
                GxR += (-2 * image[i][j - 1].rgbtRed);
                GxB += (-2 * image[i][j - 1].rgbtBlue);
                GxG += (-2 * image[i][j - 1].rgbtGreen);
            }

            //7
            if (i != (height - 1))
            {
                GyR += (2 * image[i + 1][j].rgbtRed);
                GyB += (2 * image[i + 1][j].rgbtBlue);
                GyG += (2 * image[i + 1][j].rgbtGreen);
            }

            //5
            if (j != (width - 1))
            {
                GxR += (2 * image[i][j + 1].rgbtRed);
                GxB += (2 * image[i][j + 1].rgbtBlue);
                GxG += (2 * image[i][j + 1].rgbtGreen);
            }

            //1
            if ((i != 0) && (j != 0))
            {
                GxR += (-1 * image[i - 1][j - 1].rgbtRed);
                GxB += (-1 * image[i - 1][j - 1].rgbtBlue);
                GxG += (-1 * image[i - 1][j - 1].rgbtGreen);
                GyR += (-1 * image[i - 1][j - 1].rgbtRed);
                GyB += (-1 * image[i - 1][j - 1].rgbtBlue);
                GyG += (-1 * image[i - 1][j - 1].rgbtGreen);
            }

            //3
            if ((i != 0) && (j != (width - 1)))
            {
                GxR += image[i - 1][j + 1].rgbtRed;
                GxB += image[i - 1][j + 1].rgbtBlue;
                GxG += image[i - 1][j + 1].rgbtGreen;
                GyR += (-1 * image[i - 1][j + 1].rgbtRed);
                GyB += (-1 * image[i - 1][j + 1].rgbtBlue);
                GyG += (-1 * image[i - 1][j + 1].rgbtGreen);
            }

            //6
            if ((i != (height - 1)) && (j != 0))
            {
                GxR += (-1 * image[i + 1][j - 1].rgbtRed);
                GxB += (-1 * image[i + 1][j - 1].rgbtBlue);
                GxG += (-1 * image[i + 1][j - 1].rgbtGreen);
                GyR += image[i + 1][j - 1].rgbtRed;
                GyB += image[i + 1][j - 1].rgbtBlue;
                GyG += image[i + 1][j - 1].rgbtGreen;
            }

            //8
            if ((i != (height - 1)) && (j != (width - 1)))
            {
                GxR += image[i + 1][j + 1].rgbtRed;
                GxB += image[i + 1][j + 1].rgbtBlue;
                GxG += image[i + 1][j + 1].rgbtGreen;
                GyR += image[i + 1][j + 1].rgbtRed;
                GyB += image[i + 1][j + 1].rgbtBlue;
                GyG += image[i + 1][j + 1].rgbtGreen;
            }
            float SobelR = sqrt((GxR * GxR) + (GyR * GyR));
            float SobelB = sqrt((GxB * GxB) + (GyB * GyB));
            float SobelG = sqrt((GxG * GxG) + (GyG * GyG));
            image2[i][j].Red = round(SobelR);
            image2[i][j].Blue = round(SobelB);
            image2[i][j].Green = round(SobelG);

            if (image2[i][j].Red > 255)
            {
                image2[i][j].Red = 255;
            }
            if (image2[i][j].Blue > 255)
            {
                image2[i][j].Blue = 255;
            }
            if (image2[i][j].Green > 255)
            {
                image2[i][j].Green = 255;
            }
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image2[i][j].Red;
            image[i][j].rgbtBlue = image2[i][j].Blue;
            image[i][j].rgbtGreen = image2[i][j].Green;
        }
    }

    return;
}
