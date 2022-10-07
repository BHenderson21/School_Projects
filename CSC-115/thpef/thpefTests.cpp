#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpef.h"
#include "ourDate.h"

const bool RUNCATCH = false;

int main(int argc, char **argv)
{
    Catch::Session session;
    int result;
    if( RUNCATCH )
    {
        result = session.run();
        if( result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }
    
    if(argc != 5)
    {
        cout << "Usage: thpef.exe datafile template1 template2 template3" << endl;
        cout << "       datafile --name of input data file" << endl;
        cout << "       template1 --name of purchase template file" << endl;
        cout << "       template2 --name of payment template file" << endl;
        cout << "       template3 --name of overdue template file" << endl;
        exit(0);
    }
    
    ifstream finData;
    ifstream finPurchaseTemplate;
    ifstream finPaymentTemplate;
    ifstream finOverdueTemplate;
    ofstream fout;
    client currentMember;
    string date;
    string test;
    if(currDate == "")
    {
        date = getDate();
    }
    else
    {
        date = currDate;
    }
    if(!openInput(finData, argv[1]))
    {
        cout << "Unable to open the input file: " << argv[1] << endl;
        exit(0);
    }
    while(getClient(finData, currentMember))
    {
        if(currentMember.transactionAmount > 0)
        {
            writeLetter(currentMember, argv[2], date);
        }
        else if(currentMember.transactionAmount < 0)
        {
            writeLetter(currentMember, argv[3], date);
        }
        else if(currentMember.transactionAmount == 0 && currentMember.currBal != 0)
        {
            writeLetter(currentMember, argv[4], date);
        }
    }
    
}

TEST_CASE("getDate - Test case for my getDate function. This will only work today, and I'll have to change it every day...")
{ 
    string date = getDate();
    CHECK(date == " 1 May, 2022");
}

TEST_CASE("getClient - Test case for my getClient function.")
{
    string fileName = "test.txt";
    ifstream fin;
    client testClient;
    
    if(!openInput(fin, fileName))
    {
        cout << "openInput failed" << endl;
        exit(0);
    }
    if(!getClient(fin, testClient))
    {
        cout << "getClient failed" << endl;
        exit(0);
    }    
    CHECK(testClient.first == "James");
    CHECK(testClient.transactionAmount == 89.55);
    CHECK(testClient.currBal == 12.59);
    
}