#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	vector <int> chores;
	int t, n, current, sum = 0, possible = 0;
	cin >> t >> n;
	while (n--) {
	    cin >> current;
	    chores.push_back(current);
	}
	sort (chores.begin(), chores.end());
	for (int x = 0; x < chores.size(); x++) {
	    if (sum + chores[x] <= t) {
	        sum += chores[x];
	        possible++;
	    } else {
	        break;
	    }
	}
	cout << possible << endl;
	return 0;
}
