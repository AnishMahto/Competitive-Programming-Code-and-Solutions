#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string temp, current, least = "";
	cin >> temp;
	int n;
	cin >> n;
	for (int x = 0; x <= temp.length() - n; x++) {
	    current = "";
	    for (int i = x; i < x + n; i++) {
	        current += temp[i];
	    }
	    if (least == "" || current < least) {
	        least = current;
	    }
	}
	cout << least << endl;
	return 0;
}
