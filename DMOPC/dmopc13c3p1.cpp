#include <iostream>
#include <map>
using namespace std;

int main() {
	// your code goes here
	multimap <int, string> shared;
	
	int n;
	cin >> n;
	int m;
	cin >> m;
	int p, q;
	string title;
	
	for (int x = 0; x < m; x++) {
	    cin >> p;
	    cin >> q;
	    cin.ignore();
	    getline (cin, title);
	    shared.insert(pair<int, string> (q, title));
	}
	
	int myNum;
	cin >> myNum;
	pair <multimap<int, string>::iterator, multimap<int, string>::iterator> range = shared.equal_range(myNum);
	
	for (multimap<int, string>::iterator it = range.first; it != range.second; it++) {
	    cout << it->second << endl;
	}
	
	return 0;
}
