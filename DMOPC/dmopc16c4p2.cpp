#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool compare (pair <int, pair <int, int> > &i, pair <int, pair <int, int> > &j) {
    if (i.first == j.first) {
        return i.second.first < j.second.first;
    } else {
        return i.first < j.first;
    }
}

int main() {
	// your code goes here
	int n, s, e, p, f, current;
	scanf ("%d", &n);
	vector < pair <int, pair <int, int> > > batches;
	vector <int> failed;
	for (int x = 0; x < n; x++) {
	    scanf ("%d %d %d", &s, &e, &p);
	    batches.push_back(make_pair(s, make_pair(e, p)));
	}
	sort (batches.begin(), batches.end(), compare);
	scanf ("%d", &f);
	for (int x = 0; x < f; x++) {
	    scanf ("%d", &current);
	    failed.push_back(current);
	}
	sort (failed.begin(), failed.end());
	failed.push_back(100000000);
	vector <int>::iterator it;
	int total = 0, pointer = 0;
	for (int x = 0; x < batches.size(); x++) {
	    it = lower_bound(failed.begin(), failed.end(), batches[x].first);
	    if (failed[it - failed.begin()] >= batches[x].first && failed[it - failed.begin()] <= batches[x].second.first) {
	        total += 0;
	    } else if ((it - failed.begin()) < failed.size()) {
	        total += batches[x].second.second;
	    }
	}
	cout << total << endl;
	return 0;
}
