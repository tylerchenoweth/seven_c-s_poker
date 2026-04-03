
#include <iostream>
#include <string>
#include <random>
#include <stdexcept>
#include <iterator>
#include <cstring>
#include <cstdlib>

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
void shuffleDeck(OneCard[]);
void displayHand(OneCard[]);
void holdOrDraw(OneCard[]);
void sortHand(OneCard[]);


int main() {
    system("clear");

    OneCard Deck[52];
    

    holdOrDraw(Deck);


    exit(0);


    cout << "--------------------------------------------" << endl;
    cout << "| WELCOME TO TYLER'S SEVEN C'S POKER GAME! |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;

    initiateCard(Deck);
    printDeck(Deck);
    shuffleDeck(Deck);
    cout << endl << endl;
    printDeck(Deck);
    displayHand(Deck);
    sortHand(Deck);
    displayHand(Deck);

    cout << endl << endl << "bye bye..." << endl << endl;
}


void printDeck(OneCard Deck[]) {
    for(int i=0; i<52; i++) {
        if(i%13 == 0 and i != 0)    
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


void shuffleDeck(OneCard Deck[]) {
    random_device rd;  // Non-deterministic seed source
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 51);

    for(int i=0; i<100; i++) {
        int randNum_1 = distrib(gen);
        int randNum_2 = distrib(gen);

        int tmpNum = Deck[randNum_1].getNum();
        Deck[randNum_1].setNum(Deck[randNum_2].getNum());
        Deck[randNum_2].setNum(tmpNum);
    }
}


void displayHand(OneCard Deck[]) {
    for(int i=0; i<5; i++) {
        cout << Deck[i].getCardNum() << Deck[i].getCardSuit() << " - ";
    }
    cout << endl;
}


void holdOrDraw(OneCard Deck[]) {




    string hand;
    bool allCards = false;
    bool someCards = false;
    bool isValidInput = true;
    
    

    do
    {
        isValidInput = true;

        cout << "Redraw? Enter 1-5 or 0 for all\n> ";
        cin >> hand;
        
        int count = 0;
        bool cardsToRedraw[5] = {false, false, false, false, false};

        for(int i=0; i<hand.length(); i++) {
            // cout << "Inside loop: " << hand[i] << endl;
            if(hand[i] >= '1' && hand[i] <= '5') {
                someCards = true;
                count += 1;
                if(cardsToRedraw[(hand[i]-'0')-1] == true) {
                cout << "error: 2" << endl;
                    isValidInput = false;}
            } else if(hand[i] == '0') {
                cout << "error: 2" << endl;
                allCards = true;
            } else if(hand[i] == ' ') {
                cout << "error: 2" << endl;
                continue;
            } else {
                cout << "error: 2" << endl;
                isValidInput = false;
            }

            if((someCards == true && allCards == true) || count > 5) 
                isValidInput = false;

            


        }

        if(isValidInput == false) 
                cout << "Invalid input..." << endl;

    } while(isValidInput == false);
}


void sortHand(OneCard Deck[]) {
    for(int i=1; i<5; i++) {
        int value = Deck[i].getNumIndex();
        int k = i - 1;
        while(k >= 0 && Deck[k].getNumIndex() > value) {
            Deck[k+1].setNum(Deck[k].getNum());
            k--;
            Deck[k+1].setNum(value);
        }
    }
}