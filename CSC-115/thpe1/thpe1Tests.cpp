#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe1.h"

//************************************************
// Test cases for getCCType function
//************************************************

TEST_CASE("getCCType - first test case, testing for an unknown number")
{
    string number = "120339393389330409";
    string ccType = getCCType(number);
    
    REQUIRE(ccType == "Unknown");    
}

TEST_CASE("getCCType - Testing getCCType function, expecting American Express")
{
    string number = "343669144240775";
    string ccType = getCCType(number);
    
    REQUIRE(ccType == "American Express");  
}

TEST_CASE("getCCType - Testing getCCType function, expecting Discover")
{
    string number = "6440747636070782";
    string ccType = getCCType(number);
    
    REQUIRE(ccType == "Discover");  
}

TEST_CASE("getCCType - Testing getCCType function, expecting Mastercard")
{
    string number = "5385288768768674";
    string ccType = getCCType(number);
    
    REQUIRE(ccType == "Mastercard");  
}

TEST_CASE("getCCType - Testing getCCType function, expecting Visa")
{
    string number = "4794630503276178";
    string ccType = getCCType(number);
    
    REQUIRE(ccType == "Visa");  
}

TEST_CASE("getCCType - Testing getCCType function, expecting Unknowns")
{
    string number = "7425473237792";
    string ccType = getCCType(number);
    
    REQUIRE(ccType == "Unknown");  
}

//************************************************
// Test cases for isAmericanExpressCC function
//************************************************

TEST_CASE("isAmericanExpressCC - first test case for isAmericanExpressCC. Input should be too long. Expecting false.")
{
    string number = "3410101010101010101001010";
    bool isAmEx = isAmericanExpressCC(number);
    
    REQUIRE(isAmEx == false);    
}

TEST_CASE("isAmericanExpressCC - second test case for isAmericanExpressCC. Input is right length, but starts with the wrong characters. Expecting false.")
{
    string number = "310000000000000";
    bool isAmEx = isAmericanExpressCC(number);
    
    REQUIRE(isAmEx == false);    
}

TEST_CASE("isAmericanExpressCC - Testing a valid american express cc number")
{
    string number = "343669144240775";
    bool isAmEx = isAmericanExpressCC(number);
    
    REQUIRE(isAmEx == true);    
}

//************************************************
// Test cases for isDiscoverCC function
//************************************************

TEST_CASE("isDiscoverCC - Testing a cc number with the right start, expecting true.")
{
    string number = "6229261234567890";
    bool isDisCC = isDiscoverCC(number);
    
    REQUIRE(isDisCC == true);  
}

TEST_CASE("isDiscoverCC - Testing a cc number with the right start except its too long, expecting false.")
{
    string number = "62292612345678900";
    bool isDisCC = isDiscoverCC(number);
    
    REQUIRE(isDisCC == false);  
}

TEST_CASE("isDiscoverCC - Testing a valid Discover cc number, expecting true.")
{
    string number = "6440747636070782";
    bool isDisCC = isDiscoverCC(number);
    
    REQUIRE(isDisCC == true);  
}

//************************************************
// Test cases for isMastercardCC function
//************************************************

TEST_CASE("isMastercardCC - Testing a mastercard cc number with the wrong number of digits, expecting false.")
{
    string number = "50123456789012345";
    bool isMCCC = isMastercardCC(number);
    
    REQUIRE(isMCCC == false);  
}

TEST_CASE("isMastercardCC - Testing a mastercard cc number with the right number of didgets but with the wrong starting digits, expecting false.")
{
    string number = "4000000000000000";
    bool isMCCC = isMastercardCC(number);
    
    REQUIRE(isMCCC == false);  
}

TEST_CASE("isMastercardCC - Testing isMastercardCC with valid mastercard ccnumber.")
{
    string number = "5385288768768674";
    bool isMCCC = isMastercardCC(number);
    
    REQUIRE(isMCCC == true);  
}

//************************************************
// Test cases for isVisaCC function
//************************************************

TEST_CASE("isVisaCC - First test case for isViseCC. Input has wrong number of characters, expecting false.")
{
    string number = "41234123412341";
    bool isVCC = isVisaCC(number);
    
    REQUIRE(isVCC == false);  
}

TEST_CASE("isVisaCC - Testing isVisaCC with a number of the correct length, but starting with the wrong digit. Expecting false.")
{
    string number = "3123412341234111";
    bool isVCC = isVisaCC(number);
    
    REQUIRE(isVCC == false);  
}

TEST_CASE("isVisaCC - Testing isVisaCC with a valid visa cc number. expecting true")
{
    string number = "4794630503276178";
    bool isVCC = isVisaCC(number);
    
    REQUIRE(isVCC == true);  
}

//************************************************
// Test cases for getValidCC function, testing length, contents, and Luhn's
//************************************************

TEST_CASE("isValidCC - First test case for isValidCC, input isnt a valid length, expecting false")
{
    string number = "12345";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == false);  
}

TEST_CASE("isValidCC - Second test case for isValidCC, input contains letters, expecting false")
{
    string number = "12345123451234a";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == false);  
}

TEST_CASE("isValidCC - Third test case for isValidCC, 16 length, fails luhns, expecting false")
{
    string number = "1234512345123451";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == false);  
}

TEST_CASE("isValidCC - Third test case for isValidCC, 16 length, passes luhns, expecting true")
{
    string number = "4716150722142577";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == true);  
}

TEST_CASE("isValidCC - Third test case for isValidCC, 15 length, fails luhns, expecting false")
{
    string number = "123451234512345";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == false);  
}

TEST_CASE("isValidCC - Third test case for isValidCC, 15 length, passes luhns, expecting true")
{
    string number = "343669144240775";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == true);  
}

TEST_CASE("isValidCC - Third test case for isValidCC, 13 length, fails luhns, expecting false")
{
    string number = "1234512345123";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == false);  
}

TEST_CASE("isValidCC - Third test case for isValidCC, 13 length, passes luhns, expecting true")
{
    string number = "7425473237792";
    bool valid = isValidCC(number);
    
    REQUIRE(valid == true);  
}



