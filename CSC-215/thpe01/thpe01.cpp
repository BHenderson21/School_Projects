/** *********************************************************************
 * @file
 *
 * @brief Contains function main, and functions to verify
 *        the command line arguments given.
 ***********************************************************************/

 /** ********************************************************************
 *
 * @mainpage Program 1 - Image Manipulation
 *
 * @section course_section Course Information
 *
 * @authors Brandon Henderson
 *
 * @date October 17, 2022
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
 *          containing a magic number, which indicated the format of the
 *          image data (ascii or binary, and wether or not it's grayscale),
 *          any comments that the .ppm file contains, the resolution of the
 *          image in rows and collumns, and three 2d arrays containing the
 *          individual RGB values for the pixels.
 *
 *          Next, the image will be written back out to a new file, formatted as
 *          either ascii or binary based on a command line argument given. If
 *          a command line argument was given to perform an operation on the image,
 *          (negate, brighten, sharpen, smooth, grayscale, contrast), the correct
 *          operation is performed before the image is output to a new file of the name
 *          given by a command line argument.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   C:\> thpe01.exe [option] --outputtype basename image.ppm
    Output Type
        --ascii
            * pixel values will be written in text form
        --binary
            * pixel values will be written in binary form
    Option Code
        --negate
            * Negates the colors of the image
        --brighten # (# is an integer value between -255 and 255)
            * Brigtens or dims the image by amount #. A positive
              value for # will brighten the image, whereas a
              negative value will dim the image.
        --sharpen
            * Sharpens the image. This is done by subtracting
              neighboring pixels from each pixel multiplied by 5.
            * The image's border pixels are ignored and set to black.
        --smooth
            * Smooths the image. This is done by averaging each pixel's
              value with the 8 pixels surrounding it.
            * The image's border pixels are ignored and set to black.
        --grayscale
            * Makes the image grayscale.
        --contrast
            * Makes the image grayscale and increases the contrast.
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug  Currently the auto-grader is docing me on my grayscale, contrast,
 *       sharpen, and smooth. I can not figure out why. If I had to guess it
 *       must be some rounding error.
 * @bug  There is clearly something I don't understand about clearing 2d arrays.
 *       I have the function written, but each time i call it i get an error. Will
 *       talk to Roger.
 *
 *
 * @par Modifications and Development Timeline:

   Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/101077691/csc215f22programs/-/commits/main" target="_blank">
   Click Here.</a>
 *
 ***********************************************************************/
#define CATCH_CONFIG_RUNNER

#include "..\\catch.hpp"
#include "netPBM.h"

const bool runcatch = false;

// argv: thpe01.exe [option] --outputtype basename image.ppm

// *****MAIN*****
/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This is the main function. It first checks if the 4-6 command
 * line arguments given are valid. Then, it reads the given image file,
 * applys the operation given, then outputs the file.
 *
 *
 * @param[in] argc - number of command line arguments
 *            argv - 2d array of characters containing the command line arguments.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   C:\> thpe01.exe [option] --outputtype basename image.ppm
    Output Type
        --ascii pixel values will be written in text form
        --binary pixel values will be written in binary form
    Option Code
        --negate
        --brighten #
        --sharpen
        --smooth
        --grayscale
        --contrast
   @endverbatim

 ***********************************************************************/
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

    ifstream fin;
    ofstream fout;
    string option = "";
    string type = "";
    image image;


    if (argc == 4)
    {
        if (verifyCLA4(argv[1], argv[2], argv[3]))
        {
            if (!openInput(fin, argv[3]))
            {
                cout << "Unable to open file: " << argv[3] << endl;
                exit(0);
            }
            if (!openOutput(fout, argv[2], ""))
            {
                cout << "Unable to open file: " << argv[2] << endl;
                exit(0);
            }
            type = argv[1];
        }
        else
        {
            exit(0);
        }
    }
    else if (argc == 5)
    {
        if (verifyCLA5(argv[1], argv[2], argv[3], argv[4]))
        {
            if (!openInput(fin, argv[4]))
            {
                cout << "Unable to open file: " << argv[4] << endl;
                exit(0);
            }
            if (!openOutput(fout, argv[3], argv[1]))
            {
                cout << "Unable to open file: " << argv[3] << endl;
                exit(0);
            }
            option = argv[1];
            type = argv[2];
        }
        else
        {
            exit(0);
        }
    }
    else if (argc == 6)
    {
        if (verifyCLA6(argv[1], stoi(argv[2]), argv[3], argv[4], argv[5]))
        {
            if (!openInput(fin, argv[5]))
            {
                cout << "Unable to open file: " << argv[4] << endl;
                exit(0);
            }
            if (!openOutput(fout, argv[4], argv[1]))
            {
                cout << "Unable to open file: " << argv[3] << endl;
                exit(0);
            }
            option = argv[1];
            type = argv[3];
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        if (argv[1] == "--binary" || argv[1] == "--ascii")
        {
            cout << "Invalid Option" << endl;
            printUsage();
            return 0;
        }
        else
        {
            cout << "Invalid Startup" << endl;
            printUsage();
            return 0;
        }
    }

    readFile(fin, image);
    if (option == "--negate")
    {
        negateImage(image);
    }
    else if (option == "--brighten")
    {
        brighten(image, stoi(argv[2]));
    }
    else if (option == "--sharpen")
    {
        sharpen(image);
    }
    else if (option == "--smooth")
    {
        smooth(image);
    }
    else if (option == "--grayscale")
    {
        grayscale(image);
    }
    else if (option == "--contrast")
    {
        contrast(image);
    }

    makeFile(fout, image, type);
    cleanUp(fin, fout);
    return 0;
}
// *****END MAIN*****



