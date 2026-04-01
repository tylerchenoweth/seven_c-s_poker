#include "constants.h"

void printTopBottomEdge() {
    printf("---------------\n");
}

void printTopNumberRow(int num) {
    if(num == 8) {
        printf("|%s           |\n", NUMS[num]);
    } else {
        printf("|%s            |\n", NUMS[num]);
    }
}

void printBottomNumberRow(int num) {
    if(num == 8) {
        printf("|           %s|\n", NUMS[num]);
    } else {
        printf("|            %s|\n", NUMS[num]);
    }
}

void printTopSuitRow(int suit) {
    printf("|%s  %s     %s   |\n", SUITS[suit], SUITS[suit], SUITS[suit]);
}

void printBottomSuitRow(int suit) {
    printf("|   %s     %s  %s|\n", SUITS[suit], SUITS[suit], SUITS[suit]);
}

void printTwoSuitRow(int suit) {
    printf("|   %s     %s   |\n", SUITS[suit], SUITS[suit]);
}

void printOneSuitRow(int suit) {
    printf("|      %s      |\n", SUITS[suit]);
}

int main() {

    char *s = "\u2663";

    int n = 9;
    int t = 2;



    printTopBottomEdge();
    printTopNumberRow(n);
    printTopSuitRow(t);
    printOneSuitRow(t);
    printTwoSuitRow(t);
    printTwoSuitRow(t);
    printOneSuitRow(t);
    printBottomSuitRow(t);
    printBottomNumberRow(n);
    printTopBottomEdge();

    printf("\n");



    printf("\n\n---------------\n");
    printf("|10           |\n");
    printf("|%s  %s     %s   |\n", s, s,s);
    printf("|      %s      |\n",s);
    printf("|   %s     %s   |\n",s,s);
    printf("|   %s     %s   |\n",s,s);
    printf("|      %s      |\n",s);
    printf("|   %s     %s  %s|\n", s, s,s);
    printf("|           10|\n");
    printf("---------------\n");


    printf("\n\n");

    printf("\n\n---------------\n");
    printf("|10           |\n");
    printf("|%s            |\n", s);
    printf("|   %s     %s   |\n", s,s);
    printf("|      %s      |\n",s);
    printf("|   %s     %s   |\n",s,s);
    printf("|   %s     %s   |\n",s,s);
    printf("|      %s      |\n",s);
    printf("|   %s     %s   |\n",s,s);
    printf("|            %s|\n", s);
    printf("|           10|\n");
    printf("---------------\n");

    
    

    printf("\n\n\n");
    return 0;
}
