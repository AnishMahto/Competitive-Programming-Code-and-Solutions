#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map <int, int> students;

int main() {
	// your code goes here
	int n, a, b, s, c, leastPeriod = 501;
	cin >> n >> a >> b;
	students.insert(make_pair(a, 0));
	vector < pair <int, vector <int> > > classes(n);
	for (int x = 0; x < n; x++) {
	    cin >> classes[x].first >> s;
	    for (int i = 0; i < s; i++) {
	        cin >> c;
	        classes[x].second.push_back(c);
	    }
	}
	sort (classes.begin(), classes.end());
	map <int, int>::iterator it;
	for (int x = 0; x < n; x++) {
	    int least = 10000000;
	    for (int i = 0; i < classes[x].second.size(); i++) {
	        it = students.find(classes[x].second[i]);
	        if (it == students.end()) {
	            students.insert(make_pair(classes[x].second[i], 0));
	        } else {
	            if (classes[x].second[i] == a || it->second != 0) {
	                least = min (least, it->second + 1);
	            }
	        }
	    }
	    for (int i = 0; i < classes[x].second.size(); i++) {
	        it = students.find(classes[x].second[i]);
	        if (classes[x].second[i] != a) {
	            if (it->second == 0) {
	                it->second = least;
	                if (it->first == b) {
	                    leastPeriod = classes[x].first;
	                }
	            } else {
	                if (classes[x].second[i] == b && least < it->second) {
	                    leastPeriod = classes[x].first;
	                } else if (classes[x].second[i] == b && least == it->second) {
	                    leastPeriod = min (leastPeriod, classes[x].first);
	                }
	                it->second = min (it->second, least);
	            }
	            
	        }
	    }
	}
	it = students.find(b);
	if (leastPeriod == 501 || it->second == 10000000) {
	    cout << "delivery failure" << endl;
	    return 0;
	}
	cout << it->second << endl << leastPeriod << endl;
	return 0;
}
