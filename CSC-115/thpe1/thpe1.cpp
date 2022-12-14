/** **************************************************************************************
* @file
*****************************************************************************************/
#include "thpe1.h"

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number, checks against rules
 *  for several credit card types to return the brand of the credit card.
 *
 *  @param[in] ccNumber String containing the credit card number check.
 *
 *  @returns A string containing the brand of credit card number
 *
 *  @par Example
 *  @verbatim
    
    string result;
 
    result = getCCType(343669144240775); // result would be American Express.
    
    result = getCCType(4794630503276178); // result would be Visa.
 
 *  @endverbatim
************************************************************************/

string getCCType(string ccNumber)
{
        if(isAmericanExpressCC(ccNumber))
        {
            return "American Express";
        }
        else if(isDiscoverCC(ccNumber))
        {
            return "Discover";
        }
        else if(isMastercardCC(ccNumber))
        {
            return "Mastercard";
        }
        else if(isVisaCC(ccNumber))
        {
            return "Visa";
        }
        else
        {
            return "Unknown";
        }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number, checks against rules
 *  for American Express cards, returning true or false.
 *
 *  @param[in] ccNumber String containing the credit card number check.
 *
 *  @returns A bool, true if the card is American Express, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = isAmericanExpressCC("343669144240775"); // result would be true.
    
    result = isAmericanExpressCC("341010101010"); // result would be false.
 
 *  @endverbatim
 ************************************************************************/

bool isAmericanExpressCC(string ccNumber)
{
    if(ccNumber.length() == 15)
    {
        if(ccNumber.substr(0,2) == "34" || ccNumber.substr(0,2) == "37")
        {
            return true;
        }
        else
        {
            return false;
        }   
    }
    else
    {
        return false;
    }
    
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number, checks against rules
 *  for Discover cards, returning true or false.
 *
 *  @param[in] ccNumber String containing the credit card number check.
 *
 *  @returns A bool, true if the card is Discover, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = isDiscoverCC("6440747636070782"); // result would be true.
    
    result = isDiscoverCC("62292612345678900"); // result would be false.
 
 *  @endverbatim
************************************************************************/

bool isDiscoverCC(string ccNumber)
{
    string firstTwo = (ccNumber.substr(0,2));
    string firstThree = (ccNumber.substr(0,3));
    string firstFour = (ccNumber.substr(0,4));
    string firstSix = (ccNumber.substr(0,6));
    int i = 622126;
    if(ccNumber.length() == 16)
    {
        if(firstTwo == "65")
        {
            return true;
        }
        else if(firstThree == "644" || firstThree == "649")
        {
            return true;
        }
        else if(firstFour == "6011")
        {
            return true;
        }
        else
        {
            while(i <= 622926)
            {
                if(i == stoi(firstSix))
                {
                    return true;
                }
                else
                {
                    i++;
                }
            }
            return false;
        }
    }
    else
        {
            return false;
        }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number, checks against rules
 *  for Mastercard cards, returning true or false.
 *
 *  @param[in] ccNumber String containing the credit card number check.
 *
 *  @returns A bool, true if the card is Mastercard, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = isMastercardCC("5385288768768674"); // result would be true.
    
    result = isMastercardCC("50123456789012345"); // result would be false.
 
 *  @endverbatim
************************************************************************/

bool isMastercardCC(string ccNumber)
{
    int startingDigits = 50;
    if(ccNumber.length() == 16)
    {
        while(startingDigits <= 55)
        {
            if(to_string(startingDigits) == ccNumber.substr(0,2))
            {
                return true;
            }
            else
            {
                startingDigits++;
            }
        }
        return false;
    }
    else
    {
        return false;
    }
}
    
/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number, checks against rules
 *  for Visa cards, returning true or false.
 *
 *  @param[in] ccNumber String containing the credit card number check.
 *
 *  @returns A bool, true if the card is Visa, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = isVisaCC("4794630503276178"); // result would be true.
    
    result = isVisaCC("3123412341234111"); // result would be false.
 
 *  @endverbatim
************************************************************************/
    
bool isVisaCC(string ccNumber)
{
    if(ccNumber.length() == 13 || ccNumber.length() == 16)
    {
        if(ccNumber.substr(0,1) == "4")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}



/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number, checks against rules
 *  for credit card number validity, checking that the length is valid,
 *  only digits are used, and Luhn's algorithm is passed.
 *
 *  @param[in] ccNumber String containing the credit card number check.
 *
 *  @returns A bool, true if the card number is valid, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = isValidCC("4716150722142577"); // result would be true.
    
    result = isValidCC("123451234512345"); // result would be false.
 
 *  @endverbatim
 ************************************************************************/



bool isValidCC(string ccNumber)
{
    int ccLength = ccNumber.length();
    if(isValidLength(ccLength) && isOnlyNumbers(ccNumber))
    {
        if(ccLength == 16)
        {
            if(luhns16(ccNumber))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(luhnsOdd(ccNumber))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a int containing a length of a credit card number, returns a bool
 *  depending on if the length is one of the 3 valid credit card number lengths,
 *  13, 15, or 16.
 *
 *  @param[in] length Int containing credit card number length.
 *
 *  @returns A bool, true if the card number length is valid, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = isValidLength("4716150722142577"); // result would be true.
    
    result = isValidLength("12345123451234512"); // result would be false.
 
 *  @endverbatim
 ************************************************************************/

bool isValidLength(int length)
{
    if(length == 16 || length == 13 || length == 15)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number, verifys that the number
 *  only contains digits.
 *
 *  @param[in] ccNumber String containing credit card number.
 *
 *  @returns A bool, true if the card number contains only digits, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = isOnlyNumbers("4716150722142577"); // result would be true.
    
    result = isOnlyNumbers("12345/3B123a12"); // result would be false.
 
 *  @endverbatim
 ************************************************************************/

bool isOnlyNumbers(string ccNumber)
{
    unsigned int i = 0;
    while(i <= (ccNumber.length()-1))
    {
        if(isdigit(ccNumber[i]))
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number of length 16, 
 *  verifys that the number passes Luhn's algorithm.
 *
 *  @param[in] ccNumber String containing credit card number.
 *
 *  @returns A bool, true if the card number passes Luhn's Algoithm, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = luhns16("4716150722142577"); // result would be true.
    
    result = luhns16("1234512345123451"); // result would be false.
 
 *  @endverbatim
 ************************************************************************/

bool luhns16(string ccNumber)
{
    int sumOfDigits = 0;
    int i = 0; 
    string overNine = "0";
    int overNineArray [2] = {0,0};
    
    while(i <= 15)
    {
        if(i%2 == 0)
        {
            if((2*(ccNumber[i]-48)) <= 9)
            {
                sumOfDigits = sumOfDigits + (2*(ccNumber[i]-48));
                i++;
            }
            else
            {
                overNine = to_string((2*(ccNumber[i]-48)));
                overNineArray[0] = overNine[0]-48;
                overNineArray[1] = overNine[1]-48;
                
                sumOfDigits = sumOfDigits + (overNineArray[0] + overNineArray[1]);
                i++;
            }
            
        }
        else
        {
            sumOfDigits = sumOfDigits + (ccNumber[i]-48);
            i++;
        }
    }
    if((sumOfDigits % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given a string containing a credit card number of odd length, 
 *  verifys that the number passes Luhn's algorithm.
 *
 *  @param[in] ccNumber String containing credit card number.
 *
 *  @returns A bool, true if the card number passes Luhn's Algoithm, otherwise false.
 *
 *  @par Example
 *  @verbatim
    
    bool result;
 
    result = luhnsOdd("7425473237792"); // result would be true.
    
    result = luhnsOdd("123451234512345"); // result would be false.
 
 *  @endverbatim
 ************************************************************************/

bool luhnsOdd(string ccNumber)
{
    int sumOfDigits = 0;
    int i = 0;
    int length = ((ccNumber.length()) - 1);
    string overNine = "0";
    int overNineArray [2] = {0,0};
    
    while(i <= length)
    {
        if(i%2 != 0)
        {
            if((2*(ccNumber[i]-48)) <= 9)
            {
                sumOfDigits = sumOfDigits + (2*(ccNumber[i]-48));
                i++;
            }
            else
            {
                overNine = to_string((2*(ccNumber[i]-48)));
                overNineArray[0] = overNine[0]-48;
                overNineArray[1] = overNine[1]-48;
                
                sumOfDigits = sumOfDigits + (overNineArray[0] + overNineArray[1]);
                i++;
            }
            
        }
        else
        {
            sumOfDigits = sumOfDigits + (ccNumber[i]-48);
            i++;
        }
    }
    if((sumOfDigits % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}