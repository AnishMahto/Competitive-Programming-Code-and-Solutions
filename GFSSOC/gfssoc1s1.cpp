#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int n, t, current;
	long long value = 1;
	vector < pair <long long, int> > friends;
	cin >> n;
	for (int a = 1; a <= n; a++) {
	    value = 1;
	    cin >> t;
	    for (int x = 0; x < t; x++) {
	        cin >> current;
	        value *= current;
	    }
	    friends.push_back(make_pair(value, a));
	}
	sort (friends.begin(), friends.end());
	cout << friends[friends.size() - 1].second << endl << friends[friends.size() - 2].second << endl << friends[friends.size() - 3].second << endl;
	return 0;
}
