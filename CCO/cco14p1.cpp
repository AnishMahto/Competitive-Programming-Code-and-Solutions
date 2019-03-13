#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, total = 0;
	cin >> n;
	int tri[n][n];
	bool board[n][n];
	char current;
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i < n; i++) {
	        cin >> current;
	        if (current == '.') {
	            board[x][i] = false;
	        } else {
	            board[x][i] = true;
	        }
	    }
	}
	for (int x = n - 1; x >= 0; x--) {
	    for (int i = 0; i < n; i++) {
	        if (board[x][i] == false) {
	            tri[x][i] = 0;
	        } else {
	            if (x == n - 1 || i == 0 || i == n - 1) {
	                tri[x][i] = 1;
	                total++;
	            } else {
	                tri[x][i] = min (tri[x + 1][i], min (tri[x + 1][i + 1], tri[x + 1][i - 1])) + 1;
	                total += tri[x][i];
	            }
	        }
	    }
	}
	cout << total << endl;
	return 0;
}
