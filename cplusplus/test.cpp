#include <iostream>
#include <string>
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













void printDeck(OneCard Deck[]) {
    for(int i=0; i<5; i++) {
        cout << Deck[i].getCardNum() << Deck[i].getCardSuit() << endl;
    }
}





void displayHand(OneCard Deck[]) {
    int cardLines[13][4] = {
        {0, 2, 3, 4},
        {0, 2, 3, 8},
        {0, 2, 3, 12},
        {0, 2, 3, 16},
        {0, 2, 3, 20},
        {0, 2, 3, 24},
        {0, 2, 3, 28},
        {0, 2, 3, 32},
        {0, 2, 3, 36},
        {0, 2, 3, 40},
        {0, 2, 3, 44},
        {0, 2, 3, 44},
        {0, 2, 3, 44}
    };


    for(int i=0; i<4; i++) {
        // go through cards
        for(int k=0; k<5; k++) {
            cout << cardLines[Deck[k].getNumIndex()][i] << " ";
        }
        cout << endl;
    }

    int space = 3;

    cout << endl;



    // go through lines
    for(int i=0; i<4; i++) {
        // go through cards
        for(int k=0; k<5; k++) {
            // cout << cardLines[Deck[k].getNumIndex()][i] << " ";
            string num = Deck[k].getCardNum();
            string suit = Deck[k].getCardSuit();

            switch(cardLines[Deck[k].getNumIndex()][i]) 
            {
                case 0:
                    cout << "-----------" << setw(space);
                    break;
                case 1:
                    cout << "|" << setw(9) << "|" << setw(space);
                    break;
                case 2:
                    cout << "|" << num << setw(8) << "|" << setw(space);
                    break;
                case 3:
                    cout << "|" << setw(8) << num << "|" << setw(space);
                    break;
                default:
                    cout << "/";
                    break;
                    
            }; 
        }
        cout << setw(0) << endl;
    }




}







int main() {
    int cards[5] = {0, 5, 8, 11, 12};
    OneCard Deck[5];

    for(int i=0; i<5; i++) {
        Deck[i].setNum(cards[i]);
    }

    printDeck(Deck);
    displayHand(Deck);


}