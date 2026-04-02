// #include "constants.h"
#include "hand_stuff.h"
#include "prepare_game.h"
#include "db_crud.h"


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
// void get_string_input(char *buffer, int buffer_size);


// gameplay.c prototypes
bool* redraw();
struct Card* insertion_sort_hand(struct Card* hand);
void print_hand_non_fancy(struct Card* hand);
int determineWinner(struct Card* hand, int bet);
int determineHand(struct Card* hand);

// db_crud.c prototypes
PlayerData db_main(void);

// print_hand.c prototypes
void print_hand(struct Card* hand);




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


struct Card* getTestHand(/*int num[], int suit[]*/) {
    struct Card* hand = malloc(5 * sizeof(struct Card));

    // full house
    hand[0].num = NUMS[12];   // 7
    hand[0].suit = SUITS[0];

    hand[1].num = NUMS[6];   // 7
    hand[1].suit = SUITS[1];

    hand[2].num = NUMS[6];   // 7
    hand[2].suit = SUITS[2];

    hand[3].num = NUMS[12];  // A
    hand[3].suit = SUITS[2]; // h

    hand[4].num = NUMS[12];  // A
    hand[4].suit = SUITS[3]; // s

    return hand;
}


int get_bet(int bankroll) {
    int bet;

    printf("Bankroll: $%d\n\n", bankroll);
    printf("Please enter your bet: \n> ");

    while(true) {
        scanf("%d", &bet);

        // this clears any newlines from the previous input
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        // printf("bet: %d\n", bet);
        // printf("money: %d\n", money);

        if(bet > bankroll) {
            printf("You dont have enough money to place that bet. Try again.\n> ");
        } else if(bet <=0) {
            printf("Your bet must be greater than 0. Try again.\n> ");
        } else {
            return bet;
        }
    }

}


int main() {
    
    srand((unsigned)time(NULL));

    int bankroll = 0;
    int bet = 0;
    int pot = 0;

    bool playAgain = true;

    char playAgainInput[100] = "y";
    // char playerName[100];

    struct Card* deck;
    struct Card* hand;


    system("clear");
    printf("--------------------------------------\n");
    printf("|                                    |\n");
    printf("|  Tyler's Seven C's Poker Project!  |\n");
    printf("|                                    |\n");
    printf("--------------------------------------\n\n");
    // printf("Enter your name \n> ");
    // scanf("%s", playerName);
    // char *playerName = db_main();
    PlayerData player = db_main();
    char *playerName = player.playerName;
    bankroll = player.bankroll;
    // printf("main got: %s\n",    );
    printf("\n*** Welcome, %s! ***\n\n", playerName);
    printf("Bankroll: $%d\n\n", bankroll);
    // while (getchar() != '\n' && getchar() != EOF);

    deck = load_deck();


    while(playAgain == true) {

        if(bankroll <= 0) {
            printf("\n>>> You went bust. Go to the bank for a loan. <<<\n\n\n");
            break;
        }

        deck = shuffle_deck(deck);  
        printf("\n\n******* START NEW HAND *******\n\n");
        bet = get_bet(bankroll); 
        bankroll -= bet;
        pot += bet;
        hand = deal_hand(deck);
        hand = insertion_sort_hand(hand);
        printf("\nYOUR HAND: \n");
        print_hand(hand);

        bool *new_cards_bool = redraw();
        int index = 5;

        // get new cards from the deck
        for(int i=0; i<5; i++) {
            if(new_cards_bool[i] == true) {
                hand[i] = deck[index];
                index++;
            }
        }

        hand = insertion_sort_hand(hand);
        printf("\nYOUR NEW HAND:\n");
        print_hand(hand);
        
        int winnings = determineWinner(hand, bet);
        bankroll += winnings;

        printf("\nYou bet: $%d\n", bet);
        if(winnings > 0) {
            printf("You won: $%d\n", winnings);
        } else {
            printf("You lost: $%d\n", bet);
        }
        printf("New Balance: $%d\n\n", bankroll);
        


        if(bankroll > 0) {
            printf("Do you want to play another hand(y/N)? \n> ");
            fgets(playAgainInput, sizeof(playAgainInput), stdin);

            if(playAgainInput[0] == 'n' || playAgainInput[0] == 'N') {
                playAgain = false;
            }
        } else {
            printf("You went bust...\n");
            playAgain = false;
        }
        // printf("END GAME LOOP\n");
    } // end game loop

    


    printf("\n");
    update_bankroll(playerName, bankroll);
    printf("\n\n");

    printf("\"bye bye...\"\n");
    printf("\t- Jo Dee Messina\n\n");





    printf("\n\n");
    return 0;
}