#include "prepare_game.h"


int get_random_num(size_t max_num) {
    int num = (rand() % max_num);

    return num;
}




struct Card* load_deck() {
    printf("> LOADING DECK...\n");
    struct Card* deck = (struct Card*)malloc(52 * sizeof(struct Card));

    if (deck == NULL) {
        return NULL; // Handle allocation failure
    }

    for(int i=0; i<52; i++) {
        deck[i].num = NUMS[i%13];
        deck[i].suit = SUITS[i%4];
    }

    return deck;
}


struct Card* shuffle_deck(struct Card* deck) {
    printf("> SHUFFLING DECK...\n\n");
    int new_deck_order[52];
    bool in_deck;
    int new_num;

    // Create the new deck variable
    struct Card* new_deck = (struct Card*)malloc(52 * sizeof(struct Card));
    if (new_deck == NULL) {
        return NULL; // Handle allocation failure
    }

    // Get 52 numbers in random order
    for(int i=0; i<52; i++) {
        do {
            in_deck = false;
            new_num = get_random_num(52);
            for(int j=0; j<i; j++) {
                if(new_deck_order[j] == new_num) {
                    in_deck = true;
                    break;
                }
            }
        } while(in_deck == true);
        new_deck_order[i] = new_num;
    }

    // Load the new deck
    for(int i=0; i<52; i++) {
        new_deck[i].num = deck[new_deck_order[i]].num;
        new_deck[i].suit = deck[new_deck_order[i]].suit;

        if(i%13 == 0 && i != 0) {
            // printf("\n");
        }
    }


    // int line_index = 0;
    // int lines_count[6] = {5, 10, 19, 29, 40, 52};

    // for(int i=0; i<52; i++) {

    //     // for(int j=0; j<5; j++) {
    //     //     if(i == lines_count[j]) {
    //     //         printf("\n");
    //     //     }
    //     // }

    //     if(i == lines_count[line_index]) {
    //         printf("\n");
    //         line_index++;
    //     }

    //     printf("%s%s ", new_deck[i].num, new_deck[i].suit);

        
    // }

    // printf("\n\n");
    return new_deck;
}


struct Card* deal_hand(struct Card* deck) {
    struct Card* hand = (struct Card*)malloc(5 * sizeof(struct Card));

    if (deck == NULL) {
        return NULL; // Handle allocation failure
    }

    for(int i=0; i<5; i++) {
        hand[i] = deck[i];
    }

    return hand;
}


// For the redraw function
bool is_in_range(char c, char min, char max) {
    return (c >= min && c <= max);
}


// Function takes a buffer and its size
// For the redraw function
void get_string_input(char *buffer, int buffer_size) {
    // printf("GET STRING NIPUTALKFJLA:FJS:LDJFJD:LSFJ\n\n\n");
    if (fgets(buffer, buffer_size, stdin) != NULL) {
        // Remove newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        
        // printf("You entered: >>>%s<<<\n", buffer);
    } else {
        printf("Error reading input.\n");
    }
}

