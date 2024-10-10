#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int RGB_total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            int average = RGB_total / 3;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp_RGB = image[i][j];

            image[i][j] = image[i][width - j];
            image[i][width - j] = temp_RGB;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    #define BLUR_RADIUS 3

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_Red = 0;
            int total_Green = 0;
            int total_Blue = 0;

            int total_boxes = 0;

            for (int i_box = i - BLUR_RADIUS; i_box <= i + BLUR_RADIUS; i_box++)
            {
                if (i_box >= 0 && i_box <= height)
                {
                    for (int j_box = j - BLUR_RADIUS; j_box <= j + BLUR_RADIUS; j_box++)
                    {
                        if (j_box >= 0 && j_box <= width)
                        {
                            total_Red = total_Red + image[i_box][j_box].rgbtRed;
                            total_Green = total_Green + image[i_box][j_box].rgbtGreen;
                            total_Blue = total_Blue + image[i_box][j_box].rgbtBlue;

                            total_boxes++;
                        }
                    }
                }
            }
            image[i][j].rgbtRed = total_Red / total_boxes;
            image[i][j].rgbtGreen = total_Green / total_boxes;
            image[i][j].rgbtBlue = total_Blue / total_boxes;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE input_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            input_image[i][j] = image[i][j];
        }
    }

    int Gx_array[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_array[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate Gx and Gy per channel per pixel

            int y_scan = 0;
            int Gx_Red = 0;
            int Gx_Green = 0;
            int Gx_Blue = 0;
            int Gy_Red = 0;
            int Gy_Green = 0;
            int Gy_Blue = 0;

            for (int i_box = i - 1; i_box <= i + 1; i_box++)
            {
                if (i_box >= 0 && i_box <= height)
                {
                    int x_scan = 0;
                    for (int j_box = j - 1; j_box <= j + 1; j_box++)
                    {
                        if (j_box >= 0 && j_box <= width)
                        {
                            Gx_Red += (input_image[i_box][j_box].rgbtRed * Gx_array[y_scan][x_scan]);
                            Gx_Green += (input_image[i_box][j_box].rgbtGreen * Gx_array[y_scan][x_scan]);
                            Gx_Blue += (input_image[i_box][j_box].rgbtBlue * Gx_array[y_scan][x_scan]);

                            Gy_Red += (input_image[i_box][j_box].rgbtRed * Gy_array[y_scan][x_scan]);
                            Gy_Green += (input_image[i_box][j_box].rgbtGreen * Gy_array[y_scan][x_scan]);
                            Gy_Blue += (input_image[i_box][j_box].rgbtBlue * Gy_array[y_scan][x_scan]);
                        }
                        x_scan++;
                    }
                }
                y_scan++;
            }

            int total_Red = round(sqrt((Gx_Red * Gx_Red) + (Gy_Red * Gy_Red)));
            int total_Green = round(sqrt((Gx_Green * Gx_Green) + (Gy_Green * Gy_Green)));
            int total_Blue = round(sqrt((Gx_Blue * Gx_Blue) + (Gy_Blue * Gy_Blue)));

            if (total_Red > 255)
            {
                total_Red = 255;
            }
            if (total_Green > 255)
            {
                total_Green = 255;
            }
            if (total_Blue > 255)
            {
                total_Blue = 255;
            }

            image[i][j].rgbtRed = total_Red;
            image[i][j].rgbtGreen = total_Green;
            image[i][j].rgbtBlue = total_Blue;

        }
    }
    return;
}
