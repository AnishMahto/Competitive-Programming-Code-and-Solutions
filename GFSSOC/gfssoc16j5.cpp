#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair <int, int> > nine, ten, eleven, twelve;
vector < pair <int, int> > nNine, nTen, nEleven, nTwelve;

int main() {
	// your code goes here
	int n, a, b, c, d, greatest = 0;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> a >> b >> c >> d;
	    nine.push_back(make_pair(a, x));
	    ten.push_back(make_pair(b, x));
	    eleven.push_back(make_pair(c, x));
	    twelve.push_back(make_pair(d, x));
	}
	sort (nine.begin(), nine.end());
	sort (ten.begin(), ten.end());
	sort (eleven.begin(), eleven.end());
	sort (twelve.begin(), twelve.end());
	for (int x = max (n - 1 - 8, 0); x < nine.size(); x++) {
	    nNine.push_back(nine[x]);
	    nTen.push_back(ten[x]);
	    nEleven.push_back(eleven[x]);
	    nTwelve.push_back(twelve[x]);
	}
	if (n >= 4) {
	for (int x = 0; x < nNine.size(); x++) {
	    for (int i = 0; i < nTen.size(); i++) {
	        for (int z = 0; z < nEleven.size(); z++) {
	            for (int a = 0; a < nTwelve.size(); a++) {
	                if (nNine[x].second != nTen[i].second && nNine[x].second != nEleven[z].second && nNine[x].second != nTwelve[a].second && nTen[i].second != nEleven[z].second && nTen[i].second != nTwelve[a].second && nEleven[z].second != nTwelve[a].second) {
	                    greatest = max (greatest, nNine[x].first + nTen[i].first + nEleven[z].first + nTwelve[a].first);
	                }
	            }
	        }
	    }
	}
	} else if (n == 3) {
	    for (int x = 0; x < n; x++) {
	        for (int i = 0; i < n; i++) {
	            for (int z = 0; z < n; z++) {
	                if (x != i && x != z && i != z) {
	                    greatest = max (greatest, nine[x].first + ten[i].first + eleven[z].first);
	                    greatest = max (greatest, twelve[x].first + ten[i].first + eleven[z].first);
	                    greatest = max (greatest, nine[x].first + twelve[i].first + eleven[z].first);
	                    greatest = max (greatest, nine[x].first + ten[i].first + twelve[z].first);
	                }
	            }
	        }
	    }
	} else if (n == 2) {
	    for (int x = 0; x < n; x++) {
	        for (int i = 0; i < n; i++) {
	            if (x != i) {
	                greatest = max (greatest, nine[x].first + ten[i].first);
	                greatest = max (greatest, nine[x].first + eleven[i].first);
	                greatest = max (greatest, nine[x].first + twelve[i].first);
	                greatest = max (greatest, ten[x].first + eleven[i].first);
	                greatest = max (greatest, ten[x].first + twelve[i].first);
	                greatest = max (greatest, eleven[x].first + twelve[i].first);
	            }
	        }
	    }
	} else if (n == 1) {
	    for (int x = 0; x < n; x++) {
	        greatest = max (nine[x].first, max (ten[x].first, max (eleven[x].first, twelve[x].first)));
	    }
	}
	
	cout << greatest << endl;
	return 0;
}
