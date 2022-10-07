#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct client
{
    string first;
    string last;
    string address;
    string city;
    string state;
    string zip;
    double transactionAmount;
    double currBal;
};

//Write prototypes here

bool openInput(ifstream& fin, string fileName);
bool openOutput(ofstream& fout, string fileName);
bool getClient(ifstream& fin, client& currentMember);
void writeLetter(client& currentMember, string templateFile, string date);

string getDate();


