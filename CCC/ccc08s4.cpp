#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector <int> hand;
int greatest = 0;

int solve (vector <int> cards) {
    vector <int> temp = cards;
    if (cards.size() == 1) {
        if (cards[0] > greatest && cards[0] <= 24) greatest = cards[0];
    } else {
        int t1, t2;
        for (int x = 0; x < cards.size() - 1; x++) {
            
            for (int i = x + 1; i < cards.size(); i++) {
                t1 = cards[x];
                t2 = cards[i];
                
                cards.erase(cards.begin() + i);
                cards.erase(cards.begin() + x);
                
                cards.push_back(t1 + t2);
                solve (cards);
                cards.pop_back();
                
                cards.push_back(t1 * t2);
                solve (cards);
                cards.pop_back();
                
                cards.push_back(t1 - t2);
                solve (cards);
                cards.pop_back();
                
                cards.push_back(t2 - t1);
                solve (cards);
                cards.pop_back();
                
                if (t1 != 0 && t2 % t1 == 0) {
                    cards.push_back(t2 / t1);
                    solve (cards);
                    cards.pop_back();
                }
                
                cards = temp;
            }
            
        }
        
    }
    return 0;
}

int main() {
	// your code goes here
	int n, c1, c2, c3, c4;
	cin >> n;
	while (n--) {
	    hand.clear();
	    greatest = 0;
	    cin >> c1 >> c2 >> c3 >> c4;
	    hand.push_back(c1);
	    hand.push_back(c2);
	    hand.push_back(c3);
	    hand.push_back(c4);
	    solve (hand);
	    cout << greatest << endl;
	}
	return 0;
}
