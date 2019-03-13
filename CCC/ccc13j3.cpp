#include <iostream>
using namespace std;

bool check (int n) {
    string temp = to_string(n);
    int check[200] = {0};
    int pos;
    for (int x = 0; x < temp.length(); x++) {
        pos = temp[x];
        check[pos]++;
        if (check[pos] > 1) {
            return false;
        }
    }
    return true;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	while (check(n + 1) == false) {
	    n++;
	}
	cout << n + 1 << endl;
	return 0;
}
