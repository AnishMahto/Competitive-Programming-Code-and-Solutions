#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
using namespace std;

int segTreeGreatest[2000001] = {0}, segTreeFreq[2000001] = {0}, nums[500001] = {0};

pair <int, int> build (int pos, int a, int b) {
    if (segTreeGreatest[pos] != 0) {
        return make_pair (segTreeGreatest[pos], segTreeFreq[pos]);
    }
    if (a == b) {
        segTreeGreatest[pos] = nums[a];
        segTreeFreq[pos] = 1;
    } else {
        pair <int, int> left, right;
        left = build (2 * pos, a, a + (int)floor((float)(b - a)/(float)2));
        right = build (2 * pos + 1, a + (int)floor((float)(b - a)/(float)2) + 1, b);
        if (left.first == right.first) {
            segTreeGreatest[pos] = left.first;
            segTreeFreq[pos] = left.second + right.second;
        } else if (left.first > right.first) {
            segTreeGreatest[pos] = left.first;
            segTreeFreq[pos] = left.second;
        } else {
            segTreeGreatest[pos] = right.first;
            segTreeFreq[pos] = right.second;
        }
    }
    return make_pair (segTreeGreatest[pos], segTreeFreq[pos]);
}

pair <int, int> solve (int pos, int a, int b, int intervalA, int intervalB) {
    if ((a < intervalA || a > intervalB) && (b > intervalB || b < intervalA)) {
        return make_pair(-1, -1);
    }
    if (a >= intervalA && b <= intervalB) {
        return make_pair (segTreeGreatest[pos], segTreeFreq[pos]);
    } else {
        int greatestValue = 0, greatestFreq = 0;
        pair <int, int> temp;
        temp = solve (pos * 2 + 1, a + (int)floor((float)(b - a)/(float)2) + 1, b, intervalA, intervalB);
        greatestValue = temp.first;
        greatestFreq = temp.second;
        temp.first = temp.second = 0;
        temp = solve (2 * pos, a, a + (int)floor((float)(b - a)/(float)2), intervalA, intervalB);
        if (greatestValue == temp.first) {
            greatestFreq += temp.second;
        } else if (temp.first > greatestValue) {
            greatestValue = temp.first;
            greatestFreq = temp.second;
        }
        return make_pair(greatestValue, greatestFreq);
    }
}

int main() {
	// your code goes here
	int n, q, a, b;
	scanf ("%d %d", &n, &q);
	for (int x = 0; x < n; x++) {
	    scanf ("%d", &nums[x]);
	}
	build (1, 0, n - 1);
	pair <int, int> left, right;
	for (int x = 0; x < q; x++) {
	    scanf ("%d %d", &a, &b);
	    a--; //indexing
	    b--; //indexing
	    if (a > 0) {
	        left = solve (1, 0, n - 1, 0, a - 1);
	    } else {
	        left.first = left.second = 0;
	    } 
	    if (b <= n - 2) {
	        right = solve (1, 0, n - 1, b + 1, n - 1);
	    } else {
	        right.first = right.second = 0;
	    }
	    if (left.first == right.first) {
	        printf ("%d %d\n", left.first, left.second + right.second);
	    } else if (left.first > right.first) {
	        printf ("%d %d\n", left.first, left.second);
	    } else {
	        printf ("%d %d\n", right.first, right.second);
	    }
	}
	return 0;
}
