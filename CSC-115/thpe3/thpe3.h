#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <random>
#include <iostream>
#include <fstream>

using namespace std;

const int royalFlush = 9;
const int straightFlush = 8;
const int fourOfAKind = 7;
const int fullHouse = 6;
const int Flush = 5;
const int straight = 4;
const int threeOfAKind = 3;
const int twoPair = 2;
const int twoOfAKind = 1;
const int highCard = 0;

// Helper functions
bool openInput(ifstream& fin, string fileName);
bool openOutput(ofstream& fout, string fileName);

// Hand classification functions
int classifyHand(int hand[], int handSize);
bool isTwoOfAKind(int hand[], int handSize);
bool isTwoPair(int hand[], int handSize);
bool isThreeOfAKind(int hand[], int handSize);
bool isStraight(int hand[], int handSize);
bool isFlush(int hand[], int handSize);
bool isFullhouse(int hand[], int handSize);
bool isFourOfAKind(int hand[], int handSize);
bool isStraightFlush(int hand[], int handSize);
bool isRoyalFlush(int hand[], int handSize);



//Write prototypes here

