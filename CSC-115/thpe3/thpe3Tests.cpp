#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h"
const bool RUNCATCH = true;
int main( int argc, char **argv)
{
    string FOrSInput;
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
    if(argc != 4)
    {
        cout << "Usage: thpe3.exe -s seedValue quantity" << endl;
        cout << "       seedValue - # is integer for random numbers" << endl;
        cout << "       quantity - # of hands to deal" << endl;
        cout << endl;
        cout << "       thpe3.exe -f inputfilename outputfilename" << endl;
        cout << "       inputfilename - filename containing the poker hands to classify" << endl;
        cout << "       outputfilename - filename to output the statistics in" << endl;
        exit(0);
    }
    
    FOrSInput = argv[1];
    if(FOrSInput == "-f")
    {
        ifstream fin;
        ofstream fout;
        int hand[5];
        if(!openInput(fin, argv[2]))
        {
            cout << "Unable to open the file: " << argv[2] << endl;
            exit(0);
        }
        if(!openOutput(fout, argv[3]))
        {
            cout << "Unable to open the file: " << argv[2] << endl;
            exit(0);
        }        
        int i = 0;
        int numDealt = 0;
        int RF = 0;
        int SF = 0;
        int FoaK = 0;
        int FH = 0;
        int F = 0;
        int S = 0;
        int ToaK = 0;
        int TP = 0;
        int TwoaK = 0;
        int HC = 0;
        int temp = 0;
        while( fin >> temp)
        {
            hand[i] = temp;
            i++;
            if(i == 5)
            {
                numDealt++;
                int handVal = classifyHand(hand, 5);
                if(handVal == 9)
                {
                    RF++;
                }
                else if(handVal == 8)
                {
                    SF++;
                }
                else if(handVal == 7)
                {
                    FoaK++;
                }
                else if(handVal == 6)
                {
                    FH++;
                }
                else if(handVal == 5)
                {
                    F++;
                }
                else if(handVal == 4)
                {
                    S++;
                }
                else if(handVal == 3)
                {
                    ToaK++;
                }
                else if(handVal == 2)
                {
                    TP++;
                }
                else if (handVal == 1)
                {
                    TwoaK++;
                }
                else
                {
                   HC++;
                }
                i = 0;
            }
        }
        fout << "Hand Name" << "                " << "Dealt" << "         " << "Chance" << endl;
        fout << "Royal Flush" << setw(19) << RF << setw(15) << fixed << setprecision(6) << ((double(RF)/double(numDealt))*100) << "%" << endl;
        fout << "Straight Flush" << setw(16) << SF << setw(15) << fixed << setprecision(6) << ((double(SF)/double(numDealt))*100) << "%" << endl;
        fout << "Four of a Kind" << setw(16) << FoaK << setw(15) << fixed << setprecision(6) << ((double(FoaK)/double(numDealt))*100) << "%" << endl;
        fout << "Full House" << setw(20) << FH << setw(15) << fixed << setprecision(6) << ((double(FH)/double(numDealt))*100) << "%" << endl;
        fout << "Flush" << setw(25) << F << setw(15) << fixed << setprecision(6) << ((double(F)/double(numDealt))*100) << "%" << endl;
        fout << "Straights" << setw(21) << S << setw(15) << fixed << setprecision(6) << ((double(S)/double(numDealt))*100) << "%" << endl;
        fout << "Three of a Kind" << setw(15) << ToaK << setw(15) << fixed << setprecision(6) << ((double(ToaK)/double(numDealt))*100) << "%" << endl;
        fout << "Two Pair" << setw(22) << TP << setw(15) << fixed << setprecision(6) << ((double(TP)/double(numDealt))*100) << "%" << endl;
        fout << "Two of a Kind" << setw(17) << TwoaK << setw(15) << fixed << setprecision(6) << ((double(TwoaK)/double(numDealt))*100) << "%" << endl;
        fout << "High Card" << setw(21) << HC << setw(15) << fixed << setprecision(6) << ((double(HC)/double(numDealt))*100) << "%" << endl;
        fout << endl;
        fout << "Total Hands Dealt" << setw(13) << numDealt << endl;
    }
    else if(FOrSInput == "-s")
    {
        int simHand[5];
        int seed = stoi(argv[2]);
        int howManyHands = stoi(argv[3]);
        int i = 0;
        int numDealt = 0;
        int RF = 0;
        int SF = 0;
        int FoaK = 0;
        int FH = 0;
        int F = 0;
        int S = 0;
        int ToaK = 0;
        int TP = 0;
        int TwoaK = 0;
        int HC = 0;
        int card;
        
        default_random_engine engine(seed);
        uniform_int_distribution<int> deck(0,51);
        
        while(numDealt < howManyHands)
        {
            card = deck(engine);
            while(card == simHand[0] || card == simHand[1] || card == simHand[2] || card == simHand[3] || card == simHand[4])
            {
                card = deck(engine);
            }
            simHand[i] = card;
            i++;
            if(i == 5)
            {
                numDealt++;
                int handVal = classifyHand(simHand, 5);
                if(handVal == 9)
                {
                    RF++;
                }
                else if(handVal == 8)
                {
                    SF++;
                }
                else if(handVal == 7)
                {
                    FoaK++;
                }
                else if(handVal == 6)
                {
                    FH++;
                }
                else if(handVal == 5)
                {
                    F++;
                }
                else if(handVal == 4)
                {
                    S++;
                }
                else if(handVal == 3)
                {
                    ToaK++;
                }
                else if(handVal == 2)
                {
                    TP++;
                }
                else if (handVal == 1)
                {
                    TwoaK++;
                }
                else
                {
                   HC++;
                }
                i = 0;
                simHand[0] = 52;
                simHand[1] = 52;
                simHand[2] = 52;
                simHand[3] = 52;
                simHand[4] = 52;
            }
        }
        cout << "Hand Name" << "                " << "Dealt" << "         " << "Chance" << endl;
        cout << "Royal Flush" << setw(19) << RF << setw(15) << fixed << setprecision(6) << ((double(RF)/double(numDealt))*100) << "%" << endl;
        cout << "Straight Flush" << setw(16) << SF << setw(15) << fixed << setprecision(6) << ((double(SF)/double(numDealt))*100) << "%" << endl;
        cout << "Four of a Kind" << setw(16) << FoaK << setw(15) << fixed << setprecision(6) << ((double(FoaK)/double(numDealt))*100) << "%" << endl;
        cout << "Full House" << setw(20) << FH << setw(15) << fixed << setprecision(6) << ((double(FH)/double(numDealt))*100) << "%" << endl;
        cout << "Flush" << setw(25) << F << setw(15) << fixed << setprecision(6) << ((double(F)/double(numDealt))*100) << "%" << endl;
        cout << "Straights" << setw(21) << S << setw(15) << fixed << setprecision(6) << ((double(S)/double(numDealt))*100) << "%" << endl;
        cout << "Three of a Kind" << setw(15) << ToaK << setw(15) << fixed << setprecision(6) << ((double(ToaK)/double(numDealt))*100) << "%" << endl;
        cout << "Two Pair" << setw(22) << TP << setw(15) << fixed << setprecision(6) << ((double(TP)/double(numDealt))*100) << "%" << endl;
        cout << "Two of a Kind" << setw(17) << TwoaK << setw(15) << fixed << setprecision(6) << ((double(TwoaK)/double(numDealt))*100) << "%" << endl;
        cout << "High Card" << setw(21) << HC << setw(15) << fixed << setprecision(6) << ((double(HC)/double(numDealt))*100) << "%" << endl;
        cout << endl;
        cout << "Total Hands Dealt" << setw(13) << numDealt << endl;
        
    }
    else
    {
        cout << "Invalid Option" << endl;
        return 0;
    }
    
    return 0;
}

