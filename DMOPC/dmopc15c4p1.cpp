#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	vector <string> words;
	string current;
	
	for (int a = 0; a < n; a++) {
	    cin >> current;
	    words.push_back(current);
	}
	
	sort (words.begin(), words.end());
	
	for (int x = 0; x < words.size(); x++) {
	    if (x > 0) {
	        if (words[x][0] == words[x - 1][0]) {
	            cout << ", " << words[x];
	        } else {
	            cout << endl << words[x];
	        }
	    } else {
	        cout << words[x];
	    }
	}
	
	return 0;
}
