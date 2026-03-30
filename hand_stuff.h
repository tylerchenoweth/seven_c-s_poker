#ifndef HAND_STUFF_H
#define HAND_STUFF_H

#include <stdbool.h>

extern const char* SUITS[4];
extern const char* NUMS[13];

struct Card {
    const char* num;
    const char* suit;
};

int get_index(struct Card card);
bool isPair(struct Card* hand, int index);
bool isFlush(struct Card* hand);
bool isStraight(struct Card* hand);
bool isSet(struct Card* hand, int index);
bool isRoyalFlush(struct Card* hand);
bool isStraightFlush(struct Card* hand);
bool isFourOfAKind(struct Card* hand);
bool isFullHouse(struct Card* hand);
bool isThreeOfAKind(struct Card* hand);
bool isTwoPair(struct Card* hand);
bool isOnePair(struct Card* hand);


#endif