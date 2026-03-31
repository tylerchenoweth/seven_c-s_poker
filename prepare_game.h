#ifndef PREPARE_GAME_H
#define PREPARE_GAME_H

#include "constants.h"


int get_random_num(size_t max_num);

struct Card* load_deck();
struct Card* shuffle_deck(struct Card* deck);
struct Card* deal_hand(struct Card* deck);

// For the redraw function
bool is_in_range(char c, char min, char max);

// Function takes a buffer and its size
// For the redraw function
void get_string_input(char *buffer, int buffer_size);


#endif