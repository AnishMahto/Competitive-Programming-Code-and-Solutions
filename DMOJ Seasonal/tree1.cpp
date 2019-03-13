#include <iostream>
using namespace std;

int graph[4][4];

int main() {
	// your code goes here
	for (int x = 0; x < 4; x++) {
	    for (int i = 0; i < 4; i++) {
	        cin >> graph[x][i];
	    } 
	}
	int edges = 0, nodes = 4;
	for (int x = 0; x < 4; x++) {
	    for (int i = x; i < 4; i++) {
	        if (graph[x][i] == 1) {
	            edges++;
	        }
	    }
	    for (int i = 0; i < 4; i++) {
	        if (graph[x][i] != 0) {
	            break;
	        } else if (i == 3) {
	            for (int z = 0; z < 4; z++) {
	                if (graph[z][x] != 0) {
	                    break;
	                } else if (z == 3) {
	                    nodes--;
	                }
	            }
	        }
	    }
	}
	if (edges == nodes - 1) {
	    cout << "Yes" << endl;
	} else {
	    cout << "No" << endl;
	}
	return 0;
}
