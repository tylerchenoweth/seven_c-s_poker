
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>
#include <ctype.h>



struct Card {
    const char* num;
    const char* suit;
};

extern const char* SUITS[4];
extern const char* NUMS[13];


#endif