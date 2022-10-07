/** **************************************************************************************
* @file
*****************************************************************************************/
#include "thpe2.h"

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double, returns the doubles square root within .000000000001
 *
 *  @param[in] sqrtNum Double containing number to take the square root of
 *
 *  @returns A double containing the square root of the number
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = mySqrt(25); // result would be 5.
    
    result = mySqrt(10); // result would be 3.16227766.
 
 *  @endverbatim
************************************************************************/

double mySqrt(double sqrtNum)
{
    double low = 0;
    double high;
    double mid = 0;
    int i = 0;
    
    if(sqrtNum < 1)
    {
        high = 1;
    }
    else
    {
        high = sqrtNum;
    }
    
    if(sqrtNum <= 0)
    {
        return 0;
    }
    else
    {
        while(i < ITERATIONMAX)
        {
            mid = (low + high)/2;
            if((abs(pow(mid, 2)-sqrtNum)) < ERRORVALUE)
            {
                return mid;
            }
            else
            {
                if(pow(mid, 2) < sqrtNum)
                {
                    low = mid;
                    i++;
                }
                else
                {
                    high = mid;
                    i++;
                }
            }
            
        }
        return mid;
    }

}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double, returns the doubles cube root within .000000000001
 *
 *  @param[in] cbrtNum Double containing number to take the cube root of
 *
 *  @returns A double containing the cube root of the number
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = mySqrt(125); // result would be 5.
    
    result = mySqrt(10); // result would be 2.15443469.
 
 *  @endverbatim
************************************************************************/

double myCbrt(double cbrtNum)
{
    double low = 0;
    double high;
    double mid = 0;
    int i = 0;
    
    if(cbrtNum < 1)
    {
        high = 1;
    }
    else
    {
        high = cbrtNum;
    }
    
    if(cbrtNum <= 0)
    {
        return 0;
    }
    else
    {
        while(i < ITERATIONMAX)
        {
            mid = (low + high)/2;
            if((abs(pow(mid, 3)-cbrtNum)) < ERRORVALUE)
            {
                return mid;
            }
            else
            {
                if(pow(mid, 3) < cbrtNum)
                {
                    low = mid;
                    i++;
                }
                else
                {
                    high = mid;
                    i++;
                }
            }
            
        }
        return mid;
    }

}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double, logNum, and an int, base, returns the log base 'base' of logNum
 *
 *  @param[in] logNum Double containing number to take the log root of
 *  @param[in] base Int containing base of the logarithm
 *
 *  @returns A double containing the log calculated with the proper base and input
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = myLog(1, 1); // result would be 1.
    
    result = myLog(100, 10); // result would be 2.
 
 *  @endverbatim
************************************************************************/

