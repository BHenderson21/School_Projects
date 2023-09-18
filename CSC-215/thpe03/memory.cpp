/** *********************************************************************
 * @file
 *
 * @brief Contains memory allocation for 2d arrays
 ***********************************************************************/
#include "netPBM.h"

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This function allocates 2d arrays for pixels, given the pixel to be a pointer
 * to the array and the rows and collumns required
 *
 *
 * @param[in] ptr - pixel** used as a pointer to the 2d array
 *            rows - Number of rows needed
 *            cols - Number of collumns needed.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   pixel** red;
   int rows = 5;
   int cols = 5;
   allocate2d(red, rows, cols);
   @endverbatim

 ***********************************************************************/

void allocate2d(pixel**& ptr, int rows, int cols)
{
    int i = 0;
    ptr = new (nothrow) pixel*[rows];
    if (ptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        exit(0);
    }

    while (i <= rows)
    {
        ptr[i] = new (nothrow) pixel[cols];
        if (ptr[i] == nullptr)
        {
            cout << "Memory Allocation Error" << endl;
            exit(0);
        }
        i++;
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This function frees up memory from dynamically allocated 2d arrays.
 *
 *
 * @param[in] ptr - pixel** used as a pointer to the 2d array
 *            rows - Number of rows present in array to free.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   pixel** red;
   int rows = 5;
   int cols = 5;
   free2d(red, rows);
   @endverbatim

 ***********************************************************************/

void free2d(pixel**& ptr, int rows)
{
    int i = 0;
    if (ptr == nullptr)
    {
        return;
    }

    while (i < rows)
    {
        delete[] ptr[i];
        i++;
    }        
    delete[] ptr;
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This function allocates 2d arrays for bools, given the bool to be a pointer
 * to the array and the rows and collumns required
 *
 *
 * @param[in] ptr - bool** used as a pointer to the 2d array
 * @param[in] rows - Number of rows needed
 * @param[in] cols - Number of collumns needed.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   bool** usedArray;
   int rows = 5;
   int cols = 5;
   allocateBool2d(usedArray, rows, cols);
   @endverbatim

 ***********************************************************************/

void allocateBool2d(bool**& ptr, int rows, int cols)
{
    int i = 0;
    ptr = new (nothrow) bool*[rows];
    if (ptr == nullptr)
    {
        cout << "Memory Allocation Error" << endl;
        exit(0);
    }

    while (i <= rows)
    {
        ptr[i] = new (nothrow) bool[cols];
        if (ptr[i] == nullptr)
        {
            cout << "Memory Allocation Error" << endl;
            exit(0);
        }
        i++;
    }
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * This function frees up memory from dynamically allocated 2d arrays of bools.
 *
 *
 * @param[in] ptr - bool** used as a pointer to the 2d array
 * @param[in] rows - Number of rows present in array to free.
 *
 * @returns none
 *
 * @par Example:
   @verbatim
   bool** usedArray;
   int rows = 5;
   int cols = 5;
   freeBool2d(usedArray, rows);
   @endverbatim

 ***********************************************************************/

void freeBool2d(bool**& ptr, int rows)
{
    int i = 0;
    if (ptr == nullptr)
    {
        return;
    }

    while (i < rows)
    {
        delete[] ptr[i];
        i++;
    }
    delete[] ptr;
}