/** *********************************************************************
 * @file
 *
 * @brief Contains function main, bucketFill function, and function to
          check if pixels are already colored.
 ***********************************************************************/

 /** ********************************************************************
 *
 * @mainpage Program 2 - Flood Fill
 *
 * @section course_section Course Information
 *
 * @authors Brandon Henderson
 *
 * @date November 27, 2022
 *
 * @par Instructor:
 *         Roger Schrader
 *
 * @par Course:
 *         CSC 215 - Section M02 - 1:00 pm
 *
 * @par Location:
 *         CB - Room 205
 *
 * @section program_section Program Information
 *
 * @details This program will take a .ppm image formated as either
 *          an ascii or binary file.
 *
 *          It will read the file into an image structure
 *          containing a magic number, which indicates the format of the
 *          image data (ascii or binary, and wether or not it's grayscale),
 *          any comments that the .ppm file contains, the resolution of the
 *          image in rows and collumns, and three 2d arrays containing the
 *          individual RGB values for the pixels.
 *
 *          Next, based on the given pixel coordinates (row and column),
 *          and RGB value, the flood fill operation is performed at the
 *          given pixel coordinate, coloring all pixels adjascent to the
 *          input pixel that share it's color with the color that was input
 *          with the RGB value. 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      Stack Reserve Size must be set to 4,000,000,000
 *      Stack Commit Size must be set to 4,000,000,000
 *
 * @par Usage:
   @verbatim
   C:\> thpe03.exe imageFile row col redValue greenValue blueValue
        *imageFile   - A .ppm image
        *row         - The row of any pixel within the region you wish to flood fill
        *col         - The column of any pixel within the region you wish to flood fill
        *redValue    - The red channel of the RGB value you wish to fill with
        *greenValue  - The green channel of the RGB value you wish to fill with
        *blueValue   - The blue channel of the RGB value you wish to fill with
    
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications *
 *
 * @par Modifications and Development Timeline:

   Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/101077691/csc215f22programs/-/commits/main" target="_blank">
   Click Here.</a>
 *
 ***********************************************************************/

 /** *********************************************************************
  * @author Brandon Henderson
  *
  * @par Description:
  * This is the main function. It reads in the image, allocates a 2d used
  * array and populates it wiht 0s, opens the same file as an output, writes to it, 
  * then cleans up.
  *
  *
  * @param[in] argc - number of command line arguments
  *            argv - 2d array of characters containing the command line arguments.
  *
  * @returns none
  *
  * @par Example:
    @verbatim
    C:\> thpe03.exe imageFile row col redValue greenValue blueValue
        *imageFile   - A .ppm image
        *row         - The row of any pixel within the region you wish to flood fill
        *col         - The column of any pixel within the region you wish to flood fill
        *redValue    - The red channel of the RGB value you wish to fill with
        *greenValue  - The green channel of the RGB value you wish to fill with
        *blueValue   - The blue channel of the RGB value you wish to fill with
    @endverbatim

  ***********************************************************************/


#define CATCH_CONFIG_RUNNER

#include "..//catch.hpp"
#include "netPBM.h"

const bool runcatch = false;

// ARGV: thpe03.exe imageFile row col redValue greenValue blueValue
// ARGC: 0          1         2   3   4        5          6

int main(int argc, char** argv)
{
    if (runcatch)
    {
        Catch::Session session;
        int returnCode;
        returnCode = session.run(argc, argv);
        if (returnCode != 0)
        {
            cout << "A Test case failed" << endl;
        }
        return 0;
    }

    if (argc != 7)
    {
        cout << "Invalid Startup" << endl;
        printUsage();
    }

    RGB newRGB;
    string file = argv[1];
    int row = stoi(argv[2]);
    int col = stoi(argv[3]);
    newRGB.R = stoi(argv[4]);
    newRGB.G = stoi(argv[5]);
    newRGB.B = stoi(argv[6]);

    image image;
    string type;
    ifstream fin;
    ofstream fout;
    vector<bool> rowVec;
    vector<bool> colVec;
    bool** usedArray;

    if (!openInput(fin, file))
    {
        cout << "Could not open file: " << file << endl;
        return 0;
    }

    readFile(fin, image, type);
    allocateBool2d(usedArray, (image.rows), (image.cols));
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            usedArray[i][j] = 0;
        }
    }
    bucketFill(image, usedArray, row, col, newRGB);
    /*image.redgray[204][791] = 225;
    image.green[204][791] = 0;
    image.blue[204][791] = 0;
    image.redgray[205][790] = 0;
    image.green[205][790] = 0;
    image.blue[205][790] = 225;*/
    openOutput(fout, file);
    makeFile(fout, image, type);
    cleanUp(fin, fout);
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Prints the usage statement to the console.
 *
 * @returns none
 *
 * @par Example:
   @verbatim

   printUsage();

   C:\> thpe03.exe imageFile row col redValue greenValue blueValue
        *imageFile   - A .ppm image
        *row         - The row of any pixel within the region you wish to flood fill
        *col         - The column of any pixel within the region you wish to flood fill
        *redValue    - The red channel of the RGB value you wish to fill with
        *greenValue  - The green channel of the RGB value you wish to fill with
        *blueValue   - The blue channel of the RGB value you wish to fill with
   
   @endverbatim

 ***********************************************************************/


