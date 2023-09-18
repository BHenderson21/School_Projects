/** *********************************************************************
 * @file
 *
 * @brief Contains function main, playRound function, functions to populate
 *                 hands, printUsage, openInput, and operation overloads.
 ***********************************************************************/

 /** ********************************************************************
  *
  * @mainpage Program 4 - War
  *
  * @section course_section Course Information
  *
  * @authors Brandon Henderson
  *
  * @date December 12, 2022
  *
  * @par Instructor:
  *         Roger Schrader
  *
  * @par Course:
  *         CSC 215 - Section M02 - 1:00 pm
  *
  * @par Location:
  *         CB - Room 205
  *
  * @section program_section Program Information
  *
  * @details This program simulates the card game War.
  *          
  *          When running this program you have the option of
  *          supplying two decks of cards via two files, or 
  *          supplying two integer seeds with which to randomly 
  *          generate two decks of cards. After the two decks
  *          are read or created, a game of War is simulated with
  *          the number of rounds played and the final player hands
  *          displayed two the screen when the game concludes.
  *
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *
  * @par Usage:
    @verbatim
    C:\> thpe04.exe -f file1.cards file2.cards
    or
    C<\> thpe04.exe -s seed1 seed2
         -f:                        Decks supplied via files
         file1.cards & file2.cards: Files containing decks
         -s                         Decks randomly generated
         seed1 & seed2              Seeds for randomy generating decks
    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications *
  *
  * @par Modifications and Development Timeline:

    Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/101077691/csc215f22programs/-/commits/main" target="_blank">
    Click Here.</a>
  *
  ***********************************************************************/

#define CATCH_CONFIG_RUNNER

#include "..\\catch.hpp"
#include "thpe04.h"
#include "stack.cpp"


const bool runcatch = false; /**< Variable to decide wether or not to run Catch2 test cases */

// ARGV: thpe04.exe -f file1.txt file2.txt
// ARGV: thpe04.exe -s seed1     seed2
// ARGC: 0          1  2         3

 /** *********************************************************************
   * @author Brandon Henderson
   *
   * @par Description:
   * This is the main function. It verifies the correct number of command line arguments,
   * determines if the decks are supplied or need to be generated, then opens and reads
   * the files or generates the decks, then plays rounds of War on a loop until one hand
   * is empty, at which point the number of rounds played is displayed along with the final
   * hands of each player.
   *
   *
   * @param[in] argc - number of command line arguments
   * @param[in] argv - 2d array of characters containing the command line arguments.
   *
   * @returns none
   *
   * @par Example:
     @verbatim
     C:\> thpe04.exe -f file1.cards file2.cards
    or
    C<\> thpe04.exe -s seed1 seed2
         -f:                        Decks supplied via files
         file1.cards & file2.cards: Files containing decks
         -s                         Decks randomly generated
         seed1 & seed2              Seeds for randomy generating decks
     @endverbatim

   ***********************************************************************/

int main(int argc, char** argv)
{
    // RUNCATCH
    if (runcatch)
    {
        Catch::Session session;
        int returnCode;
        returnCode = session.run(argc, argv);
        if (returnCode != 0)
        {
            cout << "A Test case failed" << endl;
        }
        return 0;
    }

    // VARIABLE DECLARATION HERE
    ifstream fin1;
    ifstream fin2;
    queue<card> deck1;
    queue<card> deck2;
    int roundCount = 0;


    if (argc == 4)
    {
        if (string(argv[1]) == "-s")
        {
            populateDeckS(deck1, stoi(argv[2]));
            populateDeckS(deck2, stoi(argv[3]));
            while ((deck1.size() != 0) && (deck2.size() != 0))
            {
                playRound(deck1, deck2);
                roundCount++;
            }
            if (deck1.size() == 0)
            {
                cout << "Player 2 wins after " << roundCount << " rounds." << endl;
                cout << "Player 1 hand: " << deck1 << endl;
                cout << "Player 2 hand: " << deck2 << endl;
            }
            else
            {
                cout << "Player 1 wins after " << roundCount << " rounds." << endl;
                cout << "Player 1 hand: " << deck1 << endl;
                cout << "Player 2 hand: " << deck2 << endl;
            }
        }
        else if (string(argv[1]) == "-f")
        {
            if (!openInput(fin1, argv[2]))
            {
                cout << "Could not open file: " << argv[2] << endl;
            }
            if (!openInput(fin2, argv[3]))
            {
                cout << "Could not open file: " << argv[3] << endl;
            }
            populateDeckF(deck1, fin1);
            populateDeckF(deck2, fin2);
            while ((deck1.size() != 0) && (deck2.size() != 0))
            {
                playRound(deck1, deck2);
                roundCount++;
            }
            if (deck1.size() == 0)
            {
                cout << "Player 2 wins after " << roundCount << " rounds." << endl;
                cout << "Player 1 hand: " << deck1 << endl;
                cout << "Player 2 hand: " << deck2 << endl;
            }
            else
            {
                cout << "Player 1 wins after " << roundCount << " rounds." << endl;
                cout << "Player 1 hand: " << deck1 << endl;
                cout << "Player 2 hand: " << deck2 << endl;
            }
        }
        else
        {
            cout << "Invalid startup: Invalid input type." << endl;
            printUsage();
            return 0;
        }
    }
    else
    {
        cout << "Invalid startup: Invalid number of command line arguments" << endl;
        printUsage();
        return 0;
    }

}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Plays a round of War with two provided decks.
 *
 *  @param[in] player1 A queue of cards
 *  @param[in] player2 A queue of cards
 *
 *
 *  @par Example
 *  @verbatim

    queue<card> player1;
    card1.faceValue = 6;
    card1.suit = 0;
    player1.push(card1);
    queue<card> player2;
    card1.faceValue = 7;
    card1.suit = 0;
    player2.push(card1);
    playRound(player1, player2); // Would result in player 2 with a hand of 2 cards and player 1 with an empty hand.

 *  @endverbatim