TEST_CASE("classifyHand- Series of test cases for my classifyHand function. Each CHECK corresponds to one type of hand, and additional testing for each bool function used is found below.")
{
    int twoPairHandT[5] = {0, 26, 25, 34, 51};
    int twoPairHandF[5] = {0, 27, 28, 34, 51};
    int twoOfAKindHandT[5] = {0, 26, 28, 34, 51};
    int twoOfAKindHandF[5] = {0, 27, 28, 34, 51};
    int threeOfAKindHandT[5] = {0, 26, 13, 34, 51};
    int threeOfAKindHandF[5] = {0, 27, 28, 34, 51};
    int straightHandT[5] = {0, 1, 2, 3, 17};
    int straightHandF[5] = {0, 27, 28, 34, 51};
    int flushHandT[5] = {0, 1, 2, 3, 5};
    int flushHandF[5] = {0, 27, 28, 34, 51};
    int fullhouseHandT[5] = {0, 13, 17, 30, 43};
    int fullhouseHandF[5] = {0, 27, 28, 34, 51};
    int fourOfAKindHandT[5] = {0, 26, 13, 39, 51};
    int fourOfAKindHandF[5] = {0, 27, 28, 34, 51};
    int straightFlushHandT[5] = {0, 1, 2, 3, 4};
    int straightFlushHandF[5] = {0, 27, 28, 34, 51};
    int royalFlushHandT[5] = {51, 50, 49, 48, 47};
    int royalFlushHandF[5] = {0, 27, 28, 34, 51};
    
    CHECK(isTwoOfAKind(twoOfAKindHandT, 5));
    CHECK(!(isTwoOfAKind(twoOfAKindHandF, 5)));
    CHECK(isTwoPair(twoPairHandT, 5));
    CHECK(!(isTwoPair(twoPairHandF, 5)));
    CHECK(isThreeOfAKind(threeOfAKindHandT, 5));
    CHECK(!(isThreeOfAKind(threeOfAKindHandF, 5)));
    CHECK(isStraight(straightHandT, 5));
    CHECK(!(isStraight(straightHandF, 5)));
    CHECK(isFlush(flushHandT, 5));
    CHECK(!(isFlush(flushHandF, 5)));
    CHECK(isFullhouse(fullhouseHandT, 5));
    CHECK(!(isFullhouse(fullhouseHandF, 5)));
    CHECK(isFourOfAKind(fourOfAKindHandT, 5));
    CHECK(!(isFourOfAKind(fourOfAKindHandF, 5)));
    CHECK(isStraightFlush(straightFlushHandT, 5));
    CHECK(!(isStraightFlush(straightFlushHandF, 5)));
    CHECK(isRoyalFlush(royalFlushHandT, 5));
    CHECK(!(isRoyalFlush(royalFlushHandF, 5)));
    CHECK(classifyHand(twoOfAKindHandT, 5) == 1);
    CHECK(classifyHand(twoPairHandT, 5) == 2);
    CHECK(classifyHand(threeOfAKindHandT, 5) == 3);
    CHECK(classifyHand(straightHandT, 5) == 4);
    CHECK(classifyHand(flushHandT, 5) == 5);
    CHECK(classifyHand(fullhouseHandT, 5) == 6);
    CHECK(classifyHand(fourOfAKindHandT, 5) == 7);
    CHECK(classifyHand(straightFlushHandT, 5) == 8);
    CHECK(classifyHand(royalFlushHandT, 5) == 9);    
}

