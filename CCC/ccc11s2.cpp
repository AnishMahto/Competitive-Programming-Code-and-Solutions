#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, correct = 0;
	char current;
	cin >> n;
	char answer[n];
	for (int x = 0; x < n; x++) {
	    cin >> answer[x];
	}
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    if (current == answer[x]) correct++;
	}
	cout << correct << endl;
	return 0;
}
