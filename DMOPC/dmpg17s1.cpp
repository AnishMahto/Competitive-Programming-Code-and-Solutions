#include <iostream>
#include <set>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	set <long long> temp;
	long long n, current, least = 2000000000000;
	scanf ("%lld", &n);
	if (n > 1000) {
	for (int x = 0; x < n; x++) {
	    scanf ("%lld", &current);
	    if (x == 0) {
	        temp.insert(current);
	    } else {
	        set <long long>::iterator it = temp.lower_bound(current);
	        least = min (least, max(*it, current) - min (*it, current));
	        it = temp.upper_bound(current);
	        least = min (least, max(*it, current) - min (*it, current));
	        temp.insert(current);
	    }
	}
	} else {
	    vector <long long> t;
	    for (int x = 0; x < n; x++) {
	        scanf ("%lld", &current);
	        for (int i = 0; i < t.size(); i++) {
	            least = min (least, max(t[i], current) - min (t[i], current));
	        }
	        t.push_back(current);
	    }
	}
	cout << least << endl;
	return 0;
}
