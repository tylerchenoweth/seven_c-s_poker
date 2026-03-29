// For the output
#include <stdio.h>

// For the random number generator
#include <time.h>
#include <stdlib.h>

#include <stdbool.h>


// Constants
#define SUIT_SPADES   "\u2660"
#define SUIT_HEARTS   "\u2665"
#define SUIT_DIAMONDS "\u2666"
#define SUIT_CLUBS    "\u2663"

char* SUITS[4] = {
    SUIT_SPADES,
    SUIT_HEARTS,
    SUIT_DIAMONDS,
    SUIT_CLUBS
};

// char* SUITS[4] = {
//     "\u2660",
//     "\u2665",
//     "\u2666",
//     "\u2663"
// };

#define LEFT_EDGE     "| "
#define RIGHT_EDGE    " |"





// char *get_left_edge() {
//     // return {'|', ' '};
//     return "| ";
// }

// char *get_right_edge() {
//     // return {' ', '|'};
//     return " |";
// }

// A hard coded card for testing purposes
void print_test_card() {

    // char *left_edge = get_left_edge();
    // char *right_edge = get_right_edge();

    printf("-----------------\n");
    printf("%s10           %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s   x     x   %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s      x      %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s   x     x   %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s             %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s   x     x   %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s      x      %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s   x     x   %s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("%s           10%s\n", LEFT_EDGE, RIGHT_EDGE);
    printf("-----------------\n");
}

void test() {
    printf("Printing constants...\n");
    printf("%s\n", SUIT_SPADES);
    printf("%s\n", SUIT_HEARTS);
    printf("%s\n", SUIT_DIAMONDS);
    printf("%s\n", SUIT_CLUBS);
    printf("%s\n", LEFT_EDGE);
    printf("%s\n", RIGHT_EDGE);
    printf("\n");
    print_test_card();
}

int get_random_num(int max) {
    return (rand() % max);
}










int* shuffle_deck() {
    srand(time(NULL));

    // int num_of_cards = 52;
    // int* deck = (int*)malloc( num_of_cards * sizeof(int));

    // if (deck == NULL) {
    //     // Handle allocation failure
    //     return NULL;
    // }

    
    int deck[52];
    int card_num;
    bool in_deck = true;

    for(int i=0; i < 52; i++) {
        in_deck = true;

        while(in_deck) {
            card_num = get_random_num(52);
            in_deck = false;

            for(int j=0; j < i; j++) {
                // printf("Comparing %d and %d\n", deck[j], card_num);
                if(deck[j] == card_num) {
                    in_deck = true;
                    break;
                } 
            }

            if(in_deck == false) {
                deck[i] = card_num;
            }     
        }
    }

    return *deck;
}


struct Card {
    int num;
    char* suit;
};


struct Card load_deck(int* shuffle) {

    struct Card deck[52];

    for(int i=0; i<52; i++) {
        deck[i].suit = SUITS[shuffle[i] % 4];
    }

    return *deck;
}





int main() {
    // printf("Hello, World!\n");

    // char *left_edge = get_left_edge();
    // char *right_edge = get_right_edge();

    // print_test_card();



    

    



    struct Card deck[52];

    int shuffle[52];
    shuffle = shuffle_deck();

    for(int i=0; i<52; i++) {
        printf("%d\n",shuffle[i]);
    }

    // deck = load_deck(shuffle);

    // for(int i=0; i<52; i++) {
    //     printf("%d === %d\n", shuffle[i]%13, shuffle[i]%4);
    // }

    
    // test(); 
    
    

    return 0;
}


