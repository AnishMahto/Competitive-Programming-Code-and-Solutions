#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

int dist[100001], updated[100001] = {0};
map < pair <int, int>, int> sells;
// store, apple; distance
vector < priority_queue < pair <int, pair <int, int> >, vector < pair <int, pair <int, int> > >, greater < pair <int, pair <int, int> > > > > apples(101);
//dist, store;
vector < vector <int> > storeSells(100001);

int main() {
	// your code goes here
	map < pair <int, int>, int>::iterator it;
	int n, s, a, b, q, k;
	char current;
	scanf ("%d %d", &n, &s);
	for (int x = 1; x <= n; x++) {
	    scanf ("%d", &dist[x]);
	    updated[x] = 1;
	}
	for (int x = 0; x < s; x++) {
	    scanf ("%d %d", &a, &b);
	    sells.insert(make_pair(make_pair(a, b), dist[a]));
	    apples[b].push(make_pair(dist[a], make_pair(a, 1)));
	}
	scanf ("%d", &q);
	while (q--) {
	    scanf (" %c", &current);
	    if (current == 'Q') {
	        scanf ("%d", &k);
	        bool done = false;
	        while (!done) {
	            if (apples[k].empty()) {
	                done = true;
	                printf ("-1\n");
	            } else {
	                int d = apples[k].top().first, store = apples[k].top().second.first;
	                it = sells.find(make_pair(store, k));
	                if (it->second != dist[store] || d != dist[store] || apples[k].top().second.second != updated[store]) {
	                    apples[k].pop();
	                } else {
	                    done = true;
	                    printf ("%d\n", store);
	                }
	            }
	        }
	    } else if (current == 'A') {
	        scanf ("%d %d", &a, &k);
	        sells.erase(make_pair(a, k));
	        sells.insert(make_pair(make_pair(a, k), dist[a]));
	        apples[k].push(make_pair(dist[a], make_pair(a, updated[a])));
	        storeSells[a].push_back(k);
	    } else if (current == 'S') {
	        scanf ("%d %d", &a, &k);
	        sells.erase(make_pair(a, k));
	    } else if (current == 'E') {
	        scanf ("%d %d", &a, &k);
	        dist[a] = k;
	        for (int x = 0; x < storeSells[a].size(); x++) {
	            sells.erase(make_pair(a, k));
	        }
	        updated[a]++;
	        storeSells[a].clear();
	    }
	}
	return 0;
}
