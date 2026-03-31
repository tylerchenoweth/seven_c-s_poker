#include "hand_stuff.h"


// internal function
int get_index(struct Card card) {
    for(int i=0; i<13; i++) {
        if(card.num == NUMS[i]) {
            return i;
        }
    }

    return -1; // Return -1 if the card number is not found
}



// this is a reusable function for hand functions to check for pairs
bool isPair(struct Card* hand, int index) {
    if(hand[index].num == hand[index+1].num) {
        return true;
    } else {
        return false;
    }
}


// next three functions are actual hands and reusable functions
//  for the other hands functions
bool isFlush(struct Card* hand) {
    // printf("allsuits\n");
    for(int i=1; i<5; i++) {
        // printf("%s - %s", hand[0].suit, hand[i].suit);
        if(hand[0].suit != hand[i].suit) {
            return false;
        }
    }

    return true;
}


bool isStraight(struct Card* hand) {
    for(int i=0; i<4; i++) {
        if(get_index(hand[i])+1 != get_index(hand[i+1])) {
            return false;
        }
    }

    return true;
}


bool isSet(struct Card* hand, int index) {
    if(isPair(hand, index) == true && isPair(hand, index+1) == true) {
        return true;
    } else {
        return false;
    }
}


// below are the functions to check for hands
bool isRoyalFlush(struct Card* hand) {
    if(isFlush(hand) == true && isStraight(hand) == true && strcmp(hand[0].num, "10") == 0) {
        return true;
    } else {
        return false;
    }
}


bool isStraightFlush(struct Card* hand) {
    if(isStraight(hand) == true && isFlush(hand) == true) {
        return true;
    } else {
        return false;
    }
}


bool isStraighFlush(struct Card* hand) {
    if(isFlush(hand) == true && isStraight(hand) == true) {
        return true;
    } else {
        return false;
    }
}


bool isFourOfAKind(struct Card* hand) {
    for(int i=0; i<3; i++) {
        if(hand[i].num != hand[i+1].num) {
            break;
        }else if(i == 2) {
            return true;
        }
    }

    for(int i=1; i<4; i++) {
        if(hand[i].num != hand[i+1].num) {
            break;
        } else if(i == 3) {
            return true;
        }
    }

    return false;
}


bool isFullHouse(struct Card* hand) {
    if(isPair(hand, 0) == true && isSet(hand, 2) == true) {
        return true;
    } else if(isPair(hand, 3) == true && isSet(hand, 0) == true) {
        return true;
    } else {
        return false;
    }
}


bool isThreeOfAKind(struct Card* hand) {
    for(int i=0; i<3; i++) {
        if(isSet(hand, i) == true) {
            return true;
        }
    }

    return false;
}


bool isTwoPair(struct Card* hand) {
    if(isPair(hand, 0) == true && isPair(hand, 2) == true) {
        return true;
    } else if(isPair(hand, 0) == true && isPair(hand, 3) == true) {
        return true;
    } else if(isPair(hand, 1) == true && isPair(hand, 3) == true) {
        return true;
    } else {
        return false;
    }
}


bool isOnePair(struct Card* hand) {
    for(int i=0; i<4; i++) {
        if(isPair(hand, i) == true) {
            return true;
        }
    }

    return false;
}