#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

vector < pair <int, int> > zombies;

int main() {
	// your code goes here
	int n, r, t, posAce = 1, zombieRow, zombieColumn, bullets;
	cin >> n >> r >> t;
	bullets = t;
	int grid[r + 1][7] = {0};
	for (int x = 0; x < n; x++) {
	    cin >> zombieColumn >> zombieRow;
	    zombies.push_back(make_pair(zombieRow, zombieColumn));
	}
	sort (zombies.begin(), zombies.end());
	int timeReq = 0;
	for (int x = 0; x < zombies.size(); x++) {
	    timeReq += abs (posAce - zombies[x].second);
	    posAce = zombies[x].second;
	    if (bullets == 0) {
	        bullets += t - 1;
	        timeReq++;
	    } else {
	        bullets--;
	    }
	    timeReq++;
	    if (timeReq > zombies[x].first) {
	        cout << "Never lucky, Ace." << endl;
	        return 0;
	    }
	}
	cout << "You can do it, Ace!" << endl;
	return 0;
}
