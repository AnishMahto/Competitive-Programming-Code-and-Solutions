#include <iostream>
#include <bitset>
using namespace std;

int main() {
	// your code goes here
	float money[11] = {0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
	bitset<15> check;
	int n, current, deal, left = 0; 
	float average = 0;
	cin >> n;
	while (n--) {
	    cin >> current;
	    check.set(current);
	}
	cin >> deal;
	for (int x = 1; x <= 10; x++) {
	    if (check.test(x) == false) {
	        average += money[x];
	        left++;
	    }
	}
	average /= (float)left;
	
	if (deal > average) {
	    cout << "deal" << endl;
	} else {
	    cout << "no deal" << endl;
	}
	
	return 0;
}
