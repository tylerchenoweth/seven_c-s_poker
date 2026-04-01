#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "constants.h"


bool* redraw();

// insertion sort
struct Card* insertion_sort_hand(struct Card* hand);

void print_hand(struct Card* hand);
int determineWinner(struct Card* hand, int bet);
int determineHand(struct Card* hand);


#endif