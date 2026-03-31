// #include "constants.h"
#include "hand_stuff.h"
#include "prepare_game.h"


// hand_stuff.c prototypes
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


// prepare_game.c prototypes
struct Card* load_deck();
struct Card* shuffle_deck(struct Card* deck);
struct Card* deal_hand(struct Card* deck);
bool is_in_range(char c, char min, char max);
void get_string_input(char *buffer, int buffer_size);




void test_prints() {

    printf("\n-------------------------------\n");
    printf("| >>> START TEST FUNCTION <<< |\n");
    printf("-------------------------------\n\n");
    int suit_size = (sizeof(SUITS) / sizeof(SUITS[0]));

    printf("* Printing suits... ");
    for(int i=0; i<suit_size; i++) {
        printf("%s ", SUITS[i]);
    }
    printf("\n\n");

    printf("* Single suit assignment print... ");
    const char* test = SUITS[0];
    printf("%s\n\n", test);

    printf("* Testing get_random_num function... ");
    for(int i=0; i<10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");


    
    printf("* Create Card struct instance... ");
    struct Card card;
    card.num = "5";
    card.suit = SUITS[1];
    printf("%s ", card.num);
    printf("%s \n", card.suit);


    printf("\n-----------------------------\n");
    printf("| >>> END TEST FUNCTION <<< |\n");
    printf("-----------------------------\n\n");
}




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



void determineWinner(struct Card* hand) {
    printf("> Determining Winner...\n\n");
    // print_hand(hand);
}



void determineHand(struct Card* hand) {
    print_hand(hand);


    if(isRoyalFlush(hand) == true) {
        printf("ROYAL FLUSH!\n");
    } else if(isStraightFlush(hand) == true) {
        printf("STRAIGHT FLUSH\n");
    } else if(isFourOfAKind(hand) == true) {
        printf("--FOUR OF A KIND--\n");
    } else if(isFullHouse(hand) == true) {
        printf("--FULL HOUSE--\n");
    } else if(isStraight(hand) == true) {
        printf("--STRAIGHT--\n");
    } else if(isThreeOfAKind(hand) == true) {
        printf("--THREE OF A KIND--\n");
    } else if(isTwoPair(hand) == true) {
        printf("--Two Pair--\n");
    } else if(isOnePair(hand) == true) {
        printf("--ONE PAIR--\n");
    } else {
        printf("--youre a loser--\n");
    }
}



int main() {
    srand((unsigned)time(NULL));

    // test_prints();

    int money = 1000;
    int bet = 0;
    int pot = 0;

    bool playAgain = true;

    char playAgainInput[100] = "y";
    char playerName[100];

    struct Card* deck;
    struct Card* hand;


    system("clear");
    printf("Tyler's Seven C's Poker Project!\n\n");
    printf("Enter your name \n> ");
    scanf("%s", playerName);
    printf("\nWelcome, %s!\n\n", playerName);
    while (getchar() != '\n' && getchar() != EOF);

    deck = load_deck();


    while(playAgain == true) {

        deck = shuffle_deck(deck);   
        hand = deal_hand(deck);

        

        hand = insertion_sort_hand(hand);
        print_hand(hand);
        bool *new_cards_bool = redraw();
        print_hand(hand);
        int index = 5;

        // get new cards from the deck
        for(int i=0; i<5; i++) {
            if(new_cards_bool[i] == true) {
                hand[i] = deck[index];
                index++;
            }
        }

        hand = insertion_sort_hand(hand);
        print_hand(hand);

        // full house
        // hand[0].num = NUMS[12];   // 7
        // hand[0].suit = SUITS[0];

        // hand[1].num = NUMS[6];   // 7
        // hand[1].suit = SUITS[1];

        // hand[2].num = NUMS[6];   // 7
        // hand[2].suit = SUITS[2];

        // hand[3].num = NUMS[12];  // A
        // hand[3].suit = SUITS[2]; // h

        // hand[4].num = NUMS[12];  // A
        // hand[4].suit = SUITS[3]; // s


        
        determineHand(hand);
        printf("\n*************************************\n\n");


        
        printf("Do you want to play another hand(y/N)? \n> ");
        fgets(playAgainInput, sizeof(playAgainInput), stdin);

        if(playAgainInput[0] == 'n' || playAgainInput[0] == 'N') {
            playAgain = false;
        }
        printf("END GAME LOOP\n");
    } // end game loop

    printf("bye bye...");











    printf("\n\n");
    return 0;
}