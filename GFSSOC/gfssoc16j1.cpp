#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int c, n, total = 0, shiz;
	string temp;
	vector <int> courses;
	cin >> c >> n;
	shiz = n;
	for (int x = 0; x < c; x++) {
	    cin >> temp;
	    if (temp == "TOK") {
	        courses.push_back(1);
	    } else if (temp == "English") {
	        courses.push_back(2);
	    } else if (temp == "Chemistry") {
	        courses.push_back(3);
	    } else if (temp == "Math") {
	        courses.push_back(4);
	    }
	}
	sort (courses.begin(), courses.end());
	for (int x = 0; x < courses.size(); x++) {
	    if (n >= courses[x]) {
	        n -= courses[x];
	        total++;
	    }
	}
	if (total == c) {
	    cout << "YEA BOI" << endl;
	} else {
	    cout << "Go to Metro" << endl;
	    cout << total << endl;
	}
	return 0;
}
