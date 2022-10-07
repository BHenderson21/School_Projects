#pragma once
#include <cmath>
#include <string>
#include <cctype>

using namespace std;

//************************************************
// getCCType function and subfunctions.
//************************************************
string getCCType(string ccNumber);

bool isAmericanExpressCC(string ccNumber);
bool isDiscoverCC(string ccNumber);
bool isMastercardCC(string ccNumber);
bool isVisaCC(string ccNumber);



//************************************************
// isValidCC function and subfunctions.
//************************************************
bool isValidCC(string ccNumber);

bool isValidLength(int length);
bool isOnlyNumbers(string ccNumber);
bool luhns16(string ccNumber);
bool luhnsOdd(string ccNumber);