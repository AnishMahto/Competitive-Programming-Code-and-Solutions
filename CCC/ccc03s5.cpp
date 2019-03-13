#include <iostream>
#include <vector>
using namespace std;

vector < vector < vector <int> > > graph;

int solve (int dp[], int end) {
    vector <int> temp;
    temp.push_back(1);
    int elements = 1;
    
    while (temp.size() > 0) {
        
        for (int x = 0; x < temp.size(); x++) {
            
            for (int i = 0; i < graph[temp[x]].size(); i++) {
                
                if (graph[temp[x]][i][1] > dp[graph[temp[x]][i][0]] && graph[temp[x]][i][0] != 0) {
                    dp[graph[temp[x]][i][0]] = graph[temp[x]][i][1];
                    temp.push_back(graph[temp[x]][i][0]);
                }
                
            }
            
            temp.erase(temp.begin() + x);
            
        }
        
    }
    
    return dp[end];
    
}

int main() {
	// your code goes here
	
	int n, roads, d;
	cin >> n;
	cin >> roads;
	cin >> d;

	vector < vector <int> > temp2d;
	vector <int> temp;
	
	for (int x = 0; x <= n; x++) {
	    graph.push_back(temp2d);
	}
	
	int a, b, z;
	for (int x = 0; x < roads; x++) {
	    cin >> a;
	    cin >> b;
	    cin >> z;
	    
	    temp.clear();
	    temp.push_back(b);
	    temp.push_back(z);
	    graph[a].push_back(temp);
	    
	    temp.clear();
	    temp.push_back(a);
	    temp.push_back(z);
	    graph[b].push_back(temp);
	    
	}
	
	int current;
	int dp[n+1] = {0};
	int greatest = -1;
	
	for (int a = 0; a < d; a++) {
	    cin >> current;
	    
	    int answer = solve (dp, current);
	    //cout << answer << endl;
	    if (greatest == -1) {
	        greatest = answer;
	    } else if (answer < greatest) {
	        greatest = answer;
	    }
	    
	}
	
	cout << greatest;
	
	return 0;
}
