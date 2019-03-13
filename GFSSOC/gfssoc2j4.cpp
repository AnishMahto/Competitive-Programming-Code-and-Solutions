#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	// your code goes here
	int n, q;
	scanf("%d %d", &n, &q);
 
	int prefixSum[n];
	int totalSum = 0;
 
	for (int x = 0; x < n; x++) {
	    if (x == 0) {
	        scanf("%d", &prefixSum[x]);
	        totalSum += prefixSum[x];
	    } else {
	        scanf("%d", &prefixSum[x]);
	        totalSum += prefixSum[x];
	        prefixSum[x] += prefixSum[x - 1];
	    }
	}
 
	int a, b;
	for (int x = 0; x < q; x++) {
	    scanf("%d %d", &a, &b);
 
	    if (a > 1) {
	        printf("%d\n", totalSum - (prefixSum[b - 1] - prefixSum[a - 2]));
	    } else {
	        printf("%d\n", totalSum - (prefixSum[b - 1]));
	    }
	}
 
	return 0;
}
