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
            int a = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            float av = a / 3.0;
            int avg = round(av);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // printf("start : %d %d %d\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);

            // int originalRed = image[i][j].rgbtRed;
            // int originalGreen = image[i][j].rgbtGreen;
            // int originalBlue =  image[i][j].rgbtBlue;
            float Red = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);
            float Green = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            float Blue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);

            int sepiaRed = round(Red);
            int sepiaGreen = round(Green);
            int sepiaBlue = round(Blue);

            // printf("%f\n%f\n%f\n", sepiaRed, sepiaGreen, sepiaBlue);

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

            // if (image[i][j].rgbtRed > 255)
            // {
            //     image[i][j].rgbtRed = 255;
            // }
            // if (image[i][j].rgbtGreen > 255)
            // {
            //     image[i][j].rgbtGreen = 255;
            // }
            // if (image[i][j].rgbtBlue > 255)
            // {
            //     image[i][j].rgbtBlue = 255;
            // }
            // printf("end : %d %d %d\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width / 2; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int tempR = image[j][i].rgbtRed;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;
            image[j][width - i - 1].rgbtRed = tempR;

            int tempG = image[j][i].rgbtGreen;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][width - i - 1].rgbtGreen = tempG;

            int tempB = image[j][i].rgbtBlue;
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][width - i - 1].rgbtBlue = tempB;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float t, u, v;
    int r, g, b;
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int t1 = image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j].rgbtRed;
            int t2 = image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed;
            int t3 = image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed;
            t = (t1 + t2 + t3) / 9.0;
            r = round(t);
            image[i][j].rgbtRed = r;

            int u1 = image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j].rgbtGreen;
            int u2 = image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen;
            int u3 = image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen;
            u = (u1 + u2 + u3) / 9.0;
            g = round(u);
            image[i][j].rgbtGreen = g;

            int v1 = image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j].rgbtBlue;
            int v2 = image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue;
            int v3 = image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue;
            v = (v1 + v2 + v3) / 9.0;
            b = round(v);
            image[i][j].rgbtBlue = b;
        }

        // For last column
        t = (image[i][width - 1].rgbtRed + image[i + 1][width - 1].rgbtRed + image[i - 1][width - 1].rgbtRed +
             image[i][width - 2].rgbtRed + image[i + 1][width - 2].rgbtRed + image[i - 1][width - 2].rgbtRed) / 6.0;
        r = round(t);
        image[i][width - 1].rgbtRed = r;

        u = (image[i][width - 1].rgbtGreen + image[i + 1][width - 1].rgbtGreen + image[i - 1][width - 1].rgbtGreen +
             image[i][width - 2].rgbtGreen + image[i + 1][width - 2].rgbtGreen + image[i - 1][width - 2].rgbtGreen) / 6.0;
        g = round(u);
        image[i][width - 1].rgbtGreen = g;

        v = (image[i][width - 1].rgbtBlue + image[i + 1][width - 1].rgbtBlue + image[i - 1][width - 1].rgbtBlue +
             image[i][width - 2].rgbtBlue + image[i + 1][width - 2].rgbtBlue + image[i - 1][width - 2].rgbtBlue) / 6.0;
        b = round(v);
        image[i][width - 1].rgbtBlue = b;

        // for first column

        t = (image[i][0].rgbtRed + image[i + 1][0].rgbtRed + image[i - 1][0].rgbtRed +
             image[i][1].rgbtRed + image[i + 1][1].rgbtRed + image[i - 1][1].rgbtRed) / 6.0;
        r = round(t);
        image[i][0].rgbtRed = r;

        u = (image[i][0].rgbtGreen + image[i + 1][0].rgbtGreen + image[i - 1][0].rgbtGreen +
             image[i][1].rgbtGreen + image[i + 1][1].rgbtGreen + image[i - 1][1].rgbtGreen) / 6.0;
        g = round(u);
        image[i][0].rgbtGreen = g;

        v = (image[i][0].rgbtBlue + image[i + 1][0].rgbtBlue + image[i - 1][0].rgbtBlue +
             image[i][1].rgbtBlue + image[i + 1][1].rgbtBlue + image[i - 1][1].rgbtBlue) / 6.0;
        b = round(v);
        image[i][0].rgbtBlue = b;
    }

    for (int j = 1; j < width - 1; j++)
    {
        // For last row
        t = (image[height - 1][j].rgbtRed + image[height - 1][j + 1].rgbtRed + image[height - 1][j - 1].rgbtRed +
             image[height - 2][j].rgbtRed + image[height - 2][j + 1].rgbtRed + image[height - 2][j - 1].rgbtRed) / 6.0;
        r = round(t);
        image[height - 1][j].rgbtRed = r;

        u = (image[height - 1][j].rgbtGreen + image[height - 1][j + 1].rgbtGreen + image[height - 1][j - 1].rgbtGreen +
             image[height - 2][j].rgbtGreen + image[height - 2][j + 1].rgbtGreen + image[height - 2][j - 1].rgbtGreen) / 6.0;
        g = round(u);
        image[height - 1][j].rgbtGreen = g;

        v = (image[height - 1][j].rgbtBlue + image[height - 1][j + 1].rgbtBlue + image[height - 1][j - 1].rgbtBlue +
             image[height - 2][j].rgbtBlue + image[height - 2][j + 1].rgbtBlue + image[height - 2][j - 1].rgbtBlue) / 6.0;
        b = round(v);
        image[height - 1][j].rgbtBlue = b;

        // for first row
        t = (image[0][j].rgbtRed + image[0][j + 1].rgbtRed + image[0][j - 1].rgbtRed +
             image[1][j].rgbtRed + image[1][j + 1].rgbtRed + image[1][j - 1].rgbtRed) / 6.0;
        r = round(t);
        image[0][j].rgbtRed = r;

        u = (image[0][j].rgbtGreen + image[0][j + 1].rgbtGreen + image[0][j - 1].rgbtGreen +
             image[1][j].rgbtGreen + image[1][j + 1].rgbtGreen + image[1][j - 1].rgbtGreen) / 6.0;
        g = round(u);
        image[0][j].rgbtGreen = g;

        v = (image[0][j].rgbtBlue + image[0][j + 1].rgbtBlue + image[0][j - 1].rgbtBlue +
             image[1][j].rgbtBlue + image[1][j + 1].rgbtBlue + image[1][j - 1].rgbtBlue) / 6.0;
        b = round(v);
        image[0][j].rgbtBlue = b;
    }

    // for top left corner
    t = (image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][0].rgbtRed + image[1][1].rgbtRed) / 4.0;
    r = round(t);
    image[0][0].rgbtRed = r;

    u = (image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][0].rgbtGreen + + image[1][1].rgbtGreen) / 4.0;
    g = round(u);
    image[0][0].rgbtGreen = g;

    v = (image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / 4.0;
    b = round(v);
    image[0][0].rgbtBlue = b;

    // for top right corner
    t = (image[0][width - 1].rgbtRed + image[0][width - 2].rgbtRed + image[1][width - 1].rgbtRed + image[1][width - 2].rgbtRed) / 4.0;
    r = round(t);
    image[0][width - 1].rgbtRed = r;

    u = (image[0][width - 1].rgbtGreen + image[0][width - 2].rgbtGreen + image[1][width - 1].rgbtGreen +image[1][width - 2].rgbtGreen)/4.0;
    g = round(u);
    image[0][width - 1].rgbtGreen = g;

    v = (image[0][width - 1].rgbtBlue + image[0][width - 2].rgbtBlue + image[1][width - 1].rgbtBlue + image[1][width - 2].rgbtBlue) / 4.0;
    b = round(v);
    image[0][width - 1].rgbtBlue = b;

    //for bottom left corner
    t = (image[height - 1][0].rgbtRed + image[height - 1][1].rgbtRed + image[height - 2][0].rgbtRed + image[height - 2][1].rgbtRed) / 4.0;
    r = round(t);
    image[height - 1][0].rgbtRed = r;

    u = (image[height - 1][0].rgbtGreen + image[height - 1][1].rgbtGreen + image[height - 2][0].rgbtGreen + + image[height - 2][1].rgbtGreen) / 4.0;
    g = round(u);
    image[height - 1][0].rgbtGreen = g;

    v = (image[height - 1][0].rgbtBlue + image[height - 1][1].rgbtBlue + image[height - 2][0].rgbtBlue + image[height - 2][1].rgbtBlue) / 4.0;
    b = round(v);
    image[height - 1][0].rgbtBlue = b;

    //for bottom right corner
    t = (image[height - 1][width - 1].rgbtRed + image[height - 1][width - 2].rgbtRed + image[height - 2][width - 1].rgbtRed + image[height - 2][width - 2].rgbtRed) / 4.0;
    r = round(t);
    image[height - 1][width - 1].rgbtRed = r;

    u = (image[height - 1][width - 1].rgbtGreen + image[height - 1][width - 2].rgbtGreen + image[height - 2][width - 1].rgbtGreen + + image[height - 2][width - 2].rgbtGreen) / 4.0;
    g = round(u);
    image[height - 1][width - 1].rgbtGreen = g;

    v = (image[height - 1][width - 1].rgbtBlue + image[height - 1][width - 2].rgbtBlue + image[height - 2][width - 1].rgbtBlue + image[height - 2][width - 2].rgbtBlue) / 4.0;
    b = round(v);
    image[height - 1][width - 1].rgbtBlue = b;

    return;
}
