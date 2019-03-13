#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int n;
	long long total = 0;
	vector <int> temp;
	string current, prev;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    if (x == 0) {
	        temp.push_back(1);
	        cin >> prev;
	    } else {
	        cin >> current;
	        if (current[0] == prev[0]) {
	            temp[temp.size() - 1]++;
	        } else {
	            temp.push_back(1);
	        }
	        prev = current;
	    }
	}
	for (int x = 0; x < temp.size(); x++) {
	    if (temp[x] == 1) {
	        total++; 
	    } else {
	        total += (temp[x] * (temp[x] + 1))/2;
	    }
	}
	cout << total % 1000000007 << endl;
	return 0;
}
