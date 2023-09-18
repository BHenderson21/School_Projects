/** *********************************************************************
 * @file
 *
 * @brief  Prototypes
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/************************************************************************
 *             Constant Variables, defines and Enums
 ***********************************************************************/
#ifndef __NETPBM__H__
#define __ NETPBM__H__
typedef unsigned char pixel;

// Structure to hold all of the information for an image
struct image 
{ 
    string magicNumber; // Magic number denoting ascii or binary (P3 or P6) and if it is grayscale (P2 or P5)
    string comment; // Comments stored with the image
    int rows; // Number of rows of pixels
    int cols; // Number of columns of pixels
    pixel** redgray; // R values for pixels
    pixel** green; // G values for pixels
    pixel** blue; // B values for pixels
};

/************************************************************************
 *                         Function Prototypes
 ***********************************************************************/

bool openInput(ifstream& fin, string fileName);
bool openOutput(ofstream& fout, string fileName, string magicNumber);
void cleanUp(ifstream& fin, ofstream& fout);

void printUsage();
bool isValidOption(string option);

bool verifyCLA4(string type, string basename, string img);
bool verifyCLA5(string option, string type, string basename, string img);
bool verifyCLA6(string option, int b_int, string type, string basename, string img);

void readFile(ifstream& fin, image& image);
void makeFile(ofstream& fout, image image, string type);

void negateImage(image& image);
void brighten(image& image, int value);
void sharpen(image& image);
void smooth(image& image);
void grayscale(image& image);
void contrast(image& image);

void allocate2d(pixel**& ptr, int rows, int cols);
void free2d(pixel**& ptr, int rows);

#endif