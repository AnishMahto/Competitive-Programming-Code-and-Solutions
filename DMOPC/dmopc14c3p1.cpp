#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	int n, k, d;
	scanf("%d %d %d", &n, &k, &d);
	
	int total = n * pow(k, d);
	
	printf ("%d", total);
	
	return 0;
}
