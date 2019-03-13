#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	vector <int> car;
	vector <int> trunk;
	
	int current;
	for (int x = 0; x < 3; x++) {
	    cin >> current;
	    trunk.push_back(current);
	}
	
	for (int x = 0; x < 3; x++) {
	    cin >> current;
	    car.push_back(current);
	}
	
	sort (car.begin(), car.begin() + car.size());
	sort (trunk.begin(), trunk.begin() + trunk.size());
	
	if (trunk[0] <= car[0] && trunk[1] <= car[1] && trunk[2] <= car[2]) {
	    cout << "Y";
	} else {
	    cout << "N";
	}
	
	
	return 0;
}
