#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, greatest = 1, sum;
	cin >> n;
	vector <long long> presents(n);
	for (int x = 0; x < n; x++) {
	    cin >> presents[x];
	}
	sort (presents.begin(),presents.end());
	sum = presents[0];
	for (int x = 1; x < n; x++) {
	    if (presents[x] >= sum) {
	        sum += presents[x];
	        greatest++;
	    }
	}
	cout << greatest << endl;
	return 0;
}
