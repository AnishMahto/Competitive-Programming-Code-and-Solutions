#include <iostream>
#include <bitset>
#include <cstdio>
#define gc getchar_unlocked
using namespace std;

void scanint(long long &x) {
	register int c = gc();
	x = 0;
	long long neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

int main() {
	// your code goes here
	long long n;
	long long current;
	bitset<64>check;
    scanint(n);
    for (int x = 0; x < n; x++) {
	    scanint(current);
	    check = current;
	    if (check.count() == 1 || current == 0) {
	        printf ("T\n");
	    } else {
	        printf ("F\n");
	    }
	}
	return 0;
}
