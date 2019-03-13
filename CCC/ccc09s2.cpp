#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int n, w, ways = 0;
int check[2048] = {0};
int memo[31][2048] = {0};

int solve (vector < bitset<8> > bits, int pressed[]) {
    bool done = true;
    for (int x = 1; x < n; x++) {
        if (pressed[x] == 0) {
            pressed[x] = 1;
            bits[x] ^= bits[x - 1];
            if (memo[x][bits[x].to_ulong()] == 0) {
                done = false;
                memo[x][bits[x].to_ulong()] = 1;
                solve (bits, pressed);
            }
            bits[x] ^= bits[x - 1];
            pressed[x] = 0;
        }
    }
    if (done && check[bits[bits.size() - 1].to_ulong()] == 0) {
        check[bits[bits.size() - 1].to_ulong()] = 1;
        ways++;
    }
    return 0;
}

int main() {
	// your code goes here
	int current;
	cin >> n >> w;
	int pressed[n] = {0};
	vector < bitset <8> > bits;
	bitset<8> temp;
	for (int x = 0; x < n; x++) {
	    temp.reset();
	    for (int i = 0; i < w; i++) {
	        cin >> current;
	        if (current == 1) {
	            temp.set(i);
	        }
	    }
	    bits.push_back(temp);
	}
	check[bits[bits.size() - 1].to_ulong()] = 1;
	ways++;
	solve (bits, pressed);
	cout << ways << endl;
	return 0;
}
