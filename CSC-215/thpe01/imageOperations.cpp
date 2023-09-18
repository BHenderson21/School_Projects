/** *********************************************************************
 * @file
 *
 * @brief Contains all functions for applying operations to images
 ***********************************************************************/
#include "netPBM.h"
/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Negates the colors of the image given by subtracting each pixel RGB value
 * from 255.
 *
 *
 * @param[in] image - image structure to be negated.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   image image;
   negateImage(image);
   @endverbatim

 ***********************************************************************/
void negateImage(image& image)
{
    int i = 0;
    int j = 0;
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            image.redgray[i][j] = 255 - image.redgray[i][j];
            image.green[i][j] = 255 - image.green[i][j];
            image.blue[i][j] = 255 - image.blue[i][j];
            j++;
        }
        i++;
        j = 0;
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Brightens (or dims) the image by an amount provided by adding
 * the provided value to each pixel value, insuring no values exceed
 * the range of 0-255.
 *
 *
 * @param[in] image - image structure to be brightened.
 *            value - int value to be used to brighten/dim.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   image image;
   value = 25;
   brighten(image, value); - Increased each rgb value by 25.
   value = -25;
   brighten(image, value); - Decreased each rgb value by 25.
   @endverbatim

 ***********************************************************************/

void brighten(image& image, int value)
{
    int i = 0;
    int j = 0;
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            if (image.redgray[i][j] + value >= 255)
            {
                image.redgray[i][j] = 255;
            }
            else if ((image.redgray[i][j] + value) <= 0)
            {
                image.redgray[i][j] = 0;
            }
            else
            {
                image.redgray[i][j] = image.redgray[i][j] + value;
            }

            if (image.green[i][j] + value > 255)
            {
                image.green[i][j] = 255;
            }
            else if ((image.green[i][j] + value) <= 0)
            {
                image.green[i][j] = 0;
            }
            else
            {
                image.green[i][j] = image.green[i][j] + value;
            }

            if (image.blue[i][j] + value > 255)
            {
                image.blue[i][j] = 255;
            }
            else if ((image.blue[i][j] + value) <= 0)
            {
                image.blue[i][j] = 0;
            }
            else
            {
                image.blue[i][j] = image.blue[i][j] + value;
            }
            j++;
        }
        i++;
        j = 0;
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Sharpens the image by multiplying each pixel by
 * 5 and subtracting the values in the surrounding 4 pixels
 * (not diagonal). Ignores border pixels, setting them to black.
 *
 *
 * @param[in] image - image structure to be sharpened.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   image image;
   sharpen(image);
   @endverbatim

 ***********************************************************************/

