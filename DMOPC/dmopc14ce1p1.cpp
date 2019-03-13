#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string verb;
	string noun;
	cin >> verb;
	cin >> noun;
	
	cout << verb << "-tu ";
	if (noun[noun.length() - 1] == 's') {
	    cout << "les " << noun << " ?";
	} else if (noun[noun.length() - 1] == 'e') {
        cout << "la " << noun << " ?";	    
	} else {
	    cout << "le " << noun << " ?";
	}
	
	return 0;
}
