#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	string word;
	int prev = -1, timeTaken = 0;
	cin >> word;
	while (word != "halt") {
	    prev = -1;
	    timeTaken = 0;
	    for (int x = 0; x < word.length(); x++) {
	        for (int i = 0; i < 8; i++) {
	            for (int z = 0; z < letters[i].length(); z++) {
	                if (letters[i][z] == word[x]) {
	                    timeTaken += z + 1;
	                    if (prev == i) {
	                        timeTaken += 2;
	                    }
	                    prev = i;
	                    break;
	                    break;
	                }
	            }
	        }
	    }
	    cout << timeTaken << endl;
	    cin >> word;
	}
	return 0;
}