************************************************************************/

void playRound(queue<card>& player1, queue<card>& player2)
{
    Stack<card> discardPile1;
    Stack<card> discardPile2;
    card tempCard;
    int n = 3;

    // Both players take a card off the top of their hands
    card p1Discard = player1.front();
    player1.pop();
    card p2Discard = player2.front();
    player2.pop();

    // Both players put their card in their discard pile
    discardPile1.push(p1Discard);
    discardPile2.push(p2Discard);

    // Compare the cards
    while (discardPile1.top().faceValue == discardPile2.top().faceValue)
    {
        if ((player1.size() == 0) || (player2.size() == 0))
        {
            while (discardPile1.pop(tempCard))
            {
                player1.push(tempCard);
            }
            while (discardPile2.pop(tempCard))
            {
                player2.push(tempCard);
            }
            card p1Discard = player1.front();
            player1.pop();
            card p2Discard = player2.front();
            player2.pop();
            discardPile1.push(p1Discard);
            discardPile2.push(p2Discard);
        }
        else
        {
            n = 3;
            if (player1.size() < 3)
            {
                n = player1.size();
            }
            if (player2.size() < 3)
            {
                n = player2.size();
            }
            for (int i = 0; i < n; i++)
            {
                card p1Discard = player1.front();
                player1.pop();
                card p2Discard = player2.front();
                player2.pop();
                discardPile1.push(p1Discard);
                discardPile2.push(p2Discard);
            }
        }
        
    }
    if (discardPile1.top().faceValue < discardPile2.top().faceValue)
    {
        while (discardPile1.pop(tempCard))
        {
            player2.push(tempCard);
        }
        while (discardPile2.pop(tempCard))
        {
            player2.push(tempCard);
        }
    }
    else
    {
        while (discardPile2.pop(tempCard))
        {
            player1.push(tempCard);
        }
        while (discardPile1.pop(tempCard))
        {
            player1.push(tempCard);
        }
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Populates a deck with cards read from a file
 *
 *  @param[in] deck A queue of cards, passed by value
 *  @param[in] fin An open input file stream 
 *
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    queue<card> deck;
    openInput(fin, file);

    populateDeckF(deck, fin); // Would fill deck with cards read from the file.
 *  @endverbatim
************************************************************************/

void populateDeckF(queue<card>& deck, ifstream& fin)
{
    int cardNumber;
    card tempCard;

    while (fin >> cardNumber)
    {
        tempCard.faceValue = (cardNumber % 13);
        tempCard.suit = (cardNumber / 13);
        deck.push(tempCard);
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Populates a deck with random cards given an integer seed, making sure there 
 *  are no repeat cards
 *
 *  @param[in] deck A queue of cards, passed by value
 *  @param[in] seed An integer to be used as a seed for random generation
 *
 *
 *  @par Example
 *  @verbatim

    queue<card> deck;
    int seed = 42;

    populateDeckS(deck, seed); // Would fill deck with 52 cards in a random order with no repitition.
 *  @endverbatim
************************************************************************/

void populateDeckS(queue<card>& deck, int seed)
{
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0, 51);

    card tempCard;
    int cardNumber;
    int usedCards[52] = { 0 };

    while (deck.size() < 52)
    {
        cardNumber = distribution(generator);
        if (usedCards[cardNumber] == 0)
        {
            usedCards[cardNumber] = 1;
            tempCard.faceValue = (cardNumber % 13);
            tempCard.suit = (cardNumber / 13);
            deck.push(tempCard);
        }
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Overloading the == operator to accomadate cards
 *
 *  @param[in] card1 Any card
 *  @param[in] card2 Any card
 *
 *  @returns bool True if the cards face values are equivilent, false otherwise
 *
 *  @par Example
 *  @verbatim

    card1.faceValue = 6;
    card1.suit = 0;
    card2.faceValue = 7;
    card2.suit = 3;
    card3.faceValue = 6;
    card3.suit = 1;

    card1 == card3; // Would evaluate to true
    card1 == card 2; // Would evaluate to false


 *  @endverbatim
************************************************************************/

bool operator==(card card1, card card2)
{
    if (card1.faceValue == card2.faceValue)
    {
        return true;
    }
    return false;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Overloading ostreams << operator to accomadate cards
 *
 *  @param[in] out Any output stream
 *  @param[in] card A card
 *
 *  @returns ostream The original ostream
 *
 *  @par Example
 *  @verbatim

    card1.faceValue = 6;
    card1.suit = 0;

    cout << card1; // Output would be "7H"
 *  @endverbatim
************************************************************************/

ostream& operator<<(ostream& out, card card)
{
    if (card.faceValue == 0)
    {
        out << "A";
    }
    else if (card.faceValue == 10)
    {
        out << "J";
    }
    else if (card.faceValue == 11)
    {
        out << "Q";
    }
    else if (card.faceValue == 12)
    {
        out << "K";
    }
    else
    {
        out << (card.faceValue + 1);
    }


    // Outputting propper suit
    if (card.suit == 0)
    {
        out << "H";
    }
    else if (card.suit == 1)
    {
        out << "D";
    }
    else if (card.suit == 2)
    {
        out << "C";
    }
    else
    {
        out << "S";
    }
    return out;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Overloading ostreams << operator to accomadate queues of cards
 *
 *  @param[in] out Any output stream
 *  @param[in] player A queue of cards
 *
 *  @returns ostream The original ostream
 *
 *  @par Example
 *  @verbatim

    queue<card> player;
    card1.faceValue = 6;
    card1.suit = 0;
    player.push(card1);

    cout << player; // Output would be "7H"
 *  @endverbatim
************************************************************************/


ostream& operator<<(ostream& out, queue<card> player)
{
    while (player.size() != 0)
    {
        out << (player.front());
        player.pop();
        if (player.size() != 0)
        {
            out << ", ";
        }
    }
    return out;
}

/** *********************************************************************
 * @author Brandon Henderson
 *
 * @par Description:
 * Prints the usage statement to the console.
 *
 *
 * @par Example:
   @verbatim

   printUsage();

   C:\> thpe04.exe -f file1.cards file2.cards
    or
    C<\> thpe04.exe -s seed1 seed2
         -f:                        Decks supplied via files
         file1.cards & file2.cards: Files containing decks
         -s                         Decks randomly generated
         seed1 & seed2              Seeds for randomy generating decks

   @endverbatim

 ***********************************************************************/


void printUsage()
{
    cout << "Usage:" << endl;
    cout << "thpe04.exe -f file1.cards file2.cards" << endl;
    cout << "or" << endl;
    cout << "thpe04.exe -s seed1 seed2" << endl;
    cout << endl;
    cout << "-f:                        Decks supplied via files" << endl;
    cout << "file1.cards & file2.cards: Files containing decks" << endl;
    cout << "-s:                        Decks randomly generated" << endl;
    cout << "seed1 & seed2:             Seeds for randomly generating decks" << endl;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an file stream and a file name, opens the file to the stream
 *
 *  @param[in] fin An input stream
 *   @param[in] fileName A file name
 *
 *  @returns A bool, indicating if the file was successfully opened
 *
 *  @par Example
 *  @verbatim

    bool result;
    ifsteam fin;
    name = "test.txt";
    name2 = "test";

    result = openInput(fin, name); // result would be true

    result = openInput(fin, name2); // result would be false.


 *  @endverbatim
************************************************************************/


bool openInput(ifstream& fin, string fileName)
{
    fin.open(fileName, ios::in);
    if (!fin.is_open())
    {
        return false;
    }
    return true;
}