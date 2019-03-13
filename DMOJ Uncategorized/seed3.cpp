#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	// your code goes here
	int n, m, j, a, b, k, ans = 0, temp = 0;
	scanf ("%d %d %d", &n, &m, &j);
	int total[100002] = {0}, add[100002] = {0}, subtract[100002] = {0};
	for (int x = 0; x < j; x++) {
	    scanf ("%d %d %d", &a, &b, &k);
	    add[a] += k;
	    subtract[b + 1] -= k;
	}
	for (int x = 1; x <= n; x++) {
	    temp += add[x] + subtract[x];
	    total[x] += temp;
	    (total[x] < m) ? ans++:x=x;
	}
	cout << ans << endl;
	return 0;
}
