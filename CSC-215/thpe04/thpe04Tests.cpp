#include "thpe04.h"
#include "..//catch.hpp"

TEST_CASE("playRound - 1 card hands")
{
	queue<card> player1;
	queue<card> player2;

	card card1;
	card1.faceValue = 0;
	card1.suit = 0;
	card card2;
	card2.faceValue = 9;
	card2.suit = 3;
	player1.push(card1);
	player2.push(card2);

	playRound(player1, player2);

	ostringstream sout1, sout2;

	sout1 << player1;
	sout2 << player2;

	CHECK(sout2.str() == "AH, 10S");
	CHECK(sout1.str() == "");
}

TEST_CASE("playRound - 4 card hands, first matching")
{
	queue<card> player1;
	queue<card> player2;

	card card1;
	card1.faceValue = 0; // AH
	card1.suit = 0;
	card card2;
	card2.faceValue = 9; // 10S
	card2.suit = 3;
	card card3;
	card3.faceValue = 12; // KC
	card3.suit = 2;
	card card4;
	card4.faceValue = 2; // 3S
	card4.suit = 3;
	card card5;
	card5.faceValue = 0; // AD
	card5.suit = 1;
	card card6;
	card6.faceValue = 9; // 10C
	card6.suit = 2;
	card card7;
	card7.faceValue = 12; // KS
	card7.suit = 3;
	card card8;
	card8.faceValue = 1; // 2H
	card8.suit = 0;
	player1.push(card1);
	player1.push(card2);
	player1.push(card3);
	player1.push(card4);
	player2.push(card5);
	player2.push(card6);
	player2.push(card7);
	player2.push(card8);

	playRound(player1, player2);

	ostringstream sout1, sout2;

	sout1 << player1;
	sout2 << player2;

	CHECK(sout2.str() == "");
	CHECK(sout1.str() == "2H, KS, 10C, AD, 3S, KC, 10S, AH");
}