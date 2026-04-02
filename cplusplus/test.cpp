
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#include <string>
using namespace std;


class OneCard {

    public:
        int numIndex;
        int suitIndex;

        void setNumIndex(int n) {
            numIndex = n;
        }

        void setSuitIndex(int s) {
            suitIndex = s;
        }

        int getNumIndex() {
            return numIndex;
        }

        int getSuitIndex() {
            return suitIndex;
        }

        string getCardNum(int n) {
            return NUMS[n];
        }

        string getCardSuit(int s) {
            return SUITS[s];
        }

    private:
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



int main() {
    system("clear");

    string hello = "hello";
    cout << hello << endl;

}
