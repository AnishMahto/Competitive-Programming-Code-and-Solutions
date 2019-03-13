#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	// your code goes here
	bitset <100001> check;
	int n, greatest = 0, current;
	cin >> n;
	vector <int> balls;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    if (!check.test(current)) {
	        check.set(current);
	        balls.push_back(current);
	    }
	}
	sort (balls.begin(), balls.end());
	for (int x = balls.size() - 1 - 2; x >= 0; x--) {
	    for (int i = x + 1; i <= balls.size() - 1 - 1; i++) {
	        if (balls[i] + balls[i] - balls[x] <= 100000 && check.test(balls[i] + balls[i] - balls[x])) {
	            greatest = max (greatest, balls[x] + balls[i] + balls[i] + (balls[i] - balls[x]));
	        }
	    }
	}
	cout << greatest << endl;
	return 0;
}
