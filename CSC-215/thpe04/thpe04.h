/** *********************************************************************
 * @file
 *
 * @brief Contains Prototypes for thpe04.cpp
 ***********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <random>
#include "stack.h"
#include <sstream>

using namespace std;

/**
	* @brief Holds data for a card, two ints.
*/
struct card
{
	int faceValue; /**< Face value of the card (0-12) */
	int suit;      /**< Suit of the card (0-3) */
};

bool openInput(ifstream& fin, string fileName);
void printUsage();
void populateDeckF(queue<card>& deck, ifstream& fin);
void populateDeckS(queue<card>& deck, int seed);
void playRound(queue<card>& player1, queue<card>& player2);

ostream& operator<<(ostream& out, card card);
bool operator==(card card1, card card2);

ostream& operator<<(ostream& out, queue<card> player);