
#include <iostream>
#include <string>
#include <random>
#include <stdexcept>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <iomanip>

using namespace std;


class OneCard {
    public:
        OneCard() {
            // cout << "card created..." << endl;
        }

        OneCard(int n) {
            if(n >= 0 && n < 52) {
                cout << "Card created..." << endl;
                num = n;
            } else {
                throw invalid_argument("Must be number between 0-51");
            }
        }

        int getNumIndex() {
            return num % 13;
        }

        int getSuitIndex() {
            return num % 4;
        }

        string getCardNum() {
            return NUMS[getNumIndex()];
        }

        string getCardSuit() {
            return SUITS[getSuitIndex()];
        }

        void setNum(int n) {
            num = n;
        }

        int getNum() {
            return num;
        }

    private:
        int num;

        const string SUITS[4] = {
            "\u2660",
            "\u2665",
            "\u2666",
            "\u2663"
        };

        const string NUMS[13] = {
            "2", "3", "4", "5", "6",  
            "7", "8", "9", "10",  
            "J", "Q", "K", "A" 
        };
    
};


void printDeck(OneCard[]);
void initiateCard(OneCard[]);
void swapCards(OneCard[], int, int);
void shuffleDeck(OneCard[]);
void displayHand(OneCard[]);
void holdOrDraw(OneCard[]);
void sortHand(OneCard[]);
int determineHand(OneCard[]);
void handleBet(long&, long, int);
bool isInteger(const string&);
long getIntegerInput();


int main() {
    system("clear");

    OneCard Deck[52];
    
    cout << "--------------------------------------------" << endl;
    cout << "| WELCOME TO TYLER'S SEVEN C'S POKER GAME! |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;

    long bankroll;
    long betAmount;
    int pokerHandRank;
    string strBetAmount;
    bool playAgain = true;
    int handsWon = 0;
    int handsLost = 0;

    cout << "ENTER SEED MONEY \n$";
    do {
        bankroll = getIntegerInput();
    } while(bankroll <= 0);

    cout << endl;

    while(playAgain == true) {
        string playAgainInput;

        cout << "BANKROLL: $" << bankroll << endl << endl;
        cout << "HOW MUCH DO YOU WANT TO BET \n$";

        do {
            betAmount = getIntegerInput();
        } while(betAmount <= 0 || betAmount > bankroll);

        initiateCard(Deck);
        // printDeck(Deck);
        shuffleDeck(Deck);
        // printDeck(Deck);
        sortHand(Deck);
        displayHand(Deck);
        holdOrDraw(Deck);
        sortHand(Deck);
        displayHand(Deck);
        pokerHandRank = determineHand(Deck);
        handleBet(bankroll, betAmount, pokerHandRank);

        if(pokerHandRank == 0)
            handsLost += 1;
        else
            handsWon += 1;

        cout << endl;
        cout << "HANDS PLAYED: " << handsWon + handsLost << endl;
        cout << "- HANDS WON: " << handsWon << endl;
        cout << "- HANDS LOST: " << handsLost << endl;

        if(bankroll > 0) {
            while(
                playAgainInput != "y" && playAgainInput != "Y" &&
                playAgainInput != "n" && playAgainInput != "N" 
            ) {
                cout << endl << "Do you want to play again(y/N)? \n> ";
                cin >> playAgainInput;
                // clear anything leftover on the input line
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        
            if(playAgainInput == "n" || playAgainInput == "N")
                playAgain = false;
            else {
                cout << endl << endl;
                for(int i=0; i<44; i++) cout << "\u2660" << " ";
                cout << endl;
                for(int i=0; i<43; i++) cout << " " << "\u2665";
                cout << endl;
                for(int i=0; i<44; i++) cout << "\u2666" << " ";
                cout << endl;
                for(int i=0; i<43; i++) cout << " " << "\u2663";
                cout << endl;
                for(int i=0; i<44; i++) cout << "\u2666" << " ";
                cout << endl;
                for(int i=0; i<43; i++) cout << " " << "\u2665";
                cout << endl;
                for(int i=0; i<44; i++) cout << "\u2660" << " ";
                cout << endl << endl << endl;
            }
        }
        else {
            cout << "\nYOU WENT BUST!" << endl;
            playAgain = false;         
        }

        
    }
    cout << endl << endl << "bye bye..." << endl << endl;
}


void printDeck(OneCard Deck[]) {
    for(int i=0; i<52; i++) {
        if(i%13 == 0 and i != 0)    
            cout << endl;
        else if(i == 5)
            cout << endl;
        else if(i == 10)
            cout << endl;
        cout << Deck[i].getCardNum() << Deck[i].getCardSuit() << " "; 
    }
    cout << endl << endl;
}


void initiateCard(OneCard Deck[]) {
    for(int i=0; i<52; i++) {
        Deck[i].setNum(i);
    }
}


void swapCards(OneCard Deck[], int index_1, int index_2) {
    int tmpNum = Deck[index_1].getNum();
    Deck[index_1].setNum(Deck[index_2].getNum());
    Deck[index_2].setNum(tmpNum);
}


void shuffleDeck(OneCard Deck[]) {
    random_device rd;  // Non-deterministic seed source
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 51);

    for(int i=0; i<100; i++) {
        int randNum_1 = distrib(gen);
        int randNum_2 = distrib(gen);

        swapCards(Deck, randNum_1, randNum_2);
    }
}


