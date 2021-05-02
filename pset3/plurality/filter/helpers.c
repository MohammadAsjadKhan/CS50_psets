#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   for (int i = 0; i < height; i++)
   {
       for (int j = 0; j < width; j++)
       {
           image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen )/3.00);
           image[i][j].rgbtGreen = image[i][j].rgbtBlue;
           image[i][j].rgbtRed = image[i][j].rgbtBlue;
       }
   }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE tmp = image[i][j];

            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    float count = 0.00;
    int Blue, Green, Red;
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Blue = 0;
            Red = 0;
            Green = 0;
            count = 0.00;

            for (int k = -1; k < 2; k++ )
            {
                if (k + i < 0 || k + i >= height )
                {
                    continue;
                }
                for (int h = -1; h < 2; h++)
                {
                    if (h + j < 0 || h + j >= width )
                    {
                        continue;
                    }
                    Blue+= image[i + k][j + h].rgbtBlue ;
                    Red+= image[i + k][j + h].rgbtRed ;
                    Green+= image[i + k][j + h].rgbtGreen;
                    count++;

                }
            }
            tmp[i][j].rgbtBlue = round(Blue/count) ;
            tmp[i][j].rgbtRed = round(Red/count) ;
            tmp[i][j].rgbtGreen = round(Green/count);

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           image[i][j] = tmp[i][j];
        }

    }
    return;
}

// stops max value at 255 preventing overflow
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    float count = 0.00;
    int x_Blue, x_Green, x_Red, y_Blue, y_Green, y_Red;
    RGBTRIPLE tmp[height][width];
    int Gx[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
    int Gy[3][3] = {{-1,-2,-1}, {0,0,0}, {1,2,1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            x_Blue = 0;
            x_Red = 0;
            x_Green = 0;
            y_Blue = 0;
            y_Red = 0;
            y_Green = 0;
            count = 0.00;

            for (int k = -1; k < 2; k++ )
            {
                if (k + i < 0 || k + i >= height )
                {
                    continue;
                }
                for (int h = -1; h < 2; h++)
                {
                    if (h + j < 0 || h + j >= width )
                    {
                        continue;
                    }
                    x_Blue+= image[i + k][j + h].rgbtBlue*(Gx[k+1][h+1]) ;
                    x_Red+= image[i + k][j + h].rgbtRed*(Gx[k+1][h+1]) ;
                    x_Green+= image[i + k][j + h].rgbtGreen*(Gx[k+1][h+1]);

                    y_Blue+= image[i + k][j + h].rgbtBlue*(Gy[k+1][h+1]) ;
                    y_Red+= image[i + k][j + h].rgbtRed*(Gy[k+1][h+1]) ;
                    y_Green+= image[i + k][j + h].rgbtGreen*(Gy[k+1][h+1]);
                    count++;

                }
            }
            tmp[i][j].rgbtBlue = limit(round(sqrt(x_Blue*x_Blue + y_Blue*y_Blue))) ;
            tmp[i][j].rgbtRed = limit(round(sqrt(x_Red*x_Red + y_Red*y_Red))) ;
            tmp[i][j].rgbtGreen = limit(round(sqrt(x_Green*x_Green + y_Green*y_Green)));

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           image[i][j] = tmp[i][j];
        }

    }
    return;
}
