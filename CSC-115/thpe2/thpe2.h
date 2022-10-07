/** **************************************************************************************
* @file
*****************************************************************************************/

#pragma once
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

const int TERMS = 10;
const double PI = atan(1.0) * 4;
const double ERRORVALUE = .000000000001;
const int ITERATIONMAX = 5000;
const double ERRORTOLERANCE = .000001;

//Write prototypes here

double mySqrt(double sqrtNum);
double myCbrt(double cbrtNum);

double myLog(double logNum, int base);

double mySin(double rads);
double mySinD(double degs);
double myCos(double rads);
double myCosD(double degs);
double myTan(double rads);
double myTanD(double degs);

double factorial(double x);

void copyArray(double destination[], double source[], int size);
void  initialArray(double arrayToInit[], int size, double initValue);

double sumArray(double arrayToSum[], int size);
double averageArray(double arrayToAverage[], int size);

int maxLocation(double array[], int size);
double maxValue(double array[], int size);
int minLocation(double array[], int size);
double minValue(double array[], int size);

int countIf(double array[], int size, double termToCount);

void mySort(double array[], int size, string ASCorDSC);

int linearSearch(double array[], int size, double termToFind);
int binarySearch(double array[], int size, double termToFind);