double myLog(double logNum, int base)
{
    double low = 0;
    double high = 1;
    double mid = 0;
    int i = 0;
    bool highHighEnough = false;
    
    if(logNum == base)
    {
        return 1;
    }
   
    
    while(!highHighEnough)
    {
        if((pow(base, high)) < logNum)
        {
            high++;
        }
        else
        {
            low = high - 1;
            highHighEnough = true;
        }
    }
    
    while(i < ITERATIONMAX)
        {
            mid = (low + high)/2;
            if((abs(pow(base, mid)-logNum)) < ERRORVALUE)
            {
                return mid;
            }
            else
            {
                if(pow(base, mid) < logNum)
                {
                    low = mid;
                    i++;
                }
                else
                {
                    high = mid;
                    i++;
                }
            }
            
        }
        return mid;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double measuring an angle in radians, returns the sin of the value within .000001.
 *
 *  @param[in] rads Double containing angle to take the sin of in radians.
 *
 *  @returns A double containing the sin of the inputted value
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = mySin(PI); // result would be 0 plus or minus .000001.
    
    result = mySin(PI/2); // result would be 1 plus or minus .000001.
 
 *  @endverbatim
************************************************************************/

double mySin(double rads)
{
    int i = 0;
    double sinValue = 0;
    while(i < TERMS)
    {
        sinValue = sinValue + (pow(-1, i) * (pow(rads,((2*i)+1))) / (factorial((2*i)+1)));
        i++;
    }
    return sinValue;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double measuring an angle in degrees, returns the sin of the value within .000001.
 *
 *  @param[in] rads Double containing angle to take the sin of in degrees.
 *
 *  @returns A double containing the sin of the inputted value
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = mySinD(180); // result would be 0 plus or minus .000001.
    
    result = mySinD(90); // result would be 1 plus or minus .000001.
 
 *  @endverbatim
************************************************************************/

double mySinD(double degs)
{
    double rads = ((degs/180)*PI);
    int i = 0;
    double sinValue = 0;
    while(i < TERMS)
    {
        sinValue = sinValue + (pow(-1, i) * (pow(rads,((2*i)+1))) / (factorial((2*i)+1)));
        i++;
    }
    return sinValue;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double measuring an angle in radians, returns the cos of the value within .000001.
 *
 *  @param[in] rads Double containing angle to take the cos of in radians.
 *
 *  @returns A double containing the cos of the inputted value
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = myCos(PI); // result would be 1 plus or minus .000001.
    
    result = myCos(PI/2); // result would be 0 plus or minus .000001.
 
 *  @endverbatim
************************************************************************/

double myCos(double rads)
{
    int i = 0;
    double cosValue = 0;
    while(i < TERMS)
    {
        cosValue = cosValue + (pow(-1, i) * (pow(rads,((2*i)))) / (factorial((2*i))));
        i++;
    }
    return cosValue;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double measuring an angle in degrees, returns the cos of the value within .000001.
 *
 *  @param[in] rads Double containing angle to take the cos of in degrees.
 *
 *  @returns A double containing the cos of the inputted value
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = myCosD(180); // result would be 1 plus or minus .000001.
    
    result = myCosD(90); // result would be 0 plus or minus .000001.
 
 *  @endverbatim
************************************************************************/

double myCosD(double degs)
{
    double rads = ((degs/180)*PI);
    int i = 0;
    double cosValue = 0;
    while(i < TERMS)
    {
        cosValue = cosValue + ((pow(-1, i)) * ((pow(rads, 2*i))/(factorial((2*i)))));
        i++;
    }
    return cosValue;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double measuring an angle in radians, returns the tan of the value within .000001.
 *
 *  @param[in] rads Double containing angle to take the tan of in radians.
 *
 *  @returns A double containing the tan of the inputted value
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = myTan(PI); // result would be 0 plus or minus .000001.
    
    result = myTan(PI/4); // result would be 1 plus or minus .000001.
 
 *  @endverbatim
************************************************************************/

double myTan(double rads)
{
    double tanValue = (mySin(rads)/myCos(rads));
    return tanValue;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a double measuring an angle in degrees, returns the tan of the value within .000001.
 *
 *  @param[in] rads Double containing angle to take the tan of in degrees.
 *
 *  @returns A double containing the tan of the inputted value
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = myTanD(180); // result would be 0 plus or minus .000001.
    
    result = myTanD(45); // result would be 1 plus or minus .000001.
 
 *  @endverbatim
************************************************************************/

double myTanD(double degs)
{
    double tanValue = (mySinD(degs)/myCosD(degs));
    return tanValue;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an double, calculates and returns the numbers factorial.
 *
 *  @param[in] x double containing the number for which to take the factorial.
 *
 *  @returns A double containing the factorial of the input.
 *
 *  @par Example
 *  @verbatim
    
    double result;
 
    result = factorial(6); // result would be 720.
    
    result = factorial(4); // result would be 24.
 
 *  @endverbatim
************************************************************************/

double factorial(double x)
{
    int i = 1;
    double total = 1;
    while(i <= x)
    {
        total = total * i;
        i++;
    }
    return total;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an destination array, a source array, and the size of both, will copy
 *  the source arrays contents to the destination array
 *
 *  @param[in] destination[] Array to copy TO.
 *  @param[in] source[] Array to copy FROM.
 *  @param[in] size Int containing size of both arrays.
 *
 *  @returns Nothing.
 *
 *  @par Example
 *  @verbatim
    
    double destination[3];
    double source[3] = {1, 2, 3};
    
    copyArray(destination, source, 3); // destination would now read {1, 2 ,3}
 
 *  @endverbatim
************************************************************************/

void copyArray(double destination[], double source[], int size)
{
    int i = 0;
    while(i < size)
    {
        destination[i] = source[i];
        i++;
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array, a value to initialize, and the size of both, will
 *  initialize each element of the array to the value.
 *
 *  @param[in] arrayToInit[] Array to initialize.
 *  @param[in] initValue Double containing value to initialize array to.
 *  @param[in] size Int containing size of array.
 *
 *  @returns Nothing.
 *
 *  @par Example
 *  @verbatim
    
    double initArray[3];
    double initValue = 5;
    
    initialArray(initArray, initValue, 3); // destination would now read {5, 5, 5}
 
 *  @endverbatim
************************************************************************/

void initialArray(double arrayToInit[], int size, double initValue)
{
    int i = 0;
    while(i < size)
    {
        arrayToInit[i] = initValue;
        i++;
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array and its size, returns the sum of all values in the array.
 *
 *  @param[in] arrayToSum[] Array to sum.
 *  @param[in] size Int containing size of array.
 *
 *  @returns Sum of array terms
 *
 *  @par Example
 *  @verbatim
    
    double arrayToSum[3] = {1, 2, 3};
    double initValue = 3;
    
    result = sumArray(arrayToSum, size); // result would be 6.
 
 *  @endverbatim
************************************************************************/

double sumArray(double arrayToSum[], int size)
{
    double sum = 0;
    int i = 0;
    while(i < size)
    {
        sum += arrayToSum[i];
        i++;
    }
    return sum;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array and its size, returns the average of all values in the array.
 *
 *  @param[in] arrayToSum[] Array to average.
 *  @param[in] size Int containing size of array.
 *
 *  @returns Average of array terms
 *
 *  @par Example
 *  @verbatim
    
    double arrayToAverage[3] = {1, 2, 3};
    
    result = averageArray(arrayToAverage, 3); // result would be 3.
 
 *  @endverbatim
************************************************************************/

double averageArray(double arrayToAverage[], int size)
{
    double sum = 0;
    double average = 0;
    int i = 0;
    while(i < size)
    {
        sum += arrayToAverage[i];
        i++;
    }
    average = (sum/size);
    return average;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array and its size, returns the index of the largest value.
 *
 *  @param[in] arrayToSum[] Array to find max of.
 *  @param[in] size Int containing size of array.
 *
 *  @returns Index of largest term in the array.
 *
 *  @par Example
 *  @verbatim
    
    double array[5] = {1, 2, 3, 10, 4};
    
    result = maxLocation(array, 5); // result would be 3.
 
 *  @endverbatim
************************************************************************/

int maxLocation(double array[], int size)
{
    int maxIndex = 0;
    int i = 0;
    while(i < size)
    {
        if(array[i] > array[maxIndex])
        {
            maxIndex = i;
            i++;
        }
        else
        {
            i++;
        }
    }
    return maxIndex;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array and its size, returns the largest value.
 *
 *  @param[in] arrayToSum[] Array to find max of.
 *  @param[in] size Int containing size of array.
 *
 *  @returns Largest term in the array.
 *
 *  @par Example
 *  @verbatim
    
    double array[5] = {1, 2, 3, 10, 4};
    
    result = maxValue(array, 5); // result would be 10.
 
 *  @endverbatim
************************************************************************/

double maxValue(double array[], int size)
{
    int index = maxLocation(array, size);
    return array[index];
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array and its size, returns the index of the smallest value.
 *
 *  @param[in] arrayToSum[] Array to find min of.
 *  @param[in] size Int containing size of array.
 *
 *  @returns Index of smallest term in the array.
 *
 *  @par Example
 *  @verbatim
    
    double array[5] = {1, 2, 3, 10, 4};
    
    result = minLocation(array, 5); // result would be 0.
 
 *  @endverbatim
************************************************************************/

int minLocation(double array[], int size)
{
    int minIndex = 0;
    int i = 0;
    while(i < size)
    {
        if(array[i] < array[minIndex])
        {
            minIndex = i;
            i++;
        }
        else
        {
            i++;
        }
    }
    return minIndex;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array and its size, returns the smallest value.
 *
 *  @param[in] arrayToSum[] Array to find min of.
 *  @param[in] size Int containing size of array.
 *
 *  @returns smallest term in the array.
 *
 *  @par Example
 *  @verbatim
    
    double array[5] = {1, 2, 3, 10, 4};
    
    result = minValue(array, 5); // result would be 1.
 
 *  @endverbatim
************************************************************************/

double minValue(double array[], int size)
{
    int index = minLocation(array, size);
    return array[index];
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array, its size, and a term to count, returns number of occurances.
 *
 *  @param[in] array[] Array to count term in.
 *  @param[in] size Int containing size of array.
 *  @param[in] termToCount double containing term to count occurances of.
 *
 *  @returns number of occurances of indicated term.
 *
 *  @par Example
 *  @verbatim
    
    double array[8] = {1, 2, 3, 10, 4, 1, 5, 1};
    
    result = minValue(array, 8, 1); // result would be 3.
 
 *  @endverbatim
************************************************************************/

int countIf(double array[], int size, double termToCount)
{
    int count = 0;
    int i = 0;
    while(i < size)
    {
        if(array[i] == termToCount)
        {
            count++;
        }
        i++;
    }
    return count;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array, its size, and a string indicating ascending or descending order, sorts the array.
 *
 *  @param[in] array[] Array to count term in.
 *  @param[in] size Int containing size of array.
 *  @param[in] tASCorDSC String containing ASC or DSC, indicating ascending or descending.
 *
 *  @returns Nothing
 *
 *  @par Example
 *  @verbatim
    
    double array[8] = {1, 2, 3, 10, 4, 1, 5, 1};
    
    mySort(array, 8, ASC); // array would be {1, 1, 1, 2, 3, 4, 5, 10}
    mySort(array, 8, DSC); // array would be {10, 5, 4, 3, 2, 1, 1, 1}
    
 *  @endverbatim
************************************************************************/

void mySort(double array[], int size, string ASCorDSC)
{
    if(ASCorDSC == "ASC")
    {
        int i, j;
        int currentMin;
        for(i=0; i < size-1; i++)
        {
            currentMin = i;
            for(j=i+1; j<size; j++)
            {
                if(array[j] < array[currentMin])
                {
                    currentMin = j;
                }
            }
            swap(array[i], array[currentMin]);
        }
    }
    else if(ASCorDSC == "DSC")
    {
       int i, j;
        int currentMax;
        for(i=0; i < size-1; i++)
        {
            currentMax = i;
            for(j=i+1; j<size; j++)
            {
                if(array[j] > array[currentMax])
                {
                    currentMax = j;
                }
            }
            swap(array[i], array[currentMax]);
        }
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array, its size, and a term to find, searches for and returns the index of term if found.
 *
 *  @param[in] array[] Array to count term in.
 *  @param[in] size Int containing size of array.
 *  @param[in] termToCount double containing term to find.
 *
 *  @returns -1 if term isnt found, index of where the term is found, if it is.
 *
 *  @par Example
 *  @verbatim
    
    double array[8] = {1, 2, 3, 10, 4, 1, 5, 1};
    
    result = linearSearch(array, 8, 10); // result would be 3.
    result = linearSearch(array, 8, 9); // result would be -1.
 
 *  @endverbatim
************************************************************************/

int linearSearch(double array[], int size, double termToFind)
{
    int i = 0;
    while(i < size)
    {
        if(array[i] == termToFind)
        {
            return(i);
        }
        i++;
    }
    return(-1);
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array, its size, and a term to find, searches for and returns the index of term if found.
 *
 *  @param[in] array[] Array to count term in.
 *  @param[in] size Int containing size of array.
 *  @param[in] termToCount double containing term to find.
 *
 *  @returns -1 if term isnt found, index of where the term is found, if it is.
 *
 *  @par Example
 *  @verbatim
    
    double array[8] = {1, 2, 3, 10, 4, 1, 5, 1};
    
    result = binarySearch(array, 8, 10); // result would be 3.
    result = binarySearch(array, 8, 9); // result would be -1.
 
 *  @endverbatim
************************************************************************/

int binarySearch(double array[], int size, double termToFind)
{
    int low = 0;
    int high = (size-1);
    int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(array[mid] == termToFind)
        {
            return mid;
        }
        else if(array[mid] > termToFind)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return(-1);
}

