#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string gstr;
	cin >> gstr;
	int pSum[100001] = {0};
	for (int x = 0; x < gstr.length(); x++) {
	    if (gstr[x] == 'G') {
	        pSum[x]++;
	    }
	    if (x > 0) {
	        pSum[x] += pSum[x - 1];
	    }
	}
	int q, i, j;
	cin >> q;
	while (q--) {
	    cin >> i >> j;
	    if (i > 0) {
	        cout << pSum[j] - pSum[i - 1] << endl;
	    } else {
	        cout << pSum[j] << endl;
	    }
	}
	return 0;
}
