#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <float,int> pos;

int main() {
	// your code goes here
	int n, q;
	float m, sums[100001] = {0}, current, a, b;
	scanf ("%d %f %d", &n, &m, &q);
	for (int x = 1; x <= n; x++) {
	    if (x == 1) {
	        scanf ("%f", &sums[x]);
	        pos.insert(make_pair(sums[x], x));
	        sums[x]/=2;
	    } else {
	        scanf ("%f", &current);
	        sums[x] = sums[x - 1] + current/2;
	        pos.insert(make_pair(current, x));
	    }
	}
	map <float, int>::iterator it;
	for (int x = 0; x < q; x++) {
	    scanf ("%f %f", &a, &b);
	    it = pos.find(a);
	    int posA = it->second;
	    it = pos.find(b);
	    int posB = it->second;
	    if (sums[posB] - sums[posA - 1] >= m) {
	        printf("Enough\n");
	    } else {
	        printf("Not enough\n");
	    }
	}
	return 0;
}
