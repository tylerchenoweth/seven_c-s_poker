
#ifndef PRINT_HAND_H
#define PRINT_HAND_H

#include "constants.h"

void printTopBottomEdge();
void printTopNumberRow(int num);
void printBottomNumberRow(int num);
void printTwoSuitRow(int suit);
void printOneSuitRow(int suit);
void printEmptyRow();
void printFaceCardTopNumberRow(int num, int suit);
void printFaceCardBottomNumberRow(int num, int suit);
void printCardSpace();
void printNewLine();
void testPrintFiveCardsHardCoded();
void determinePrintLine(int n, int num, int suit);
void print_hand(struct Card* hand);



#endif