#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int n, m;
	long long total = 0;
	cin >> n >> m;
	vector <int> flowers(n);
	for (int x = 0; x < n; x++) {
	    cin >> flowers[x];
	}
	sort (flowers.begin(), flowers.end());
	for (int x = m - 1; x >= 0; x--) {
	    long long temp = 1;
	    for (int i = 0; i < (1 + ((m - 1) - x)); i++) {
	        temp *= flowers[x];
	        temp %= 1000000007;
	    }
	    total += temp;
	    total %= 1000000007;
	}
	cout << total << endl;
	return 0;
}
