#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int atoms[1001] = {0};
vector < pair <int, int> > edgeList;

int main() {
	// your code goes here
	int m, a, b, c = 0, h = 0, n;
	long long energy = 0;
	cin >> n >> m;
	for (int x = 0; x < m; x++) {
	    cin >> a >> b;
	    atoms[a]++;
	    atoms[b]++;
	    edgeList.push_back(make_pair(min (a, b), max (a, b)));
	}
	sort (edgeList.begin(), edgeList.end());
	for (int x = 1; x <= n; x++) {
	    if (atoms[x] == 0) {
	        cout << "Impossible" << endl;
	        return 0;
	    }
	}
	for (int x = 1; x <= n; x++) {
	    if (atoms[x] == 1) {
	        h++;
	    } else if (atoms[x] == 4) {
	        c++;
	    } else {
	        cout << "Impossible" << endl;
	        return 0;
	    }
	}
	
	for (int x = 0; x < edgeList.size(); x++) {
	    if (x < edgeList.size() - 2 && edgeList[x].first == edgeList[x + 2].first && edgeList[x].second == edgeList[x + 2].second) {
	        cout << "Impossible" << endl;
	        return 0;
	    } else {
	        if (x < edgeList.size() - 1 && edgeList[x].first == edgeList[x + 1].first && edgeList[x].second == edgeList[x + 1].second) {
	            energy += 615;
	            x++;
	        } else {
	            if (atoms[edgeList[x].first] == 1 || atoms[edgeList[x].second] == 1)  {
	                energy += 413;
	            } else {
	                energy += 346;
	            }
	        }
	    }
	}
	cout << energy << endl;
	cout << "C";
	if (c > 1) {
	   cout << c;
	}
	cout << "H";
	if (h > 1) {
	   cout << h;
	}
	return 0;
}
