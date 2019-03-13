#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	int height, width;
	cin >> width;
	cin >> height;
	
	int edible = 0;
	string current;
	cin.ignore();
	for (int x = 0; x < height; x++) {
	    getline(cin, current);
	    for (int i = 0; i < current.length(); i++) {
	        if (current[i] == '*') {
	            cout << ' ';
	        } else if (current[i] == 'o') {
	            cout << ' ';
	            edible++;
	        } else {
	            cout << current[i];
	        }
	    } cout << endl;
	}
	
	for (int x = 0; x < edible; x++) {
	    cout << 'o';
	}
	
	return 0;
}
