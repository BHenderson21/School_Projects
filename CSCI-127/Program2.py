# -----------------------------------------+
# Your name                                |
# CSCI 127, Program 2                      |
# Last Updated: Month __, 20__             |
# Name:                                    |
# -----------------------------------------|
# Poker Hand Evaluation                    |
# -----------------------------------------+

# Helper Function
# Given a poker hand as a list, return a list of the ranks
def getAllRanks(hand):
    result = []
    for card in hand:
        result.append(card[0])
    return result

# Another helper function, similar to get ranks, but get suits
def getAllSuits(hand):
    result = []
    for card in hand:
        result.append(card[1])
    return result
    
# TODO:
# decide on parameters for the hand evaluation functions, and
# define functions to return True if the criteria is met; false otherwise.

# Tests to see if the cards are the 5 highest value cards, consecutive.
def royal_flush(hand):
    ranksSeen = getAllRanks(hand)
    ranksSeen.sort()
    suitsSeen = getAllSuits(hand)
    if(ranksSeen[4] == 14):
       if (bool(straight(hand)) and (suitsSeen.count(suitsSeen[0]) == 5)):
        return True
    return False 

# Tests for a straight by calling the straight function, and also checks if all belong to the same suit
def straight_flush(hand):
    suitsSeen = getAllSuits(hand)
    if (bool(straight(hand)) and (suitsSeen.count(suitsSeen[0]) == 5)):
        return True
    return False

# Tests to see if the 5 cards in the hand are all consecutive numbers.
def straight(hand):
    ranksSeen = getAllRanks(hand)
    ranksSeen.sort()

    firstCard = ranksSeen[0]
    secondCard = ranksSeen[1]
    thirdCard = ranksSeen[2]
    fourthCard = ranksSeen[3]
    fifthCard = ranksSeen[4]

    if ((secondCard == firstCard + 1) and (thirdCard == secondCard + 1) and (fourthCard == thirdCard + 1) and (fifthCard == fourthCard + 1)):
        return True
    else:
        return False

# Tests for 4 cards belonging to the same rank.
def four_of_a_kind(hand):
    ranksSeen = getAllRanks(hand)
    for i in ranksSeen:
        if ranksSeen.count(i) == 4:
            return True
        else:
            continue
    return False

# Test to see if there are is combination of a pair and 3 of a kind in one hand.
def full_house(hand):
    ranksSeen = getAllRanks(hand)
    ranksSeen.sort()
    if (ranksSeen.count(ranksSeen[0]) == 2 and ranksSeen.count(ranksSeen[2]) == 3) or (ranksSeen.count(ranksSeen[0]) == 3 and ranksSeen.count(ranksSeen[3]) == 2):
        return True
    else:
        return False

# Tests to see if all 5 cards belong to the same suit.
def flush(hand):
    suitsSeen = getAllSuits(hand)
    for i in suitsSeen:
        if suitsSeen.count(i) == 5:
            return True
        else:
            return False

# Tests for any triplets in rank.
def three_of_a_kind(hand):
    ranksSeen = getAllRanks(hand)
    for i in ranksSeen:
        if ranksSeen.count(i) == 3:
            return True
        else:
            continue
    return False

# See's if theres 2 pairs, by checking for duplicate ranks, and counting how many duplicates there are, and returning true if 2 pairs are reached.
def two_pair(hand):
    ranksSeen = getAllRanks(hand)
    pairs = 0
    for i in ranksSeen:
        if ranksSeen.count(i) == 2:
            pairs += 1
            if pairs == 2:
                return True
            else:
                ranksSeen.remove(i)
                continue
    return False

# See's if there is a pair in the hand, by seeing if theres 2 of any ranks.            
def pair(hand):
    ranksSeen = getAllRanks(hand)
    for i in ranksSeen:
        if ranksSeen.count(i) == 2:
            return True
        else:
            continue
    return False


# -----------------------------------------+
# Do not modify the evaluate function.     |
# -----------------------------------------+

def evaluate(poker_hand):
    poker_hand.sort() 
    print(poker_hand, " is ", end="")
    if royal_flush(poker_hand):
        print("a Royal Flush")
    elif straight_flush(poker_hand):
        print("a Straight Flush")
    elif four_of_a_kind(poker_hand):
        print("a Four of a Kind")
    elif full_house(poker_hand):
        print("a Full House")
    elif flush(poker_hand):
        print("a Flush")
    elif straight(poker_hand):
        print("a Straight")
    elif three_of_a_kind(poker_hand):
        print("Three of a Kind")
    elif two_pair(poker_hand):
        print("Two Pair")
    elif pair(poker_hand):
        print("a Pair")
    else:
        print("Nothing")
		
# -----------------------------------------+

def main():
    T = 10
    J = 11
    Q = 12
    K = 13
    A = 14
    print("CSCI 127: Poker Hand Evaluation Program")
    print("---------------------------------------")
    evaluate([[2, "spd"], [7, "clb"], [8, "dmd"], [A, "dmd"], [Q, "hrt"]])    # nothing
    evaluate([[T, "spd"], [A, "spd"], [Q, "spd"], [K, "spd"], [J, "spd"]])    # royal flush
    evaluate([[T, "clb"], [9, "clb"], [6, "clb"], [7, "clb"], [8, "clb"]])    # straight flush
    evaluate([[2, "dmd"], [7, "clb"], [2, "hrt"], [2, "clb"], [2, "spd"]])    # 4 of a kind
    evaluate([[8, "dmd"], [7, "clb"], [8, "hrt"], [8, "clb"], [7, "spd"]])    # full house
    evaluate([[2, "hrt"], [9, "hrt"], [3, "hrt"], [6, "hrt"], [T, "hrt"]])    # flush    
    evaluate([[K, "dmd"], [7, "clb"], [7, "hrt"], [8, "clb"], [7, "spd"]])    # 3 of a kind
    evaluate([[T, "clb"], [9, "clb"], [6, "clb"], [7, "clb"], [8, "spd"]])    # straight
    evaluate([[T, "spd"], [9, "clb"], [6, "dmd"], [9, "dmd"], [6, "hrt"]])    # 2 pair
    evaluate([[T, "spd"], [Q, "clb"], [6, "dmd"], [9, "dmd"], [Q, "hrt"]])    # 1 pair


# -----------------------------------------+

main()