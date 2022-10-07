#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe2.h"

//write test cases here

//*****************************************************************************
// Test cases for mySqrt functon
//*****************************************************************************

TEST_CASE("mySqrt - Testing mySqrt with a number less than 0")
{
    double x = 0;
    double sqrt = mySqrt(x);
    REQUIRE(sqrt == Approx(0));
}

TEST_CASE("mySqrt - Testing mySqrt with 1")
{
    double x = 1;
    double sqrt = mySqrt(x);
    REQUIRE(sqrt == Approx(1));
}

TEST_CASE("mySqrt - Testing mySqrt with perfectly square number, 25")
{
    double x = 25;
    double sqrt = mySqrt(x);
    REQUIRE(sqrt == Approx(5));
}

TEST_CASE("mySqrt - Testing mySqrt with less perfectly square number, 10")
{
    double x = 10;
    double sqrt = mySqrt(x);
    REQUIRE(sqrt == Approx(3.16227766));
}

//*****************************************************************************
// Test cases for myCbrt functon
//*****************************************************************************

TEST_CASE("myCbrt - Testing myCbrt with a number less than 0")
{
    double x = 0;
    double cbrt = myCbrt(x);
    REQUIRE(cbrt == Approx(0));
}

TEST_CASE("myCbrt - Testing myCbrt with 1")
{
    double x = 1;
    double cbrt = myCbrt(x);
    REQUIRE(cbrt == Approx(1));
}

TEST_CASE("myCbrt - Testing myCbrt with perfectly cube number, 125")
{
    double x = 125;
    double cbrt = myCbrt(x);
    REQUIRE(cbrt == Approx(5));
}

TEST_CASE("myCbrt - Testing myCbrt with less perfectly cube number, 10")
{
    double x = 10;
    double cbrt = myCbrt(x);
    REQUIRE(cbrt == Approx(2.15443469));
}

//*****************************************************************************
// Test cases for myLog functon
//*****************************************************************************

TEST_CASE("myLog - Testing myLog with a base and an input of 1. Should output 1")
{
    int base = 1;
    double x = 1;
    double log = myLog(x, base);
    REQUIRE(log == Approx(1));
}

TEST_CASE("myLog - Testing myLog with a base of 10 and an input of 100, expecting 2")
{
    int base = 10;
    double x = 100;
    double log = myLog(x, base);
    REQUIRE(log == Approx(2));
}

TEST_CASE("myLog - Testing myLog with a random base(4) and random input(3)")
{
    int base = 4;
    double x = 3;
    double log = myLog(x, base);
    REQUIRE(log == Approx(0.79248125));
}

//*****************************************************************************
// Test cases for factorial functon
//*****************************************************************************

TEST_CASE("factorial - Series of tests for my factorial function")
{
    double a = 0;
    double c = 2;
    double d = 3;
    double f = 15;
    double g = 21;
    
    double factA = factorial(a);      
    double factC = factorial(c);    
    double factD = factorial(d);      
    double factF = factorial(f);    
    double factG = factorial(g);
    
    CHECK(factA == Approx(1));
    CHECK(factC == Approx(2));
    CHECK(factD == Approx(6));
    CHECK(factF == Approx(1307674368000));
    CHECK(factG == Approx(51090942171709440000.0));
}

//*****************************************************************************
// Test cases for mySin functon
//*****************************************************************************

TEST_CASE("mySin - Series of test cases for mySin")
{
    double a = PI;
    double b = PI/2;
    double c = PI/4;
    double d = PI/3;
    double e = 0;
    
    double sinA = mySin(a);      
    double sinB = mySin(b);    
    double sinC = mySin(c);      
    double sinD = mySin(d);    
    double sinE = mySin(e);
    
    CHECK((fabs(sinA) < ERRORTOLERANCE));
    CHECK((fabs(sinB) - 1) < ERRORTOLERANCE);
    CHECK((fabs(sinC) - 0.70710678118) < ERRORTOLERANCE);
    CHECK((fabs(sinD) - 1.0471975512) < ERRORTOLERANCE);
    CHECK(fabs(sinE) < ERRORTOLERANCE);
}

//*****************************************************************************
// Test cases for mySinD functon
//*****************************************************************************