TEST_CASE("isTwoOfAKind - Series of test cases for my isTwoOfAKind function")
{
    int size = 5;
    int hand1[5] = {0, 26, 28, 34, 51};
    int hand2[5] = {0, 27, 28, 34, 51};
    int hand3[5] = {0, 27, 28, 34, 40};
    
    CHECK((isTwoOfAKind(hand1, size)));
    CHECK(!(isTwoOfAKind(hand2, size)));
    CHECK((isTwoOfAKind(hand3, size)));
}

TEST_CASE("isTwoPair - Series of test cases for my isTwoPair function")
{
    int size = 5;
    int hand1[5] = {0, 26, 25, 34, 51};
    int hand2[5] = {0, 27, 28, 34, 51};
    int hand3[5] = {0, 27, 28, 34, 40};
    
    CHECK((isTwoPair(hand1, size)));
    CHECK(!(isTwoPair(hand2, size)));
    CHECK(!(isTwoPair(hand3, size)));
}

TEST_CASE("isThreeOfAKind - Series of test cases for my isThreeOfAKind function")
{
    int size = 5;
    int hand1[5] = {0, 26, 13, 34, 51};
    int hand2[5] = {0, 27, 28, 34, 51};
    int hand3[5] = {14, 27, 28, 34, 40};
    
    CHECK((isThreeOfAKind(hand1, size)));
    CHECK(!(isThreeOfAKind(hand2, size)));
    CHECK((isThreeOfAKind(hand3, size)));
}

