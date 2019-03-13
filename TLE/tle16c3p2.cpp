#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main() {
	// your code goes here
	long long p, n, v, r, current, destroyed = 0, deathY = 0;
	cin >> p >> n >> v >> r;
	vector < pair <long long, long long> > planets(p);
	vector <long long> a(n);
	for (int x = 0; x < p; x++) {
	    cin >> planets[x].first >> planets[x].second;
	}
	for (int x = 0; x < n; x++) {
	    cin >> a[x];
	}
	for (int i = n; i > 0; i--) {
	    deathY += a[n - i] * pow(v, i);
	}
	for (int x = 0; x < p; x++) {
	    int sum = 0;
	    bool done = false;
	    if (planets[x].first <= v) {
	        for (int i = n; i > 0; i--) {
	            sum += a[n - i] * pow(planets[x].first, i);
	        }
	        if (sum == planets[x].second) {
	            done = true;
	        }
	    } 
	    if (!done) {
	        if ((float)sqrt((float)pow(abs (planets[x].first - v), 2) + (float)pow(abs (planets[x].second - deathY), 2)) <= (float)r) {
	            done = true;
	        }
	    }
	    if (done) {
	        destroyed++;
	    }
	}
	cout << destroyed << endl;
	return 0;
}
