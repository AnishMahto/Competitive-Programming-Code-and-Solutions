#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	vector <int> nums;
	int n, sum = 0, current;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    if (current != 0) {
	        sum += current;
	        nums.push_back(current);
	    } else {
	        sum -= nums.back();
	        nums.pop_back();
	    }
	}
	cout << sum << endl;
	return 0;
}
