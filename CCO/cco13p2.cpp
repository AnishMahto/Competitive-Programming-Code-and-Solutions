#include <iostream>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cstdio>
using namespace std;

long long n, m, tree[1048576 * 2 + 1] = {0};
int start, end, currentWinner = 0; 

int build (int pos) {
    if (pos < start) {
        tree[pos] = max (build(2*pos), build(2*pos + 1));
    }
    return tree[pos];
}
void RandD (int pos) {
    if (pos == 0) {
        return;
    }
    int change = tree[(pos - (pos % 2))/2];
    tree[(pos - (pos % 2))/2] = max (tree[(pos - (pos % 2))], tree[(pos - (pos % 2)) + 1]);
    if (tree[(pos - (pos % 2))/2] == change) {
        return;
    } else {
        RandD ((pos - (pos % 2))/2);
    }
}
void replace (int pos, int val) {
    tree[pos] = val;
    RandD(pos);
}
int roundsWon (int pos) {
    int val = tree[pos], wins = 0;
    while (pos != 1) {
        if (pos % 2 == 0) {
            pos /= 2;
        } else {
            pos--;
            pos /= 2;
        }
        if (tree[pos] == val)  {
            wins++;
        } else {
            return wins;
        }
    }
    return wins;
}
int winner (int pos) {
    if (pos >= start) {
        return pos;
    } else {
        if (tree[pos * 2] == tree[pos]) {
            return winner (pos * 2);
        } else if (tree[pos * 2 + 1] == tree[pos]) {
            return winner (pos * 2 + 1);
        }
    }
}
int printTree () {
    for (int x = 1; x < start + end; x++) {
	    cout << tree[x] << " ";
	} cout << endl;
}
int main() {
	// your code goes here
	bitset<21>temp;
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
	    temp.set(x);
	}
	start = (int)(temp.to_ulong()) + 1;
	end = pow(2, n);
	int i, s;
	char command;
	for (int x = start; x < start + end; x++) {
	    scanf("%d", &tree[x]);
	}
	build(1);
	for (int x = 0; x < m; x++) {
	    scanf(" %c", &command);
	    if (command == 'R') {
	        scanf("%d %d", &i, &s);
	        replace (start + i - 1, s);
	    } else if (command == 'W') {
	        printf("%d\n", winner(1) - (start - 1));
	    } else if (command == 'S') {
	        scanf ("%d", &i);
	        printf("%d\n", roundsWon(start + i - 1));
	    }
	}
	return 0;
}