void sharpen(image& image)
{
    int i = 0;
    int j = 0;
    pixel** tempred;
    pixel** tempblue;
    pixel** tempgreen;
    allocate2d(tempred, image.rows, image.cols);
    allocate2d(tempblue, image.rows, image.cols);
    allocate2d(tempgreen, image.rows, image.cols);
    int newRed = 0;
    int newGreen = 0;
    int newBlue = 0;
    i = 1;
    while (i < image.rows-1)
    {
        j = 1;
        while (j < image.cols-1)
        {            
            //if (i == 0 || i == image.rows-1 || j == 0 || j == image.cols-1)
            //{
            //    tempred[i][j] = 0;
            //    tempgreen[i][j] = 0;
            //    tempblue[i][j] = 0;
            //}
            //else
            //{
                newRed = (     5 * int(image.redgray[i][j])        ) - 
                         int(image.redgray[i + 1][j]) - 
                         int(image.redgray[i][j - 1]) - 
                         int(image.redgray[i - 1][j]) - 
                         int(image.redgray[i][j + 1]);

                newGreen = (5 * int(image.green[i][j]) ) - 
                         int(image.green[i + 1][j]) - 
                         int(image.green[i][j - 1]) - 
                         int(image.green[i - 1][j]) - 
                         int(image.green[i][j + 1]);
                
                newBlue = (5 * int(image.blue[i][j])) - 
                         int(image.blue[i + 1][j]) - 
                         int(image.blue[i][j - 1]) - 
                         int(image.blue[i - 1][j]) - 
                         int(image.blue[i][j + 1]);
                if (newRed >= 255)
                {
                    tempred[i][j] = 255;
                }
                else if (newRed <= 0)
                {
                    tempred[i][j] = 0;
                }
                else
                {
                    tempred[i][j] = newRed;
                }
            
                if (newGreen >= 255)
                {
                    tempgreen[i][j] = 255;
                }
                else if (newGreen <= 0)
                {
                    tempgreen[i][j] = 0;
                }
                else
                {
                    tempgreen[i][j] = newGreen;
                }
                
                if (newBlue >= 255)
                {
                    tempblue[i][j] = 255;
                }
                else if (newBlue <= 0)
                {
                    tempblue[i][j] = 0;
                }
                else
                {
                    tempblue[i][j] = newBlue;
                }
            //}
            j++;
        }
        i++;
     
    }
    swap(image.redgray, tempred);
    swap(image.green, tempgreen);
    swap(image.blue, tempblue);

    /*
    i = 0;
    j = 0;
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            image.redgray[i][j] = tempred[i][j];
            image.blue[i][j] = tempblue[i][j];
            image.green[i][j] = tempgreen[i][j];
            j++;
        }
        i++;
        j = 0;
    }
    */
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Smooths the image by multiplying each pixel by
 * averaging each pixel with all 8 surrounding pixels.
 * Ignores border pixels, setting them to black.
 *
 *
 * @param[in] image - image structure to be smoothed.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   image image;
   smooth(image);
   @endverbatim

 ***********************************************************************/

void smooth(image& image)
{
    int i = 0;
    int j = 0;
    pixel** tempred;
    pixel** tempblue;
    pixel** tempgreen;
    allocate2d(tempred, image.rows, image.cols);
    allocate2d(tempblue, image.rows, image.cols);
    allocate2d(tempgreen, image.rows, image.cols);
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            if (i == 0 || i == image.rows - 1 || j == 0 || j == image.cols - 1)
            {
                tempred[i][j] = 0;
                tempgreen[i][j] = 0;
                tempblue[i][j] = 0;
            }
            else
            {
                tempred[i][j] = int((int(image.redgray[i+1][j-1]) + int(image.redgray[i+1][j]) + int(image.redgray[i+1][j-1]) + int(image.redgray[i][j-1]) + int(image.redgray[i][j]) + int(image.redgray[i][j+1]) + int(image.redgray[i-1][j-1]) + int(image.redgray[i-1][j]) + int(image.redgray[i-1][j+1])) /9);
                tempgreen[i][j] = int((int(image.green[i + 1][j - 1]) + int(image.green[i + 1][j]) + int(image.green[i + 1][j - 1]) + int(image.green[i][j - 1]) + int(image.green[i][j]) + int(image.green[i][j + 1]) + int(image.green[i - 1][j - 1]) + int(image.green[i - 1][j]) + int(image.green[i - 1][j + 1])) / 9);
                tempblue[i][j] = int((int(image.blue[i + 1][j - 1]) + int(image.blue[i + 1][j]) + int(image.blue[i + 1][j - 1]) + int(image.blue[i][j - 1]) + int(image.blue[i][j]) + int(image.blue[i][j + 1]) + int(image.blue[i - 1][j - 1]) + int(image.blue[i - 1][j]) + int(image.blue[i - 1][j + 1])) / 9);
            }
            j++;
        }
        i++;
        j = 0;
    }
    i = 0;
    j = 0;
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            image.redgray[i][j] = tempred[i][j];
            image.blue[i][j] = tempblue[i][j];
            image.green[i][j] = tempgreen[i][j];
            j++;
        }
        i++;
        j = 0;
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Makes the image grayscale by applying a formula (seen below)
 * to each pixel and storing them in a single array.
 * Formula - (0.3 * R) + (0.6 * G) + (0.1 * B)
 *
 * @param[in] image - image structure to be made grayscale.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   image image;
   grayscale(image);
   @endverbatim

 ***********************************************************************/

void grayscale(image& image)
{
    int i = 0;
    int j = 0;
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            image.redgray[i][j] = int((.3 * int(image.redgray[i][j])) + (.6 * int(image.green[i][j])) + (.1 * int(image.blue[i][j])));
            j++;
        }
        i++;
        j = 0;
    }
    if (image.magicNumber == "P3")
    {
        image.magicNumber = "P2";
    }
    else
    {
        image.magicNumber = "P5";
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Makes the image grayscale using the function above, and increases the contrast
 * by finding the maximum and minimum pixel values and applying the formula below
 * to each pixel
 * 
 * Formula - scale = 255/(max-min)
 *           pixel = scale * (pixel - min)
 *
 * @param[in] image - image structure to be made grayscale and contrasted.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   image image;
   contrast(image);
   @endverbatim
 ***********************************************************************/

void contrast(image& image)
{
    grayscale(image);
    int min = image.redgray[0][0];
    int max = image.redgray[0][0];
    int i = 0;
    int j = 0;
    double scale = 0;
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            if (image.redgray[i][j] > max)
            {
                max = image.redgray[i][j];
            }
            if (image.redgray[i][j] < min)
            {
                min = image.redgray[i][j];
            }
            j++;
        }
        i++;
        j = 0;
    }
    scale = 255.0 / (max-min);
    i = 0;
    j = 0;
    while (i < image.rows)
    {
        while (j < image.cols)
        {
            image.redgray[i][j] = int((scale * (image.redgray[i][j] - min)));
            j++;
        }
        i++;
        j = 0;
    }
}
