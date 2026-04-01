#include "prepare_game.h"
#include "hand_stuff.h"
#include "gameplay.h"




bool* redraw() {

    // allocate memory for bool arr
    bool* new_cards_bool = (bool*)malloc(5 * sizeof(bool));

    if (new_cards_bool == NULL) {
        // Handle allocation failure
        return NULL;
    }

    bool valid_input = false;

    do {
        char new_hand_input[10];
        bool has_zero = false;
        bool has_nums = false;
        valid_input = true;

        // load bool array as all false
        for (int i = 0; i < 5; i++) {
            new_cards_bool[i] = false;
        }
        
        printf("List cards you want to discard and redraw \n");
        printf("- Enter 0 to discard and redraw all cards\n");
        printf("- Enter 1-5 to indicate the card you want to discard and redraw\n");
        printf("- Please only use numbers and spaces\n");
        printf("> ");
        get_string_input(new_hand_input, sizeof(new_hand_input));
        
        for(size_t i=0; i<strlen(new_hand_input); i++) {
            if(is_in_range(new_hand_input[i], '1','5')) {
                if(has_zero == true) {
                    printf("Invalid input. You entered a 0 and a number(s) between 1-5...\n");
                    valid_input = false;
                } else {
                    has_nums = true;
                }
            } else if(new_hand_input[i] == '0') {
                if(has_nums == true) {
                    printf("Invalid input. You entered a 0 and a number(s) between 1-5...\n");
                    valid_input = false;
                } else {
                    has_zero = true;
                }
            } else {
                if(new_hand_input[i] != ' ') {
                    printf("Invalid character\n");
                    valid_input = false;
                }
            }
        }

        if(has_zero == true && has_nums == false) {
            for (int i = 0; i < 5; i++) {
                new_cards_bool[i] = true;
            }
        } else if(valid_input == true) {
            for(size_t i=0; i<strlen(new_hand_input); i++) {
                if(new_hand_input[i] == ' ') {
                    continue;
                } else {
                    int index = new_hand_input[i] - '0';
                    index -= 1;
                    if(new_cards_bool[index] == 1) {
                        printf("> You entered duplicate inputs... %d\n", new_cards_bool[index]);
                        valid_input = false;
                    } else {
                        new_cards_bool[index] = true;
                    }
                }
            }  
        }   
    } while(valid_input == false);

    return new_cards_bool;
}



// insertion sort
struct Card* insertion_sort_hand(struct Card* hand) {
    
    int n = 5;

    for(int i=1; i<n; i++) {
        struct Card key = hand[i];

        int j = i - 1;

        while(j >= 0 && get_index(hand[j]) > get_index(key)) {
            hand[j+1] = hand[j];
            j = j - 1;
        }

        hand[j+1] = key;
    }

    return hand;
}




void print_hand(struct Card* hand) {
    printf("\n");
    printf("1:    2:    3:    4:    5:\n");
    printf("---------------------------\n");
    for(int i=0; i<5; i++) {
        printf("%s %s", hand[i].num, hand[i].suit);
        if(i != 4) {
            printf(" - ");
        }
    }
    printf("\n\n");
}







int determineHand(struct Card* hand) {
    print_hand(hand);


    if(isRoyalFlush(hand) == true) {
        printf("--ROYAL FLUSH!--\n");
        return 100;
    } else if(isStraightFlush(hand) == true) {
        printf("--STRAIGHT FLUSH--\n");
        return 50;
    } else if(isFourOfAKind(hand) == true) {
        printf("--FOUR OF A KIND--\n");
        return 20;
    } else if(isFullHouse(hand) == true) {
        printf("--FULL HOUSE--\n");
        return 7;
    }  else if(isFlush(hand) == true) {
        printf("--FLUSH--\n");
        return 5;
    } else if(isStraight(hand) == true) {
        printf("--STRAIGHT--\n");
        return 4;
    } else if(isThreeOfAKind(hand) == true) {
        printf("--THREE OF A KIND--\n");
        return 3;
    } else if(isTwoPair(hand) == true) {
        printf("--TWO PAIR--\n");
        return 2;
    } else if(isOnePair(hand) == true) {
        printf("----------------\n");
        printf("|-- ONE PAIR --|\n");
        printf("----------------\n");
        return 1;
    } else {
        printf("--youre a loser--\n");
        return 0;
    }
}


int determineWinner(struct Card* hand, int bet) {
    printf("> Determining Winner...\n\n");
    
    int winningsX = determineHand(hand);

    if(winningsX == 0) {
        return 0;
    } else {
        return ((bet * winningsX) + bet);
    }
}