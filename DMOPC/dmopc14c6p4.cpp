#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int n, m, h, total = 0;
	cin >> n >> m >> h;
	vector <int> buses(n);
	for (int x = 0; x < n; x++) {
	    cin >> buses[x];
	}
	sort (buses.begin(),buses.end());
	for (int x = buses.size() - 2; x >= 0; x--) {
	    if (buses[x + 1] - buses[x] > h) {
	        total += ceil((float)((buses[x + 1] - h) - buses[x])/(float)m);
	        buses[x] += ceil((float)((buses[x + 1] - h) - buses[x])/(float)m) * m;
	    }
	}
	cout << total << endl;
	return 0;
}
