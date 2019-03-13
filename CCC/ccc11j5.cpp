#include <iostream>
#include <vector>
using namespace std;

int n, ways = 0;
vector < vector <int> > graph(7);

int check (vector <int> set) {
    vector <int> temp;
    int visited[10] = {0};
    int special[10] = {0};
    for (int a = 0; a < set.size(); a++) {
        special[set[a]] = 1;
    }
    for (int a = 0; a < set.size(); a++) {
        if (visited[set[a]] == 0) {
            visited[set[a]] = 1;
            temp.push_back(set[a]);
            while (temp.size() != 0) {
                
                for (int x = 0; x < temp.size(); x++) {
                    
                    for (int i = 0; i < graph[temp[x]].size(); i++) {
                        
                        if (special[graph[temp[x]][i]] != 1) {
                            return 0;
                        } else if (visited[graph[temp[x]][i]] == 0) {
                            temp.push_back(graph[temp[x]][i]);
                            visited[graph[temp[x]][i]] = 1;
                        }
                        
                    }
                    
                    temp.erase(temp.begin() + x);
                    x--;
                }
                
            }
        }
    }
    
    for (int x = 0; x < set.size(); x++) {
        if (visited[set[x]] != 1) {
            return 0;
        }
    }
    ways++;
}

int solve (int pos, vector <int> set) {
    if (pos >= n && set.size() > 0) {
        check(set);
        return 0;
    } else if (pos < n) {
        solve (pos + 1, set);
        set.push_back(pos);
        solve (pos + 1, set);
    }
    return 0;
}

int main() {
	// your code goes here
	vector <int> temp;
	int current;
	cin >> n;
	for (int x = 1; x <= n - 1; x++) {
	    cin >> current;
	    graph[current].push_back(x);
	}
	solve (1, temp);
	cout << ways + 1 << endl;
	return 0;
}
