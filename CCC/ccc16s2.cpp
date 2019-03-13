#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int question = 0;
	cin >> question;
 
	int people;
	cin >> people;
 
	vector <int> dmo;
	vector <int> org_dmo;
 
	vector <int> peg;
	vector <int> org_peg;
 
	int current;
	for (int x = 0; x < people; x++) {
		cin >> current;
		dmo.push_back(current);
	}
	for (int x = 0; x < people; x++) {
		cin >> current;
		peg.push_back(current);
	}
 
	while (dmo.size() > 0) {
		int least = 2000000; // just a huge number, nothing special
		int location;
 
		for (int x = 0; x < dmo.size(); x++) {
			if (dmo[x] < least) {
				least = dmo[x];
				location = x;
			}
		}
 
		org_dmo.push_back(least);
		dmo.erase(dmo.begin() + location);
	}
	while (peg.size() > 0) {
		int least = 2000000; // just a huge number, nothing special
		int location;
 
		for (int x = 0; x < peg.size(); x++) {
			if (peg[x] < least) {
				least = peg[x];
				location = x;
			}
		}
 
		org_peg.push_back(least);
		peg.erase(peg.begin() + location);
	}
 
	int sum = 0;
 
	if (question == 1) {
		for (int x = 0; x < org_dmo.size(); x++) {
			if (org_dmo[x] >= org_peg[x]) {
				sum += org_dmo[x];
			} else {
				sum += org_peg[x];
			}
		}
	} else if (question == 2) {
		vector <int> temp;
		for (int x = (org_peg.size() - 1); x >= 0; x--) {
			temp.push_back(org_peg[x]);
		}
		for (int x = 0; x < org_dmo.size(); x++) {
			if (org_dmo[x] >= temp[x]) {
				sum += org_dmo[x];
			} else {
				sum += temp[x];
			}
		}
	}
 
	cout << sum;
 
	return 0;
}
