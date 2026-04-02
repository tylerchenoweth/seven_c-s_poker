#include "constants.h"













// struct Card {
//     const char* num;
//     const char* suit;
// };






void printTopBottomEdge() {
    printf("---------------");
}

void printTopNumberRow(int num) {
    if(num == 8) {
        printf("|%s           |", NUMS[num]);
    } else {
        printf("|%s            |", NUMS[num]);
    }
}

void printBottomNumberRow(int num) {
    if(num == 8) {
        printf("|           %s|", NUMS[num]);
    } else {
        printf("|            %s|", NUMS[num]);
    }
}

void printTwoSuitRow(int suit) {
    printf("|   %s     %s   |", SUITS[suit], SUITS[suit]);
}

void printOneSuitRow(int suit) {
    printf("|      %s      |", SUITS[suit]);
}

void printEmptyRow() {
    printf("|             |");
}

void printFaceCardTopNumberRow(int num, int suit) {
    printf("|%s%s           |", NUMS[num], SUITS[suit]);
}

void printFaceCardBottomNumberRow(int num, int suit) {
    printf("|           %s%s|", SUITS[suit], NUMS[num]);
}

void printCardSpace() {
    printf("   ");
}

void printNewLine() {
    printf("\n");
}


void testPrintFiveCardsHardCoded() {
    char *s = "\u2663";

    int n = 9;
    int t = 2;

    for (int i = 0; i < 5; i++) {
        printTopBottomEdge();
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printTopNumberRow(n);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printTwoSuitRow(t);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printOneSuitRow(t);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printTwoSuitRow(t);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printEmptyRow();
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printTwoSuitRow(t);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printOneSuitRow(t);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printTwoSuitRow(t);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printBottomNumberRow(n);
        printCardSpace();
    }
    printNewLine();
    
    for (int i = 0; i < 5; i++) {
        printTopBottomEdge();
        printCardSpace();
    }
    printNewLine();
}



void determinePrintLine(int n, int num, int suit) {
    switch(n) 
    {
        case 1: printTopBottomEdge();
        break;
        case 2: printTopNumberRow(num);
        break;
        case 3: printBottomNumberRow(num);
        break;
        case 4: printOneSuitRow(suit);
        break;
        case 5: printTwoSuitRow(suit);
        break;
        case 6: printEmptyRow();
        break;
        case 7: printFaceCardTopNumberRow(num, suit);
        break;
        case 8: printFaceCardBottomNumberRow(num, suit);
        break;
        default: printf("INVALID NUMBER FOR CARD PRINTS");

    }
}



int main() {

    char *s = "\u2663";

    int n = 7;
    int t = 2;

    struct Card* hand = (struct Card*)malloc(5 * sizeof(struct Card));
    int test_nums[5] = {0,3,8,9,12};
    int test_suits[5] = {0,3,2,1,0};

    // LOAD TEST DATA
    for(int i=0; i<5; i++) {
        hand[i].num = NUMS[test_nums[i]];
        hand[i].suit = SUITS[test_suits[i]];
    }

    // END TEST DATA BLOCK


    




    int num_index[5];
    int suit_index[5];

    for(int i=0; i<5; i++) {
        for(int k=0; k<(sizeof(NUMS)/sizeof(NUMS[0])); k++) {
            if(hand[i].num == NUMS[k]) {
                num_index[i] = k;
            }
        }

        for(int k=0; k<(sizeof(SUITS)/sizeof(SUITS[0])); k++) {
            if(hand[i].suit == SUITS[k]) {
                suit_index[i] = k;
            }
        }


    }

    
    /*
        1 - Top Bottom Edge
        2 - Top Number
        3 - Bottom Number
        4 - One Suit
        5 - Two Suits
        6 - Empty Row
        7 - Top Face Num
        8 - Bottom Face Num
    */

    // need 11 numbers
    int cardLinesIndex[13][11] = {
        {1,2,4,6,6,6,6,6,4,3,1}, // 2
        {1,2,4,6,6,4,6,6,4,3,1}, // 3
        {1,2,5,6,6,6,6,6,5,3,1}, // 4
        {1,2,5,6,6,4,6,6,5,3,1}, // 5
        {1,2,5,6,6,5,6,6,5,3,1}, // 6
        {1,2,5,4,6,5,6,6,5,3,1}, // 7
        {1,2,5,4,6,5,6,4,5,3,1}, // 8
        {1,2,5,6,5,4,5,6,5,3,1}, // 9
        {1,2,5,4,5,6,5,4,5,3,1}, // 10
        {1,7,6,6,6,6,6,6,6,8,1}, // jack
        {1,7,6,6,6,6,6,6,6,8,1}, // queen
        {1,7,6,6,6,6,6,6,6,8,1}, // king
        {1,2,6,6,6,4,6,6,6,3,1}, // ace
    };
    


    for(int i=0; i<11; i++) {
        for(int k=0; k<5; k++) {
            determinePrintLine(cardLinesIndex[num_index[k]][i], num_index[k], suit_index[k]);
            printCardSpace();
        }
        printNewLine();
    }



    

























    
    






    printf("\n");



    // printf("\n\n-------------\n");
    // printf("|9          |\n");
    // printf("|  %s     %s  |\n", s,s);
    // printf("|     %s     |\n",s);
    // printf("|  %s     %s  |\n",s,s);
    // printf("|           |\n");
    // printf("|  %s     %s  |\n",s,s);
    // printf("|     %s     |\n",s);
    // printf("|  %s     %s  |\n", s,s);
    // printf("|          9|\n");
    // printf("-------------\n");


    // printf("\n\n");

    // printf("\n\n---------------\n");
    // printf("|9            |\n");
    // printf("|   %s     %s   |\n", s,s);
    // printf("|      %s      |\n",s);
    // printf("|   %s     %s   |\n",s,s);
    // printf("|             |\n");
    // printf("|   %s     %s   |\n",s,s);
    // printf("|      %s      |\n",s);
    // printf("|   %s     %s   |\n",s,s);
    // printf("|            9|\n");
    // printf("---------------\n");

    
    

    printf("\n\n\n");
    return 0;
}