void displayHand(OneCard Deck[]) {
    /*
        0 - top or bottom edge
        1 - number left row
        2 - number right row
        3 - 10 left row
        4 - 10 right row
        5 - face left row
        6 - face right row
        7 - empty row 
        8 - one suit row
        9 - two suit row
    */
    int cardLines[13][11] = {
        {0, 1, 8, 7, 7, 7, 7, 7, 8, 2, 0}, // 2
        {0, 1, 8, 7, 7, 8, 7, 7, 8, 2, 0}, // 3
        {0, 1, 9, 7, 7, 7, 7, 7, 9, 2, 0}, // 4
        {0, 1, 9, 7, 7, 8, 7, 7, 9, 2, 0}, // 5
        {0, 1, 9, 7, 7, 9, 7, 7, 9, 2, 0}, // 6
        {0, 1, 9, 8, 7, 9, 7, 7, 9, 2, 0}, // 7
        {0, 1, 9, 7, 9, 7, 9, 7, 9, 2, 0}, // 8
        {0, 1, 9, 7, 9, 8, 9, 7, 9, 2, 0}, // 9
        {0, 3, 9, 8, 9, 7, 9, 8, 9, 4, 0}, // 10
        {0, 5, 7, 7, 7, 7, 7, 7, 7, 6, 0}, // J
        {0, 5, 7, 7, 7, 7, 7, 7, 7, 6, 0}, // Q
        {0, 5, 7, 7, 7, 7, 7, 7, 7, 6, 0}, // K
        {0, 1, 7, 7, 7, 8, 7, 7, 7, 2, 0}, // A
    };

    int space = 3;
    cout << endl;

    // go through lines
    for(int i=0; i<11; i++) {
        // go through cards
        for(int k=0; k<5; k++) {
            // cout << cardLines[Deck[k].getNumIndex()][i] << " ";
            string num = Deck[k].getCardNum();
            string suit = Deck[k].getCardSuit();

            switch(cardLines[Deck[k].getNumIndex()][i]) 
            {
                case 0:
                    cout << "---------------" << setw(space) << "";
                    break;
                case 1:
                    cout << "|" << num << "            " << "|" << setw(space) << "";
                    break;
                case 2:
                    cout << "|" << "            " << num << "|" << setw(space) << "";
                    break;
                case 3:
                    cout << "|" <<  "10           " << "|" << setw(space) << "";
                    break;
                case 4:
                    cout << "|" <<  "           10" << "|" << setw(space) << "";
                    break;
                case 5:
                    cout << "|" << num << suit << "           " << "|" << setw(space) << "";
                    break;
                case 6:
                    cout << "|" << "           " << suit << num << "|" << setw(space) << "";
                    break;
                case 7:
                    cout << "|             |" << setw(space) << "";
                    break;
                case 8:
                    cout << "|" << "      " << suit << "      " << "|" << setw(space) << "";
                    break;
                case 9:
                    cout << "|  " << suit << "       " << suit << "  |" << setw(space) << "";
                    break;
                default:
                    cout << "BAD LINE INPUT";
                    break;     
            }; 
        }
        cout << endl;
    }
    cout << endl;
}


void holdOrDraw(OneCard Deck[]) {
    string hand;
    bool allCards = false;
    bool someCards = false;
    bool isValidInput = true;
    bool cardsToRedraw[5] = {false, false, false, false, false};

    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    do
    {
        isValidInput = true;
        allCards = false;
        someCards = false;
        int count = 0;

        cout << "Redraw? Enter 1-5 or 0 for all\n> ";
        getline(cin, hand);
        
        // reset bool array
        for(int i=0; i<5; i++)
            cardsToRedraw[i] = false;

        for(int i=0; i<hand.length(); i++) {
            if(hand[i] >= '1' && hand[i] <= '5') {
                someCards = true;
                count += 1;
                if(cardsToRedraw[(hand[i]-'0')-1] == true) 
                    isValidInput = false;
                else 
                    cardsToRedraw[(hand[i]-'0')-1] = true;
            } else if(hand[i] == '0') {
                allCards = true;

                for(int k=0; k<5; k++) 
                    cardsToRedraw[k] = true; 
            }
            else if(hand[i] == ' ') 
                continue;
            else 
                isValidInput = false;

            if((someCards == true && allCards == true) || isValidInput == false)
                isValidInput = false;
        }

        if(isValidInput == false) 
            cout << "Invalid input..." << endl;

    } while(isValidInput == false);

    int newCardIndex = 5;

    // deal new hand
    for(int i=0; i<5; i++) {
        if(cardsToRedraw[i] == true) {
            swapCards(Deck, i, newCardIndex);
            newCardIndex++;
        }
    }
}