TEST_CASE("isStraight - Series of test cases for my isStraight function")
{
    int size = 5;
    int hand1[5] = {0, 1, 2, 4, 3};
    int hand2[5] = {0, 28, 14, 42, 51};
    int hand3[5] = {0, 4, 42, 28, 14};
    
    CHECK((isStraight(hand1, size)));
    CHECK(!(isStraight(hand2, size)));
    CHECK((isStraight(hand3, size)));
}

TEST_CASE("isFlush - Series of test cases for my isFlush function")
{
    int size = 5;
    int hand1[5] = {0, 1, 2, 4, 3};
    int hand2[5] = {0, 28, 14, 42, 51};
    int hand3[5] = {0, 4, 42, 28, 14};
    
    CHECK((isFlush(hand1, size)));
    CHECK(!(isFlush(hand2, size)));
    CHECK(!(isFlush(hand3, size)));
}

TEST_CASE("isFullhouse - Series of test cases for my isFullhouse function")
{
    int size = 5;
    int hand1[5] = {0, 13, 17, 30, 43};
    int hand2[5] = {0, 28, 14, 42, 51};
    int hand3[5] = {12, 25, 38, 31, 44};
    
    CHECK((isFullhouse(hand1, size)));
    CHECK(!(isFullhouse(hand2, size)));
    CHECK((isFullhouse(hand3, size)));
}

TEST_CASE("isFourOfAKind - Series of test cases for my isFourOfAKind function")
{
    int size = 5;
    int hand1[5] = {0, 26, 13, 39, 51};
    int hand2[5] = {0, 27, 28, 34, 51};
    int hand3[5] = {14, 27, 1, 34, 40};
    
    CHECK((isFourOfAKind(hand1, size)));
    CHECK(!(isFourOfAKind(hand2, size)));
    CHECK((isFourOfAKind(hand3, size)));
}

TEST_CASE("isStraightFlush - Series of test cases for my isStraightFlush function")
{
    int size = 5;
    int hand1[5] = {0, 1, 2, 3, 4};
    int hand2[5] = {0, 27, 28, 34, 51};
    int hand3[5] = {51, 50, 49, 48, 47};
    
    CHECK((isStraightFlush(hand1, size)));
    CHECK(!(isStraightFlush(hand2, size)));
    CHECK((isStraightFlush(hand3, size)));
}

TEST_CASE("isRoyalFlush - Series of test cases for my isRoyalFlush function")
{
    int size = 5;
    int hand1[5] = {0, 1, 2, 3, 4};
    int hand2[5] = {0, 27, 28, 34, 51};
    int hand3[5] = {51, 50, 49, 48, 47};
    
    CHECK(!(isRoyalFlush(hand1, size)));
    CHECK(!(isRoyalFlush(hand2, size)));
    CHECK((isRoyalFlush(hand3, size)));
}
