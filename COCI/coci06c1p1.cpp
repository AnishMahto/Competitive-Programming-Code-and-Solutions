#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int check[45] = {0};
	int current, total = 0;
	for (int x = 0; x < 10; x++) {
	    cin >> current;
	    if (check[current % 42] == 0) {
	        total++;
	        check[current % 42] = 1;
	    }
	}
	cout << total << endl;
	return 0;
}