// *****PRINTUSAGE*****
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

   C:\> thpe01.exe [option] --outputtype basename image.ppm
    Output Type
        --ascii pixel values will be written in text form
        --binary pixel values will be written in binary form
    Option Code
        --negate
        --brighten #
        --sharpen
        --smooth
        --grayscale
        --contrast
   @endverbatim

 ***********************************************************************/
void printUsage()
{
    cout << "thpe01.exe [option] --outputtype basename image.ppm" << endl;
    cout << endl;
    cout << "Output Type" << endl;
    cout << "       --ascii  pixel values will be written in text form"
        << endl;
    cout << "       --binary pixel values will be written in binary form"
        << endl;
    cout << endl;
    cout << "Option Code" << endl;
    cout << "       --negate" << endl;
    cout << "       --brighten #" << endl;
    cout << "       --sharpen" << endl;
    cout << "       --smooth" << endl;
    cout << "       --grayscale" << endl;
    cout << "       --contrast" << endl;
}
// *****END PRINTUSAGE*****



// *****CLA HANDLINH*****
/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Verifys the validity of the operation option given.
 *
 *
 * @param[in] option - Operation option provided.
 *
 * @returns True if the option provided is a member of the options allowed
 *          False if the option provided is not a member of the options allowed
 *
 * @par Example:
   @verbatim
   isValidOption("--negate") - Returns true
   isValidOption("--begate") - Returns false
   @endverbatim

 ***********************************************************************/
bool isValidOption(string option)
{
    if (option == "--negate" || option == "--brighten" || option == "--sharpen"
        || option == "--smooth" || option == "--grayscale" || option == "--contrast")
    {
        return true;
    }
    return false;
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This function verifys the validity of the command line arguments given
 * if 4 are provided (the first being the name of the program, not checked)
 *
 *
 * @param[in] type - The output type, should be either "--ascii" or "--binary"
 *            basename - Name to be used for output file.
 *            img - Name of input image. File extension should be .ppm
 *
 * @returns True if the CLA's are valid
 *          False otherwise
 *
 * @par Example:
   @verbatim
   verifyCLA4("-ascii", "test", "img.ppm"); - Returns true
   verifyCLA4("--asci", "test", "image.ppm"); - Returns false
   verifyCLA4("--ascii", "test", "image.png"); - Returns false
   @endverbatim

 ***********************************************************************/

bool verifyCLA4(string type, string basename, string img)
{
    if (type == "--ascii" || type == "--binary")
    {
        if (img.substr(img.size() - 4, 4) == ".ppm")
        {
            return true;
        }
        else
        {
            cout << "Invalid Image" << endl;
            printUsage();
            return false;
        }
    }
    else
    {
        cout << "Invalid Option" << endl;
        printUsage();
        return false;
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This function verifys the validity of the command line arguments given
 * if 5 are provided (the first being the name of the program, not checked)
 *
 *
 * @param[in] option - The operation option. This sent to isValidOption.
 *            type - The output type, should be either "--ascii" or "--binary"
 *            basename - Name to be used for output file.
 *            img - Name of input image. File extension should be .ppm
 *
 * @returns True if the CLA's are valid
 *          False otherwise
 *
 * @par Example:
   @verbatim
   verifyCLA4("negate", "-ascii", "test", "img.ppm"); - Returns true
   verifyCLA4("negate", "--asci", "test", "image.ppm"); - Returns false
   verifyCLA4("negate", "--ascii", "test", "image.png"); - Returns false
   verifyCLA4("--begate", "--ascii", "test", "image.png"); - Returns false
   @endverbatim

 ***********************************************************************/

bool verifyCLA5(string option, string type, string basename, string img)
{
    if (isValidOption(option))
    {
        if (type == "--ascii" || type == "--binary")
        {
            if (img.substr(img.size() - 4, 4) == ".ppm")
            {
                return true;
            }
            else
            {
                cout << "Invalid Image" << endl;
                printUsage();
                return false;
            }
        }
        else
        {
            cout << "Invalid Option" << endl;
            printUsage();
            return false;
        }
    }
    else
    {
        cout << "Invalid Option" << endl;
        printUsage();
        return false;
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This function verifys the validity of the command line arguments given
 * if 6 are provided (the first being the name of the program, not checked)
 *
 *
 * @param[in] option - The operation option MUST be brighten if there ar 6 CLAs.
 *            b_int - Must be between -255 and 255.
 *            type - The output type, should be either "--ascii" or "--binary"
 *            basename - Name to be used for output file.
 *            img - Name of input image. File extension should be .ppm
 *
 * @returns True if the CLA's are valid
 *          False otherwise
 *
 * @par Example:
   @verbatim
   verifyCLA4("brighten", 27, "-ascii", "test", "img.ppm"); - Returns true
   verifyCLA4("brighten", 27, "--asci", "test", "image.ppm"); - Returns false
   verifyCLA4("brighten", 27, "--ascii", "test", "image.png"); - Returns false
   verifyCLA4("brighten", 270, "--ascii", "test", "image.png"); - Returns false
   verifyCLA4("--brigten", 27, "--ascii", "test", "image.png"); - Returns false
   @endverbatim

 ***********************************************************************/

bool verifyCLA6(string option, int b_int, string type, string basename, string img)
{
    if (isValidOption(option))
    {
        if (type == "--ascii" || type == "--binary")
        {
            if (img.substr(img.size() - 4, 4) == ".ppm")
            {
                return true;
            }
            else
            {
                cout << "Invalid Image" << endl;
                printUsage();
                return false;
            }
        }
        else
        {
            cout << "Invalid Option" << endl;
            printUsage();
            return false;
        }
    }
    else
    {
        cout << "Invalid Option" << endl;
        printUsage();
        return false;
    }
}
// *****END CLA HANDLING*****