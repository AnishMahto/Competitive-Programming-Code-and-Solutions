#include <iostream>
#include <bitset>
using namespace std;

int f[2001][26] = {0}, backward[2001][26] = {0};

int main() {
	int n, k;
	cin >> n >> k;
	string a;
	cin >> a;
	for (int x = a.length() - 1; x >= 0; x--) {
	    backward[x][(int)a[x] - 97]++;
	    if (x < a.length() - 1) {
	        for (int i = 0; i < 26; i++) {
                backward[x][i] += backward[x + 1][i];
	        }
	    }
	}
	for (int x = 0; x < a.length(); x++) {
	    f[x][(int)a[x] - 97]++;
	    if (x != 0) {
	        for (int i = 0; i < 26; i++) {
	            f[x][i] += f[x - 1][i];
	        }
	    }
	}
	if (k > a.length()) {
	    cout << "WRONGANSWER" << endl;
	    return 0;
	} else if (k == a.length()) {
	    cout << a << endl;
	    return 0;
	} else {
	    for (int x = max(k - 1, 0); x < a.length(); x++) {
	            for (int i = 25; i >= 0; i--) {
	                if (backward[x][i] == 0 && f[max(x - 5*k, 0)][i] == 0) {
	                    for (int z = x - k + 1; z <= x; z++) {
	                        cout << a[z];
	                    }
	                    for (int z = k; z < a.length(); z++) {
	                        cout << (char)(i + 97);
	                    }
	                    return 0;
	                }
	            }
	    }
	}
	cout << "WRONGANSWER" << endl;
	return 0;
}