void printUsage()
{
    cout << "Usage: thpe03.exe imageFile row col redValue greenValue blueValue" << endl;
    cout << "   *imageFile: .ppm file" << endl;
    cout << "   *row: row of pixel where fill should be started" << endl;
    cout << "   *col: col of pixel where fill should be started" << endl;
    cout << "   *redValue: red element for RGB value to fill with" << endl;
    cout << "   *greenValue: green element for RGB value to fill with" << endl;
    cout << "   *blueValue: blue element for RGB value to fill with" << endl;
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Recursivley performs the flood fill function using the given command line arguments
 * for color and coordinate of pixel to start at. This is done by checking the four
 * surrounding pixels for each pixel to see if they also need colored. This is done
 * using the isColored function. For each pixel that isn't colored but should be, the
 * bucketFill function is called. This is done until all 4 surrounding pixels are colored,
 * at which time the pixel is colored and the function is returned from.
 *
 * @param[in] image - image structure to perform flood fill on 
 * @param[in] row - int containing the row of the pixel to be start at 
 * @param[in] col - int containing the col of the pixel to be start at 
 * @param[in] usedArray - 2d array of bools containing the pixels that have been colored 
 * @param[in] initRGB - RGB structure containing the color to flood fill with
 * 
 * @returns none
 *
 * @par Example:
   @verbatim

   image image;
   bool** usedArray;
   int row = 5;
   int col = 5;
   RGB newRGB;
   newRGB.R = 225;
   newRGB.G = 0;
   newRGB.B = 0;

   bucketFill(image, usedArray, row, col, newRGB);

   @endverbatim

 ***********************************************************************/

void bucketFill(image& image, bool** usedArray, int row, int col, RGB newRGB)
{
    RGB initRGB;
    initRGB.R = image.redgray[row][col];
    initRGB.G = image.green[row][col];
    initRGB.B = image.green[row][col];
    //cout << row << " " << col << endl;
    while (true)
    {
        if ((isColored(image, row + 1, col, usedArray, initRGB)) &&
            (isColored(image, row, col + 1, usedArray, initRGB)) &&
            (isColored(image, row - 1, col, usedArray, initRGB)) &&
            (isColored(image, row, col - 1, usedArray, initRGB)))
        {
            image.redgray[row][col] = newRGB.R;
            image.green[row][col] = newRGB.G;
            image.blue[row][col] = newRGB.B;
            return;
        }
        else
        {
            usedArray[row][col] = 1;
            if (!isColored(image, row + 1, col, usedArray, initRGB))
            {
                bucketFill(image, usedArray, row + 1, col, newRGB);
            }
            if (!isColored(image, row, col + 1, usedArray, initRGB))
            {
                bucketFill(image, usedArray, row, col + 1, newRGB);
            }
            if (!isColored(image, row - 1, col, usedArray, initRGB))
            {
                bucketFill(image, usedArray, row - 1, col, newRGB);
            }
            if (!isColored(image, row, col - 1, usedArray, initRGB))
            {
                bucketFill(image, usedArray, row, col - 1, newRGB);
            }
        }
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Checks to see if a pixel has been "colored", meaning accounted for. There are 3 criteria
 * under which a pixel can be considered accounted for. The first is if the pixel is outside
 * the bounds of the image, in which case the pixel can be ignored and the isColored function
 * returns true. The second is if the pixel is already a different color from the initial color.
 * The third is that it has already been marked in the used array. If none of these criteria are
 * met the function returns false.
 * 
 * @param[in] image - image structure containing the pixel to be checked 
 * @param[in] row - int containing the row of the pixel to be checked 
 * @param[in] col - int containing the col of the pixel to be checked 
 * @param[in] usedArray - 2d array of bools containing the pixels that have been colored 
 * @param[in] initRGB - RGB structure containing the color of the initial pixel
 * 
 *
 * @returns true  - if one of the above 3 criteria is met
 *          false - if none of the above 3 criteria is met
 *
 * @par Example:
   @verbatim

   image image;
   int row = 5;
   int col = 5;
   bool** usedArray;
   RGB newRGB;
   newRGB.R = 225;
   newRGB.G = 0;
   newRGB.B = 0;

   isColored(image, row, col, usedArray, initRGB);

   @endverbatim

 ***********************************************************************/

bool isColored(image image, int row, int col, bool** usedArray, RGB initRGB)
{
    if ((row < 0) || (row > image.rows) || (col < 0) || (col > image.cols))
    {
        return true;
    }
    else if (((image.redgray[row][col] != initRGB.R) ||
        (image.green[row][col] != initRGB.G) ||
        (image.blue[row][col] != initRGB.B)))
    {
        return true;
    }
    else
    {
        if (usedArray[row][col] == 1)
        {
            return true;
        }
    }
    return false;
}