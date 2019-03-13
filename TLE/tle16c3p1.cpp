#include <iostream>
#include <map>
using namespace std;

map <string, int> words;

int main() {
	// your code goes here
	map <string, int>::iterator it;
	int n, total = 0;
	string temp;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> temp;
	    it = words.find(temp);
	    if (it == words.end()) {
	        total++;
	        words.insert(make_pair(temp, 0));
	    } else {
	        if (it->second == 0) {
	            it->second = 1;
	            total--;
	        }
	    }
	}
	cout << total << endl;
	return 0;
}
