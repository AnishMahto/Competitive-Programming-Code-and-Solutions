#include <iostream>
#include <map>
using namespace std;

multimap<int, bool> shots;

int main() {
	// your code goes here
	multimap<int, bool>::iterator it;
	int n, current, shoot = 0;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    it = shots.find(current);
	    if (it != shots.end()) {
	        shots.erase(it);
	        shots.insert(make_pair(it->first - 1, true));
	    } else {
	        shoot++;
	        shots.insert(make_pair(current - 1, true));
	    }
	}
	cout << shoot << endl;
	return 0;
}
