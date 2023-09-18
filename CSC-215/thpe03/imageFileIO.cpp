/** *********************************************************************
 * @file
 *
 * @brief Contains all functions handling file inputs and outputs
 ***********************************************************************/
#include "netPBM.h"

// *****IOSTREAM HANDLING

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an file stream and a file name, opens the file to the stream
 *
 *  @param[in] fin An input stream
 *             fileName A file name
 *
 *  @returns A bool, indicating if the file was successfully opened
 *
 *  @par Example
 *  @verbatim

    bool result;
    ifsteam fin;
    name = "test.txt";
    name2 = "test";

    result = openInput(fin, name); // result would be true

    result = openInput(fin, name2); // result would be false.


 *  @endverbatim
************************************************************************/
bool openInput(ifstream& fin, string fileName)
{
    fin.open(fileName, ios::in | ios::binary);
    if (!fin.is_open())
    {
        return false;
    }
    return true;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an file stream and a file name, opens the file to the stream
 *
 *  @param[in] fout An output stream
 *             fileName A file name
 *             option A string containing the option command line argument
 *
 *  @returns A bool, indicating if the file was successfully opened
 *
 *  @par Example
 *  @verbatim

    bool result;
    ofsteam fout;
    name = "test.txt";
    name2 = "test";

    result = openOutput(fin, name, "--grayscale"); // result would be true

    result = openOutput(fin, name2, "--bluescale"); // result would be false.


 *  @endverbatim
************************************************************************/

bool openOutput(ofstream& fout, string fileName)
{
    fout.open(fileName, ios::out | ios::binary);
    if (!fout.is_open())
    {
        return false;
    }
    return true;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an ifstream and an ofstream, closes both
 *
 *  @param[in] fin An input stream
 *             fout an output stream
 *
 *  @returns none
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    ofstream fout;

    cleanUp(fin, fout); - Closes both fin and fout

 *  @endverbatim
************************************************************************/

void cleanUp(ifstream& fin, ofstream& fout)
{
    fin.close();
    fout.close();
}
// *****END IOSTREAM HANDLING*****

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an input stream and an image structure, populates the structure
 *  using information from the file.
 *
 *  @param[in, out] fin - An input stream
 *                  image - an image structure
 *
 *  @returns A bool, indicating if the file was successfully opened
 *
 *  @par Example
 *  @verbatim

    bool result;
    ifstream fin;
    image image;

    readFile(fin, image); - Populates the given image structure
                            with the magic number, comments, 
                            resolution (rows and collumns), and 
                            pixel values from the file.

 *  @endverbatim
************************************************************************/

// *****READ FILE*****
void readFile(ifstream& fin, image& image, string& type)
{
    string temp;
    pixel tempPix;
    int i = 0;
    int j = 0;
    getline(fin, image.magicNumber);
    image.comment = "";
    while (fin.peek() == '#')
    {
        getline(fin, temp);
        image.comment.append(temp);
        image.comment.push_back('\n');
    }
    fin >> image.cols >> image.rows >> i;
    fin.ignore();
    //getline(fin, temp, ' ');
    //image.cols = stoi(temp);
    //getline(fin, temp);
    //image.rows = stoi(temp);
    //getline(fin, temp);
    allocate2d(image.redgray, image.rows, image.cols);
    allocate2d(image.green, image.rows, image.cols);
    allocate2d(image.blue, image.rows, image.cols);
    i = 0;
    if (image.magicNumber == "P6")
    {
        type = "--binary";
        temp = "";
        i = 0;
        while (i < image.rows)
        {
            j = 0;
            while (j < image.cols)
            {
                fin.read((char*) &tempPix, sizeof(pixel));
                image.redgray[i][j] = tempPix;
                fin.read((char*)&tempPix, sizeof(pixel));
                image.green[i][j] = tempPix;
                fin.read((char*) &tempPix, sizeof(pixel));
                image.blue[i][j] = tempPix;
                
                j++;
            }
            i++;
            j = 0;
        }
    }
    else if (image.magicNumber == "P3")
    {
        type = "--ascii";
        int r, g, b;
        while (i < image.rows)
        {
            while (j < image.cols)
            {
                fin >> r >> g >> b;
                image.redgray[i][j] = r;
                image.green[i][j] = g;
                image.blue[i][j] = b;

                //getline(fin, temp);
                //image.redgray[i][j] = stoi(temp);
                //getline(fin, temp);
                //image.green[i][j] = stoi(temp);
                //getline(fin, temp);
                //image.blue[i][j] = stoi(temp);
                j++;
            }
            i++;
            j = 0;
        }
    }
}
// *****END READ FILE*****

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an output stream and an image structure, populates the stream with the
 *  data from the image structure
 *
 *  @param[in, out] fout - An output stream
 *  @param[in]      image - an image structure
 *                  type - Output type, ascii or binary
 *                  
 *
 *  @returns none
 *
 *  @par Example
 *  @verbatim

    bool result;
    ifstream fin;
    image image;

    makeFile(fin, image); - Populates the given output stream
                            with the magic number, which is updated as needed,
                            comments, resolution (rows and collumns), and
                            pixel values from the image structure.

 *  @endverbatim
************************************************************************/

// *****MAKE FILE*****
void makeFile(ofstream& fout, image image, string type)
{
    int i = 0;
    int j = 0;

    
    if (type == "--ascii")
    {
        if (image.magicNumber == "P2" || image.magicNumber == "P5")
        {
            image.magicNumber = "P2";
        }
        else
        {
            image.magicNumber = "P3";
        }
        fout << image.magicNumber << '\n';
        fout << image.comment;
        fout << image.cols << " " << image.rows << '\n' << "255" << '\n';
        while (i < image.rows)
        {
            while (j < image.cols)
            {
                if (image.magicNumber == "P3")
                {
                    fout << int(image.redgray[i][j]) << " " 
                        << int(image.green[i][j])
                        << " " << int(image.blue[i][j])
                         << '\n';
                }
                else
                {
                    fout << int(image.redgray[i][j]) << endl;
                }
                j++;
            }
            i++;
            j = 0;
        }
    }
    else if (type == "--binary")
    {
        if (image.magicNumber == "P2" || image.magicNumber == "P5")
        {
            image.magicNumber = "P5";
        }
        else
        {
            image.magicNumber = "P6";
        }
        fout << image.magicNumber << '\n';
        fout << image.comment;
        fout << image.cols << " " << image.rows << '\n' << "255" << '\n';
        i = 0;
        while (i < image.rows)
        {
            j = 0;
            while (j < image.cols)
            {
                fout.write((char*)&image.redgray[i][j], sizeof(pixel));
                if (image.magicNumber == "P6")
                {
                    fout.write((char*)&image.green[i][j], sizeof(pixel));
                    fout.write((char*)&image.blue[i][j], sizeof(pixel));
                }
                j++;
            }
            i++;
            j = 0;
        }
    }
}
// *****END MAKE FILE*****