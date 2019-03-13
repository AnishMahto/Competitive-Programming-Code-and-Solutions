#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
using namespace std;

bool possible[301][601] = {0}, whiteOrNah[301] = {0};
int least[301][601] = {0};
bool visited[301] = {0};
vector < vector <int> > graph(301);

int solve (int pos) {
    if (!visited[pos]) {
        visited[pos] = true;
        for (int x = 0; x < graph[pos].size(); x++) {
            solve (graph[pos][x]);
        }
    }
    if (graph[pos].size() == 0) {
        if (whiteOrNah[pos]) {
            least[pos][300 + 1] = 0;
        } else {
            least[pos][300 - 1] = 0;
        }
    } else {
        int add = 0;
        //if we prune all subtree children
        if (whiteOrNah[pos]) {
            least[pos][300 + 1] = graph[pos].size();
            add++;
        } else {
            least[pos][300 - 1] = graph[pos].size();
            add--;
        }
        int tempX, tempI;
        if (graph[pos].size() == 2) {
            for (int x = 0; x <= 600; x++) {
                if (x <= 300) {
                    tempX = 0 - (300 - x);
                } else {
                    tempX = x - 300;
                }
                //if we prune subtree rooted at right
                if (least[graph[pos][0]][x] != -1 && tempX + 300 + add >= 0 && tempX + 300 + add <= 600) {
                    if (least[pos][tempX + 300 + add] == -1) {
                        least[pos][tempX + 300 + add] = least[graph[pos][0]][x] + 1;
                    } else {
                        least[pos][tempX + 300 + add] = min (least[pos][tempX + 300 + add], least[graph[pos][0]][x] + 1);
                    }
                }
                //if we prune subtree rooted at left
                if (least[graph[pos][1]][x] != -1 && tempX + 300 + add >= 0 && tempX + 300 + add <= 600) {
                    if (least[pos][tempX + 300 + add] == -1) {
                        least[pos][tempX + 300 + add] = least[graph[pos][1]][x] + 1;
                    } else {
                        least[pos][tempX + 300 + add] = min (least[pos][tempX + 300 + add], least[graph[pos][1]][x] + 1);
                    }
                }
                //if we both subtrees, and consider net black/white of each subtree added together;
                for (int i = 0; i <= 600; i++) {
                    if (i <= 300) {
                        tempI = 0 - (300 - i);
                    } else {
                        tempI = i - 300;
                    }
                    if (least[graph[pos][0]][x] != -1 && least[graph[pos][1]][i] != -1 && tempX + tempI + 300 + add >= 0 && tempX + tempI + 300 + add <= 600) {
                        if (least[pos][tempX + tempI + 300 + add] == -1) {
                            least[pos][tempX + tempI + 300 + add] = least[graph[pos][0]][x] + least[graph[pos][1]][i];
                        } else {
                            least[pos][tempX + tempI + 300 + add] = min (least[pos][tempX + tempI + 300 + add], least[graph[pos][0]][x] + least[graph[pos][1]][i]);
                        }
                    }
                }
            }
        } else {
            for (int x = 0; x <= 600; x++) {
                if (x <= 300) {
                    tempX = 0 - (300 - x);
                } else {
                    tempX = x - 300;
                }
                if (least[graph[pos][0]][x] != -1 && tempX + 300 + add >= 0 && tempX + 300 + add <= 600) {
                    if (least[pos][tempX + 300 + add] == -1) {
                        least[pos][tempX + 300 + add] = least[graph[pos][0]][x];
                    } else {
                        least[pos][tempX + 300 + add] = min (least[pos][tempX + 300 + add], least[graph[pos][0]][x]);
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
	// your code goes here
	memset(least, -1, sizeof(int)*301*601);
	int n, d, a, b, c, w;
	scanf ("%d %d", &n, &d);
	for (int x = 0; x < n; x++) {
	    scanf ("%d %d %d", &a, &w, &c);
	    if (w == 1) {
	        whiteOrNah[a] = true;
	    }
	    for (int i = 0; i < c; i++) {
	        scanf ("%d", &b);
	        graph[a].push_back(b);
	    }
	}
	solve (0);
	cout << least[0][d + 300] << endl;
	return 0;
}
