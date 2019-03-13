#include <iostream>
#include <vector>
using namespace std;
 
int main() {
 
	string word;
	cin >> word;
 
	int palindromes = 1;
 
	//int i = (x + 1), does the plus 1 work?
	vector <char> forward;
	vector <char> backward;
 
	for (int x = 0; x < word.length(); x++) {
		forward.clear();
		forward.push_back(word[x]);
		for (int i = (x + 1); i < word.length(); i++) {
			bool palin = true;
			backward.clear();
			forward.push_back(word[i]);
			for (int z = (forward.size() - 1); z >= 0; z--) {
				backward.push_back(forward[z]);
			}
			for (int z = 0; z < forward.size(); z++) {
				if (forward[z] != backward[z]) {
					palin = false;
				}
			}
 
			if (palin == true && forward.size() > palindromes) {
				palindromes = forward.size();
			}
		}
	}
 
	cout << palindromes;
 
	return 0;
}
