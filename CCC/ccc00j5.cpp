#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector < vector <string> > graph(101);
vector <string> names;
int visited[101] = {0};
bool possible = false;
int dfs (string current, string b) {
    if (possible) {
        return 0;
    }
    int pos;
    for (int x = 0; x < names.size(); x++) {
        if (names[x] == current) {
            pos = x;
            break;
        }
    }
    if (visited[pos] == 1) {
        return 0;
    }
    if (current == b) {
        possible = true;
        return 0;
    }
    visited[pos] = 1;
    for (int x = 0; x < graph[pos].size(); x++) {
        dfs (graph[pos][x], b);
    }
    return 0;
}

int main() {
	// your code goes here
	int n;
	string currentPage, temp;
	string a, b;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    cin >> currentPage;
	    names.push_back(currentPage);
	    string website = "";
	    temp = "";
	    while (temp != "</HTML>") {
	        if (temp.length() > 8) {
	            if (temp[0] == 'H' && temp[1] == 'R' && temp[2] == 'E' && temp[3] == 'F') {
	                website = "";
	                for (int i = 6; i < temp.length(); i++) {
	                    if (temp[i] != '"') {
	                        website += temp[i];
	                    } else {
	                        break;
	                    }
	                }
	                graph[x].push_back(website);
	                cout << "Link from " << currentPage << " to " << website << endl;
	            }
	        }
	        cin >> temp;
	    }
	}
	cin >> a >> b;
	while (a != "The") {
	    memset(visited, 0, sizeof(int)*101);
	    possible = false;
	    dfs (a, b);
	    if (possible) {
	        cout << "Can surf from " << a << " to " << b << "." << endl;
	    } else {
	        cout << "Can't surf from " << a << " to " << b << "." << endl;
	    }
	    cin >> a >> b;
	}
	return 0;
}
