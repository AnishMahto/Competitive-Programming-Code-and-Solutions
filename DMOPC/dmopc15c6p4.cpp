#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

vector < vector < pair <int, int> > > graph(100001);
bitset <100001> visited;

int main() {
	// your code goes here
	priority_queue <pair <int, int>, vector< pair <int, int> >, greater < pair <int, int> > > min_heap;
	int n, k, current, sum = 0;
	cin >> n >> k;
	for (int x = 1; x <= n - 1; x++) {
	    cin >> current;
	    graph[x].push_back(make_pair (current, x + 1));
	    graph[x + 1].push_back(make_pair (current, x));
	    if (x + k <= n) {
	        graph[x].push_back(make_pair (0, x + k));
	        graph[x + k].push_back(make_pair (0, x));
	    }
	}
	visited.set(1);
	for (int x = 0; x < graph[1].size(); x++) {
	    min_heap.push(make_pair (graph[1][x].first, graph[1][x].second));
	}
	while (!min_heap.empty()) {
	    if (visited.count() == n) {
	        cout << sum << endl;
	        return 0;
	    } else {
	        int temp = min_heap.top().first, temp2 = min_heap.top().second;
	        min_heap.pop();
	        if (!visited.test(temp2)) {
	            visited.set(temp2);
	            sum += temp;
	            for (int x = 0; x < graph[temp2].size(); x++) {
	                if (!visited.test(graph[temp2][x].second)) {
	                    min_heap.push(make_pair(graph[temp2][x].first, graph[temp2][x].second));
	                }
	            }
	        }
	    }
	}
	cout << sum << endl;
	return 0;
}