TEST_CASE("mySinD - Series of test cases for mySinD")
{
    double a = 180;
    double b = 90;
    double c = 45;
    double d = 60;
    double e = 0;
    
    double sinA = mySinD(a);      
    double sinB = mySinD(b);    
    double sinC = mySinD(c);      
    double sinD = mySinD(d);    
    double sinE = mySinD(e);
    
    CHECK((fabs(sinA) < ERRORTOLERANCE));
    CHECK((fabs(sinB) - 1) < ERRORTOLERANCE);
    CHECK((fabs(sinC) - 0.70710678118) < ERRORTOLERANCE);
    CHECK((fabs(sinD) - 1.0471975512) < ERRORTOLERANCE);
    CHECK(fabs(sinE) < ERRORTOLERANCE);
}

//*****************************************************************************
// Test cases for myCos functon
//*****************************************************************************

TEST_CASE("myCos- Series of test cases for myCos")
{
    double a = PI;
    double b = PI/2;
    double c = PI/4;
    double d = PI/3;
    double e = 0;
    
    double CosA = myCos(a);      
    double CosB = myCos(b);    
    double CosC = myCos(c);      
    double CosD = myCos(d);    
    double CosE = myCos(e);
    
    CHECK(((fabs(CosA) - 1) < ERRORTOLERANCE));
    CHECK((fabs(CosB)) < ERRORTOLERANCE);
    CHECK((fabs(CosC) - 0.70710678118) < ERRORTOLERANCE);
    CHECK((fabs(CosD) - 0.5) < ERRORTOLERANCE);
    CHECK((fabs(CosE)-1) < ERRORTOLERANCE);
}

//*****************************************************************************
// Test cases for myCosD functon
//*****************************************************************************

TEST_CASE("myCosD - Series of test cases for myCosD")
{
    double a = 180;
    double b = 90;
    double c = 45;
    double d = 60;
    double e = 0;
    
    double CosA = myCosD(a);      
    double CosB = myCosD(b);    
    double CosC = myCosD(c);      
    double CosD = myCosD(d);    
    double CosE = myCosD(e);
    
    CHECK(((fabs(CosA) - 1) < ERRORTOLERANCE));
    CHECK((fabs(CosB)) < ERRORTOLERANCE);
    CHECK((fabs(CosC) - 0.70710678118) < ERRORTOLERANCE);
    CHECK((fabs(CosD) - 0.5) < ERRORTOLERANCE);
    CHECK((fabs(CosE)-1) < ERRORTOLERANCE);
}

//*****************************************************************************
// Test cases for myTan functon
//*****************************************************************************

TEST_CASE("myTan - Series of test cases for myTan")
{
    double a = PI;
    double c = PI/4;
    double d = PI/3;
    double e = 0;
    
    double tanA = myTan(a);          
    double tanC = myTan(c);      
    double tanD = myTan(d);    
    double tanE = myTan(e);
    
    CHECK(((fabs(tanA)) < ERRORTOLERANCE));
    CHECK((fabs(tanC) - 1) < ERRORTOLERANCE);
    CHECK((fabs(tanD) - 1.73205080757) < ERRORTOLERANCE);
    CHECK((fabs(tanE)) < ERRORTOLERANCE);
}

//*****************************************************************************
// Test cases for myTanD functon
//*****************************************************************************

TEST_CASE("myTanD - Series of test cases for myTanD")
{
    double a = 180;
    double c = 45;
    double d = 60;
    double e = 0;
    
    double tanA = myTanD(a);          
    double tanC = myTanD(c);      
    double tanD = myTanD(d);    
    double tanE = myTanD(e);
    
    CHECK(((fabs(tanA)) < ERRORTOLERANCE));
    CHECK((fabs(tanC) - 1) < ERRORTOLERANCE);
    CHECK((fabs(tanD) - 1.73205080757) < ERRORTOLERANCE);
    CHECK((fabs(tanE)) < ERRORTOLERANCE);
}

//*****************************************************************************
// Test cases for copyArray functon
//*****************************************************************************

