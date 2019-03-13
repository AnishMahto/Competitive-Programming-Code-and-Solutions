#include <iostream>
#include <map>
using namespace std;

int main() {
	// your code goes here
	multimap<string, int> names;
	int n;
	cin >> n;
	
	int found[n] = {0};
	string check[n];
	
	string current;
	for (int x = 0; x < n; x++) {
	    cin >> check[x];
	    names.insert(pair<string, int> (check[x], x));
	    
	}
	
	for (int x = 0; x < n - 1; x++) {
	    
	    cin >> current;
	    multimap<string, int>::iterator it = names.find(current);
	    found[it->second] = 1;
	    names.erase(it);
	    
	}
	
	for (int x = 0; x < n; x++) {
	    if (found[x] == 0) {
	        cout << check[x];
	        x = n;
	    }
	}
	
	return 0;
}
