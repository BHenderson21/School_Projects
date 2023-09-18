/** *********************************************************************
 * @file
 *
 * @brief  Prototypes
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************
 *             Constant Variables, defines and Enums
 ***********************************************************************/
#ifndef __NETPBM__H__
#define __ NETPBM__H__
typedef unsigned char pixel;
/**
* @brief Structure to hold all of the information for an image
*/

struct image 
{ 
    string magicNumber; /**< Magic number denoting ascii or binary(P3 or P6) and if it is grayscale(P2 or P5) */
    string comment; /**< Comments stored with the image */
    int rows; /**< Number of rows of pixels */
    int cols; /**< Number of columns of pixels */
    pixel** redgray; /**< R values for pixels */
    pixel** green; /**< G values for pixels */
    pixel** blue; /**< B values for pixels */
};

/**
* @brief Structure to hold a RGB value
*/

struct RGB
{
    int R; /**< Red Value */
    int G; /**< Green Value */
    int B; /**< Blue Value */
};

/************************************************************************
 *                         Function Prototypes
 ***********************************************************************/

bool openInput(ifstream& fin, string fileName);
bool openOutput(ofstream& fout, string fileName);
void cleanUp(ifstream& fin, ofstream& fout);

void printUsage();
//bool isvalidoption(string option);

//bool verifyCLA4(string type, string basename, string img);
//bool verifyCLA5(string option, string type, string basename, string img);
//bool verifyCLA6(string option, int b_int, string type, string basename, string img);

void readFile(ifstream& fin, image& image, string& type);
void makeFile(ofstream& fout, image image, string type);

//void negateImage(image& image);
//void brighten(image& image, int value);
//void sharpen(image& image);
//void smooth(image& image);
//void grayscale(image& image);
//void contrast(image& image);
void bucketFill(image& image, bool** usedArray, int row, int col, RGB RGB);
bool isColored(image image, int row, int col, bool** usedArray, RGB initRGB);

void allocate2d(pixel**& ptr, int rows, int cols);
void allocateBool2d(bool**& ptr, int rows, int cols);
void free2d(pixel**& ptr, int rows);
void freeBool2d(bool**& ptr, int rows);

#endif