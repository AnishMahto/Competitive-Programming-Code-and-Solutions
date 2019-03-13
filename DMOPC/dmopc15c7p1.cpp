#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, team[5], greatestTime = 0;
	cin >> n;
	for (int x = 1; x <= 4; x++) {
	    cin >> team[x];
	}
	int problems[n][4];
	for (int x = 0; x < n; x++) {
	    cin >> problems[x][0] >> problems[x][1] >> problems[x][2] >> problems[x][3];
	    greatestTime = max (greatestTime, problems[x][2]);
	}
	for (int x = 0; x < n; x++) {
	    if (greatestTime + problems[x][3] * team[problems[x][0]] <= 180 || problems[x][1] == 10) {
	        cout << 10 - problems[x][1] << endl;
	    } else {
	        cout << "The kemonomimi are too cute!" << endl;
	    }
	}
	return 0;
}
