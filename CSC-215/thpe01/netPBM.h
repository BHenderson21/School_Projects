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
struct image 
{ 
    string magicNumber;
    string comment;
    int rows;
    int cols;
    pixel** redgray; 
    pixel** green;
    pixel** blue;
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