void sortHand(OneCard Deck[]) {
    for(int i=1; i<5; i++) {
        OneCard Card = Deck[i];
        int k = i - 1;
        while(k >= 0 && Deck[k].getNumIndex() > Card.getNumIndex()) {
            Deck[k+1].setNum(Deck[k].getNum());
            k--;
            Deck[k+1].setNum(Card.getNum());
        }
    }
}


bool isPair(OneCard Card_1, OneCard Card_2) {
    if(Card_1.getNumIndex() == Card_2.getNumIndex())
        return true;
    else
        return false;
}


int determineHand(OneCard Deck[]) {

    bool isFlush = true;
    bool isStraight = true;
    int fourCount = 0;

    for(int i=0; i<4; i++) {
        if(Deck[i].getNumIndex()+1 != (Deck[i+1].getNumIndex())) {
            isStraight = false;
        }
        if(Deck[i].getSuitIndex() != Deck[i+1].getSuitIndex()) {
            isFlush = false;
        }
        if(Deck[i].getNumIndex() == (Deck[i+1].getNumIndex())) {
            fourCount += 1;
        } else if(fourCount != 3) {
            fourCount = 0;
        }
    }

    if (isStraight == true && isFlush == true) {
        if (Deck[0].getNumIndex() == 8) {
            cout << "--ROYAL FLUSH--" << endl;
            return 9;
        } else {
            cout << "--STRAIGHT FLUSH--" << endl;
            return 8;
        }
    } 
    else if (fourCount == 3) {
        cout << "--FOUR OF A KIND--" << endl;
        return 7;
    } 
    else if (isPair(Deck[0], Deck[1]) && isPair(Deck[0], Deck[2]) && isPair(Deck[3], Deck[4])) {
        cout << "--FULL HOUSE--" << endl;
        return 6;
    } 
    else if (isPair(Deck[2], Deck[3]) && isPair(Deck[2], Deck[4]) && isPair(Deck[0], Deck[1])) {
        cout << "--FULL HOUSE--" << endl;
        return 6;
    } 
    else if (isFlush == true) {
        cout << "--FLUSH--" << endl;
        return 5;
    } 
    else if (isStraight == true) {
        cout << "--STRAIGHT--" << endl;
        return 4;
    } 
    else {   
        for (int i = 0; i < 3; i++) {
            if (isPair(Deck[i], Deck[i+1]) && isPair(Deck[i], Deck[i+2])) {
                cout << "--THREE OF A KIND--" << endl;
                return 3;
            }
        }
        for (int i = 0; i < 2; i++) {
            if (isPair(Deck[i], Deck[i+1])) {
                for (int k = (i + 2); k < 4; k++) {
                    if (isPair(Deck[k], Deck[k+1])) {
                        cout << "--TWO PAIR--" << endl;
                        return 2;
                    }
                }
            }
        }
                  
        for (int i = 0; i < 4; i++) {
            if (isPair(Deck[i], Deck[i+1])) {
                cout << "--ONE PAIR--" << endl;
                return 1;
            }
        }
    } 
    
    cout << "--Nothing--" << endl;
    return 0;
}


void handleBet(long& bankroll, long betAmount, int pokerHandRank) {
    long oldBankroll = bankroll;

    if(pokerHandRank == 9)
        bankroll += (betAmount * 100);
    else if(pokerHandRank == 8)
        bankroll += (betAmount * 50);
    else if(pokerHandRank == 7)
        bankroll += (betAmount * 20);
    else if(pokerHandRank == 6)
        bankroll += (betAmount * 7);
    else if(pokerHandRank == 5)
        bankroll += (betAmount * 5);
    else if(pokerHandRank == 4)
        bankroll += (betAmount * 4);
    else if(pokerHandRank == 3)
        bankroll += (betAmount * 3);
    else if(pokerHandRank == 2)
        bankroll += (betAmount * 2);
    else if(pokerHandRank == 1)
        bankroll += (betAmount * 1);
    else 
        bankroll -= betAmount;

    if(bankroll > oldBankroll)
        cout << "\nYOU WON: $" << (bankroll-oldBankroll) << endl;
    else
        cout << "\nYOU LOST: $" << betAmount << endl;
    cout << "NEW BALANCE: $" << bankroll << endl;
}

bool isInteger(const string& s) {
    stringstream ss(s);
    int n;
    // Check if we can extract an int AND if nothing else is left in the string
    return (ss >> n) && (ss >> ws).eof();
}


long getIntegerInput() {
    string input;
    long num;
    
    while (true) {
        getline(cin, input);
        stringstream ss(input);

        if (ss >> num && ss.eof()) {
            return num;
        }

        cout << "Invalid input. Try again\n> $";
    }
}