TEST_CASE("copyArray - Series of test cases for my copyArray function.")
{
    int size = 6;
    
    double source1[6] = {7, 8, 3, 6, 8, 9};
    double source2[6] = {5, 7, 35, 89, 58, 39};
    double source3[6] = {1.7, 4.8, 53.6, 6.6, 7.8, 8.9};
    
    double destination1[6] = {};
    double destination2[6] = {};
    double destination3[6] = {};
    
    copyArray(destination1, source1, size);
    copyArray(destination2, source2, size);
    copyArray(destination3 , source3, size);
    
    CHECK(destination1[0] == source1[0]);
    CHECK(destination1[1] == source1[1]);
    CHECK(destination1[2] == source1[2]);
    CHECK(destination1[3] == source1[3]);
    CHECK(destination1[4] == source1[4]);
    CHECK(destination1[5] == source1[5]);
    
    CHECK(destination2[0] == source2[0]);
    CHECK(destination2[1] == source2[1]);
    CHECK(destination2[2] == source2[2]);
    CHECK(destination2[3] == source2[3]);
    CHECK(destination2[4] == source2[4]);
    CHECK(destination2[5] == source2[5]);
    
    CHECK(destination3[0] == source3[0]);
    CHECK(destination3[1] == source3[1]);
    CHECK(destination3[2] == source3[2]);
    CHECK(destination3[3] == source3[3]);
    CHECK(destination3[4] == source3[4]);
    CHECK(destination3[5] == source3[5]);
}

//*****************************************************************************
// Test cases for initialArray functon
//*****************************************************************************

TEST_CASE("initialArray - Test cases for initialArray function")
{
    double array1[5] = {0, 0, 0, 0, 0};
    double array2[5] = {0, 0, 0, 0, 0};
    
    int size = 5;
    
    double value1 = 2.9;
    double value2 = 300;
    
    initialArray(array1, size, value1);
    initialArray(array2, size, value2);
    
    CHECK(array1[0] == 2.9);    
    CHECK(array1[1] == 2.9);    
    CHECK(array1[2] == 2.9);    
    CHECK(array1[3] == 2.9);    
    CHECK(array1[4] == 2.9);
    
    CHECK(array2[0] == 300);    
    CHECK(array2[1] == 300);    
    CHECK(array2[2] == 300);    
    CHECK(array2[3] == 300);    
    CHECK(array2[4] == 300);        
}

//*****************************************************************************
// Test cases for sumArray functon
//*****************************************************************************

TEST_CASE("sumArray - Test cases for sumArray function")
{
    double array1[4] = {1.5, 2.5, 3.5, 4.4};
    double array2[6] = {1, 3, 5, 7, 9, 11};
    
    int size1 = 4;
    int size2 = 6;
    
    double sum1 = sumArray(array1, size1);
    double sum2 = sumArray(array2, size2);
    
    CHECK(sum1 == 11.9);
    CHECK(sum2 == 36);
}

//*****************************************************************************
// Test cases for averageArray functon
//*****************************************************************************

TEST_CASE("averageArray - Test cases for averageArray function")
{
    double array1[4] = {1.5, 2.5, 3.5, 4.4};
    double array2[6] = {1, 3, 5, 7, 9, 11};
    
    int size1 = 4;
    int size2 = 6;
    
    double av1 = averageArray(array1, size1);
    double av2 = averageArray(array2, size2);
    
    CHECK(av1 == 2.975);
    CHECK(av2 == 6);
}

//*****************************************************************************
// Test cases for maxLocation functon
//*****************************************************************************

TEST_CASE("maxLocation - Test cases for maxLocation function")
{
    double array1[4] = {1.5, 2.5, 3.5, 4.4};
    double array2[6] = {1, 3, 5, 7, 99, 11};
    
    int size1 = 4;
    int size2 = 6;
    
    int loc1 = maxLocation(array1, size1);
    int loc2 = maxLocation(array2, size2);
    
    CHECK(loc1 == 3);
    CHECK(loc2 == 4);
}

//*****************************************************************************
// Test cases for maxValue functon
//*****************************************************************************

TEST_CASE("maxValue - Test cases for maxValue function")
{
    double array1[4] = {1.5, 2.5, 3.5, 4.4};
    double array2[6] = {1, 3, 5, 7, 99, 11};
    
    int size1 = 4;
    int size2 = 6;
    
    double val1 = maxValue(array1, size1);
    double val2 = maxValue(array2, size2);
    
    CHECK(val1 == 4.4);
    CHECK(val2 == 99);
}
//*****************************************************************************
// Test cases for minLocation functon
//*****************************************************************************

