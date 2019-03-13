#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <string, int> weight;

int main() {
	// your code goes here
	int n;
	string current;
	cin >> n;
	for (int x = 1; x <= n; x++) {
	    cin >> current;
	    weight.insert(make_pair(current, x));
	}
	int t;
	cin >> t;
	vector < pair <int, int> > problems;
	map<string, int>::iterator it;
	for (int x = 0; x < t; x++) {
	    cin >> current;
	    it = weight.find(current);
	    problems.push_back(make_pair(it->second, x + 1));
	}
	sort (problems.begin(), problems.end());
	for (int x = 0; x < problems.size(); x++) {
	    cout << problems[x].second << endl;
	}
	return 0;
}
