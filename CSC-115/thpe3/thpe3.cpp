/** **************************************************************************************
* @file
*****************************************************************************************/
#include "thpe3.h"

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, classifys the hand based on poker rules
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns An int containing the numerical score of the hand classification
 *
 *  @par Example
 *  @verbatim
    
    int result;
    hand[5] = {0, 1, 2, 3, 4};
    handRF[5] = {8, 9, 10, 11, 12};
 
    result = classifyHand(hand, 5); // result would be 4, representing a straight.
    
    result = classifyHand(handRF, 5); // result would be 9, representing a royal flush.
    
 *  @endverbatim
************************************************************************/

int classifyHand(int hand[], int handSize)
{
    if(isRoyalFlush(hand, handSize))
    {
        return royalFlush;
    }
    else if(isStraightFlush(hand, handSize))
    {
        return straightFlush;
    }
    else if(isFourOfAKind(hand, handSize))
    {
        return fourOfAKind;
    }
    else if(isFullhouse(hand, handSize))
    {
        return fullHouse;
    }
    else if(isFlush(hand, handSize))
    {
        return Flush;
    }
    else if(isStraight(hand, handSize))
    {
        return straight;
    }
    else if(isThreeOfAKind(hand, handSize))
    {
        return threeOfAKind;
    }
    else if(isTwoPair(hand, handSize))
    {
        return twoPair;
    }
    else if(isTwoOfAKind(hand, handSize))
    {
        return twoOfAKind;
    }
    else
    {
        return highCard;
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a pair.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a pair
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 14, 3, 4};
    hand2[5] = {8, 9, 10, 11, 12};
 
    result = isTwoOfAKind(hand, 5); // result would be true.
    
    result = isTwoOfAKind(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isTwoOfAKind(int hand[], int handSize)
{
    int i, j;
    int currentPair;
    for(i = 0; i < (handSize - 1); i++)
    {
        currentPair = (hand[i]);
        for(j = i + 1; j < handSize; j ++)
        {
            if(((hand[j]%13) == (currentPair%13)))
            {
                return true;
            }
        }
    }
    return false;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains two pairs.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is two pairs
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 14, 3, 16};
    hand2[5] = {8, 9, 10, 11, 12};
 
    result = isTwoPair(hand, 5); // result would be true.
    
    result = isTwoPair(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isTwoPair(int hand[], int handSize)
{
    int i, j;
    int pairs = 0;
    int currentPair;
    for(i = 0; i < (handSize - 1); i++)
    {
        currentPair = (hand[i]);
        for(j = i + 1; j < handSize; j ++)
        {
            if(((hand[j]%13) == (currentPair%13)))
            {
                pairs++;
            }
        }
    }
    if(pairs == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a triplet
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a triplet
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 14, 27, 4};
    hand2[5] = {8, 9, 10, 11, 12};
 
    result = isThreeOfAKind(hand, 5); // result would be true.
    
    result = isThreeOfAKind(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isThreeOfAKind(int hand[], int handSize)
{
    int i, j;
    int howMany = 0;
    for(i = 0; i < (handSize - 1); i++)
    {
        howMany++;
        for(j = i + 1; j < handSize; j ++)
        {
            if(((hand[j]%13) == (hand[i]%13)))
            {
                howMany++;
            }
        }
        if(howMany == 3)
        {
            return true;
        }
        howMany = 0;
    }
    return false;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a straight.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a straight
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 2, 3, 4};
    hand2[5] = {8, 9, 10, 11, 1};
 
    result = isTwoOfAKind(hand, 5); // result would be true.
    
    result = isTwoOfAKind(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isStraight(int hand[], int handSize)
{
    int i, j;
    int currentMin;
    int ranksInHand[5];
    for(i = 0; i < handSize; i++)
    {
        ranksInHand[i] = (hand[i]) % 13;
    }
    
    for(i=0; i < handSize; i++)
    {
        currentMin = i;
        for(j=i+1; j<handSize; j++)
        {
            if(ranksInHand[j] < ranksInHand[currentMin])
            {
                currentMin = j;
            }
        }
        swap(ranksInHand[i], ranksInHand[currentMin]);
    }
    i = 0;
    while(i < handSize-1)
    {
        if(ranksInHand[i] + 1 == ranksInHand[i+1])
        {
            i++;
        }
        else if(ranksInHand[0] == 0 && ranksInHand[1] == 9 && ranksInHand[2] == 10 && ranksInHand[3] == 11 && ranksInHand[4] == 12)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a flush.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a flush
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 2, 3, 4;
    hand2[5] = {8, 9, 10, 11, 13};
 
    result = isFlush(hand, 5); // result would be true.
    
    result = isFlush(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isFlush(int hand[], int handSize)
{
    int i;
    for(i = 0; i < handSize - 1; i++)
    {
        if(hand[i]/13 != hand[i+1]/13)
        {
            return false;
        }
    }
    return true;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a full house.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a full house
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 2, 40, 41};
    hand2[5] = {8, 9, 10, 11, 13};
 
    result = isFullhouse(hand, 5); // result would be true.
    
    result = isFullhouse(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isFullhouse(int hand[], int handSize)
{
    int i, j;
    int currentMin;
    int ranksInHand[5];
    for(i = 0; i < handSize; i++)
    {
        ranksInHand[i] = (hand[i]) % 13;
    }

    for(i=0; i < handSize; i++)
    {
        currentMin = i;
        for(j=i+1; j<handSize; j++)
        {
            if(ranksInHand[j] < ranksInHand[currentMin])
            {
                currentMin = j;
            }
        }
        swap(ranksInHand[i], ranksInHand[currentMin]);
    }
    if(((ranksInHand[0] == ranksInHand[1]) && (ranksInHand[2] == ranksInHand[3])) && (ranksInHand[3] == ranksInHand[4]))
    {
        return true;
    }
    else if(((ranksInHand[0] == ranksInHand[1]) && (ranksInHand[1] == ranksInHand[2])) && (ranksInHand[3] == ranksInHand[4]))
    {
        return true;
    }
    return false;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a four of a kind.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a four of a kind
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 13, 26, 39, 4;
    hand2[5] = {8, 9, 10, 11, 13};
 
    result = isFourOfAKind(hand, 5); // result would be true.
    
    result = isFourOfAKind(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isFourOfAKind(int hand[], int handSize)
{
    int i, j;
    int howMany = 0;
    for(i = 0; i < (handSize - 1); i++)
    {
        howMany++;
        for(j = i + 1; j < handSize; j ++)
        {
            if(((hand[j]%13) == (hand[i]%13)))
            {
                howMany++;
            }
        }
        if(howMany == 4)
        {
            return true;
        }
        howMany = 0;
    }
    return false;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a straight flush.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a flush
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 2, 3, 4;
    hand2[5] = {8, 9, 10, 11, 13};
 
    result = isStraightFlush(hand, 5); // result would be true.
    
    result = isStraightFlush(hand2, 5); // result would be false.
    
 *  @endverbatim
************************************************************************/

bool isStraightFlush(int hand[], int handSize)
{
    if((isStraight(hand, handSize)) && (isFlush(hand, handSize)))
    {
        return true;
    }
    return false;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an array representing 5 poker cards, indicates if the hand contains a royal flush.
 *
 *  @param[in] hand An array of 5 integers, 0-51, representing cards
 *             handSize An int containing the size of the hand.
 *
 *  @returns A bool, indicating if there is a royal flush
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    hand[5] = {0, 1, 2, 3, 4;
    hand2[5] = {47, 48, 49, 50, 51};
 
    result = isRoyalFlush(hand, 5); // result would be false.
    
    result = isRoyalFlush(hand2, 5); // result would be true.
    
 *  @endverbatim
************************************************************************/

bool isRoyalFlush(int hand[], int handSize)
{
    int i;
    if(isStraightFlush(hand, handSize))
    {
        for(i = 0; i < handSize; i++)
        {
            if(hand[i] == 51 || hand[i] == 38 || hand[i] == 25 || hand[i] == 12)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an file stream and a file name, opens the file to the stream
 *
 *  @param[in] fin An input stream
 *             fileName A file name
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
    fin.open(fileName);
    if(!fin.is_open())
    {
        cout << "Unable to open the file: " << fileName << endl;
        return false;
    }
    return true;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Given an file stream and a file name, opens the file to the stream
 *
 *  @param[in] fout An output stream
 *             fileName A file name
 *
 *  @returns A bool, indicating if the file was successfully opened
 *
 *  @par Example
 *  @verbatim
    
    bool result;
    ofsteam fout;
    name = "test.txt";
    name2 = "test";
    
    result = openOutput(fin, name); // result would be true
    
    result = openOutput(fin, name2); // result would be false. 
    
    
 *  @endverbatim
************************************************************************/

bool openOutput(ofstream& fout, string fileName)
{
    fout.open(fileName);
    if(!fout.is_open())
    {
        cout << "Unable to open the file: " << fileName << endl;
        return false;
    }
    return true;
}


