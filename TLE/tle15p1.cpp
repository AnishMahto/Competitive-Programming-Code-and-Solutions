#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector < pair <int, string> > students;

int main() {
	// your code goes here
	int n, p, current;
	string name;
	cin >> n >> p;
	for (int x = 0; x < n; x++) {
	    cin >> name;
	    students.push_back(make_pair(0, name));
	}
	for (int x = 0; x < p; x++) {
	    for (int i = 0; i < n; i++) {
	        cin >> current;
	        students[i].first += current; 
	    }
	}
	sort (students.begin(), students.end());
	for (int x = students.size() - 1; x >= 0; x--) {
	    cout << students.size() - 1 - x + 3 << ". " << students[x].second << endl;
	}
	return 0;
}
