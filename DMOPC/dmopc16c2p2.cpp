#include <iostream>
using namespace std;

class disjointSet {
    private:
        int parent[100001] = {0};
    public:
        void init (int n) {
            for (int x = 1; x <= n; x++) {
                parent[x] = x;
            }
        }
        int find (int a) {
            if (parent[a] == a) {
                return a;
            } else {
                parent[a] = find (parent[a]);
                return parent[a];
            }
        }
        void merge (int a, int b) {
            if (parent[a] == parent[b]) {
                return;
            }
            find (a);
            find (b);
            if (parent[a] < parent[b]) {
                parent[parent[b]] = parent[a];
            } else {
                parent[parent[a]] = parent[b];
            }
        }
        int infected (int a) {
            find (a);
            if (parent[a] == 1) {
                return true;
            } else {
                return false;
            }
        }
        void print (int n) {
            for (int x = 1; x <= n; x++) {
                cout << parent[x] << " ";
            } cout << endl;
        }
        int findParent (int a) {
            return parent[a];
        }
};

int main() {
	// your code goes here
	int n, m, k, current, prev, one = 0, total = 0;
	cin >> n >> m;
	disjointSet ds;
	ds.init(n);
	for (int x = 0; x < m; x++) {
	    cin >> k;
	    for (int i = 0; i < k; i++) {
	        cin >> current;
	        if (current == 1) {
	            one = 1;
	        }
	        if (i > 0) {
	            ds.merge (current, prev);
	        }
	        prev = current;
	    }
	}
	if (one != 1) {
	    cout << 1 << endl << 1 << endl;
	    return 0;
	}
	for (int x = 1; x <= n; x++) {
	    if (ds.find(x) == 1) {
	        total++;
	    }
	}
	cout << total << endl;
	for (int x = 1; x <= n; x++) {
	    if (ds.findParent(x) == 1) {
	        cout << x << " ";
	    }
	}
	return 0;
}
