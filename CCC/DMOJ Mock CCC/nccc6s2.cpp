#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n, a[1001][1001], cnt = 0, l = 1001, r=-1, u = 1001, d = -1;
	cin >> n;
	for (int x = 1; x <= n; x++) {
		for (int i = 1; i <= n; i++) {
			cin >> a[x][i];
			cnt++;
			if (a[x][i] != cnt) {
				l = min (l, i);
				r = max (r, i);
				u = min (u, x);
				d = max (d, x);
			}
		}
	}
	cout << max (r-l+1, d-u+1) << "\n";
}
