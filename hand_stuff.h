#ifndef HAND_STUFF_H
#define HAND_STUFF_H

#include "constants.h"


int get_index(struct Card card);

bool isPair(struct Card* hand, int index);
bool isSet(struct Card* hand, int index);

bool isFlush(struct Card* hand);
bool isStraight(struct Card* hand);

bool isRoyalFlush(struct Card* hand);
bool isStraightFlush(struct Card* hand);
bool isFourOfAKind(struct Card* hand);
bool isFullHouse(struct Card* hand);
bool isThreeOfAKind(struct Card* hand);
bool isTwoPair(struct Card* hand);
bool isOnePair(struct Card* hand);


#endif