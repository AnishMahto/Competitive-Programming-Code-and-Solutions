#include <iostream>
#include <cstdio>
using namespace std;

int parent[100001] = {0};

int find (int num) {
    if (num != parent[num]) {
        parent[num] = find (parent[num]);
    } else {
        return num;
    }
    return parent[num];
}

int add (int a, int b) {
    find (a);
    find (b);
    if (parent[a] == parent[b]) {
        return 0;
    }
    if (a > b) {
        parent[parent[b]] = parent[a];
    } else {
        parent[parent[a]] = parent[b];
    }
}

int query (int a, int b) {
    find (a);
    find (b);
    if (parent[a] == parent[b]) {
        printf ("Y\n");
    } else {
        printf ("N\n");
    }
}

int main() {
	// your code goes here
	int n, a, b, l;
	char q;
	scanf ("%d %d", &n, &l);
	for (int x = 0; x <= n; x++) {
	    parent[x] = x;
	}
	for (int x = 0; x < l; x++) {
	    scanf (" %c", &q);
	    scanf ("%d %d", &a, &b);
	    if (q == 'Q') {
	        query (a, b);
	    } else {
	        add (a, b);
	    }
	}
	return 0;
}
