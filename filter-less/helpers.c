#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int greyscale =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtBlue = greyscale;
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
            int ogRed = image[i][j].rgbtRed;
            int ogGreen = image[i][j].rgbtGreen;
            int ogBlue = image[i][j].rgbtBlue;

            float sepiaRed = 0.393 * ogRed + 0.769 * ogGreen + 0.189 * ogBlue;
            float sepiaGreen = 0.349 * ogRed + 0.686 * ogGreen + 0.168 * ogBlue;
            float sepiaBlue = 0.272 * ogRed + 0.534 * ogGreen + 0.131 * ogBlue;

            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);

            sepiaRed = (sepiaRed > 255) ? 255 : sepiaRed;
            sepiaGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            sepiaBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Intial parameters value
            float red = 0;
            float green = 0;
            float blue = 0;
            float divisor = 0.0;

            // Iterate over 3x3 neighborhood
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    // Check if the neighbor pixel is within the image bounds
                    if (i + x >= 0 && i + x < height && j + y >= 0 && j + y < width)
                    {
                        red += image[i + x][j + y].rgbtRed;
                        green += image[i + x][j + y].rgbtGreen;
                        blue += image[i + x][j + y].rgbtBlue;
                        divisor += 1.0;
                    }
                }
            }
            temp[i][j].rgbtRed = round((red / divisor));
            temp[i][j].rgbtGreen = round((green / divisor));
            temp[i][j].rgbtBlue = round((blue / divisor));
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
