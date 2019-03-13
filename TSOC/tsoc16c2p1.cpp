#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int names;
	cin >> names;
	
	string letters;
	cin >> letters;
	
	int counter = 0;
	bool prevX = false;
	
	for (int x = 0; x < letters.length(); x++) {
	    if (letters[x] == 'X') {
	        counter++;
	        letters.erase(x, 1);
	        prevX = true;
	        x--;
	    } else if (prevX == true && letters[x] != 'X') {
	        letters[x - counter] = letters[x];
	        letters.erase(x, 1);
	        x--;
	        counter = 0;
	        prevX = false;
	    }
	}
	string current;
	
	
	int len = letters.length();
	
	for (int x = 0; x < len; x++) {
	    if (letters[x] == 'X') {
	        letters.erase(x, 1);
	        x--;
	    }
	}
	
	for (int x = 0; x < names; x++) {
	    cin >> current;
	    if (letters[x] == 'A') {
	        cout << "Dear " << current << ", beloved artist, I would love to have you at my party. Come to my crib on April 20th." << endl;
	    } else if (letters[x] == 'O') {
	        cout << "Dear " << current << ", beloved occasion enthusiast, come to my crib to celebrate this very special day." << endl;
	    } else if (letters[x] == 'R') {
	        cout << "Dear " << current << ", April 20th is happening again this year. Don't miss out." << endl;
	    }
	}
	
	return 0;
}
