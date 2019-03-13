#include <iostream>
#include <map>
using namespace std;

map <string, string> replace;

int main() {
	// your code goes here
	map <string, string>::iterator it;
	int n;
	string a, b, line, current;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> a >> b;
	    replace.insert(make_pair(b, a));
	}
	getline(cin, current);
	getline(cin, line);
	for (int x = 0; x < line.length(); x++) {
	    if (line[x] == ' ' || line[x] == '.') {
	        it = replace.find(current);
	        if (it != replace.end()) {
	            cout << it->second;
	        } else {
	            cout << current;
	        }
	        cout << line[x];
	        current.clear();
	    } else {
	        current += line[x];
	    }
	}
	return 0;
}