TEST_CASE("minLocation - Test cases for minLocation function")
{
    double array1[4] = {1.5, 2.5, 3.5, 4.4};
    double array2[6] = {1, 3, -5, 7, 99, 11};
    
    int size1 = 4;
    int size2 = 6;
    
    int loc1 = minLocation(array1, size1);
    int loc2 = minLocation(array2, size2);
    
    CHECK(loc1 == 0);
    CHECK(loc2 == 2);
}

//*****************************************************************************
// Test cases for minValue functon
//*****************************************************************************

TEST_CASE("minValue - Test cases for minValue function")
{
    double array1[4] = {1.5, 2.5, 3.5, 4.4};
    double array2[6] = {1, 3, 5, 7, 99, 11};
    
    int size1 = 4;
    int size2 = 6;
    
    double val1 = minValue(array1, size1);
    double val2 = minValue(array2, size2);
    
    CHECK(val1 == 1.5);
    CHECK(val2 == 1);
}

//*****************************************************************************
// Test cases for countIf functon
//*****************************************************************************

TEST_CASE("countIf - series of test cases for my countIf function")
{
    double array[10] = {1, 2, 3, 4.4, 3, 2, 4.4, 5, 1, 4.4};
    int size = 10;
    
    int count1 = countIf(array, size, 1);
    int count2 = countIf(array, size, 2);
    int count3 = countIf(array, size, 3);
    int count4 = countIf(array, size, 4.4);
    int count5 = countIf(array, size, 5);
    
    CHECK(count1 == 2);
    CHECK(count2 == 2);
    CHECK(count3 == 2);
    CHECK(count4 == 3);
    CHECK(count5 == 1);
}

//*****************************************************************************
// Test cases for mySort functon
//*****************************************************************************

TEST_CASE("mySort - series of test cases for mySort function when ascending")
{
    double array[5] = {1, 3, 5, 4, 2};
    int size = 5;
    
    mySort(array, size, "ASC");
    
    CHECK(array[0] == 1);
    CHECK(array[1] == 2);
    CHECK(array[2] == 3);
    CHECK(array[3] == 4);
    CHECK(array[4] == 5);
}

//***************************************************

TEST_CASE("mySort - series of test cases for mySort function when decending")
{
    double array[5] = {1, 3, 5, 4, 2};
    int size = 5;
    
    mySort(array, size, "DSC");
    
    CHECK(array[0] == 5);
    CHECK(array[1] == 4);
    CHECK(array[2] == 3);
    CHECK(array[3] == 2);
    CHECK(array[4] == 1);
}

//*****************************************************************************
// Test cases for linearSearch functon
//*****************************************************************************

TEST_CASE("linearSearch - series of test cases for my linearSearch function")
{
    double array[5] = {1, 3, 5, 4, 2};
    int size = 5;
    
    int search5 = linearSearch(array, size, 5);
    int search1 = linearSearch(array, size, 1);
    int search3 = linearSearch(array, size, 3);
    int search4 = linearSearch(array, size, 4);
    int search2 = linearSearch(array, size, 2);
    int search0 = linearSearch(array, size, 0);
    
    CHECK(search5 == 2);
    CHECK(search1 == 0);
    CHECK(search3 == 1);
    CHECK(search4 == 3);
    CHECK(search2 == 4);
    CHECK(search0 == -1);
}

//*****************************************************************************
// Test cases for binarySearch functon
//*****************************************************************************

TEST_CASE("binarySearch - series of test cases for my binarySearch function")
{
    double array[5] = {1, 3, 5, 4, 2};
    mySort(array, 5, "ASC");
    int size = 5;
    
    int search5 = binarySearch(array, size, 5);
    int search1 = binarySearch(array, size, 1);
    int search3 = binarySearch(array, size, 3);
    int search4 = binarySearch(array, size, 4);
    int search2 = binarySearch(array, size, 2);
    int search0 = binarySearch(array, size, 0);
    
    CHECK(search5 == 4);
    CHECK(search1 == 0);
    CHECK(search3 == 2);
    CHECK(search4 == 3);
    CHECK(search2 == 1);
    CHECK(search0 == -1);
}