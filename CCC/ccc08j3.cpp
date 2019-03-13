#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	// your code goes here
	char keypad[5][6] = {
	  {'A', 'B', 'C', 'D', 'E', 'F'},
	  {'G', 'H', 'I', 'J', 'K', 'L'},
	  {'M', 'N', 'O', 'P', 'Q', 'R'},
	  {'S', 'T', 'U', 'V', 'W', 'X'},
	  {'Y', 'Z', ' ', '-', '.', 'n'}
	};
	string word;
	getline (cin, word);
	int prevX = 0, prevY = 0, sum = 0;
	for (int x = 0; x < word.length(); x++) {
	    for (int i = 0; i < 5; i++) {
	        for (int z = 0; z < 6; z++) {
	            if (keypad[i][z] == word[x]) {
	                sum += abs(z - prevX) + abs(i - prevY);
	                prevX = z;
	                prevY = i;
	                z = 6;
	                i = 5;
	            }
	        }
	    }
	}
	sum += abs(prevX - 5) + abs(prevY - 4);
	cout << sum << endl;
	
	return 0;
}
