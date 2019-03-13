#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	vector <int> sumac;
	int prev, current;
	cin >> prev >> current;
	sumac.push_back(prev);
	sumac.push_back(current);
	while (current >= 0) {
	    if (prev - current >= 0 && (prev != 0 || current != 0)) {
	        sumac.push_back(prev - current);
	    } else {
	        break;
	    }
	    prev = current;
	    current = sumac[sumac.size() - 1];
	}
	
	cout << sumac.size() << endl;
	
	return 0;
}
