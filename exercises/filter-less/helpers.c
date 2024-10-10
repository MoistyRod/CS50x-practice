#include "helpers.h"

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            int sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            int sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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
                        if (j_box >= 0 && j <= width)
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
