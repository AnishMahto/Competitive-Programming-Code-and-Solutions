#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#define gc getchar_unlocked
using namespace std;

int n, m, t, dp[21][21] = {0}, shortestPath[6][6], sx, sy, least = 1000000;
vector < pair <int, int> > hiders;
char map[21][21] = {0};

int solve (bool visited[6], int pos, int sum) {
    bool done = true;
    for (int x = 1; x <= t; x++) {
        if (!visited[x]) {
            done = false;
            visited[x] = true;
            solve (visited, x, sum + shortestPath[pos][x]);
            visited[x] = false;
        }
    }
    if (done) {
        least = min (least, sum);
    }
    return 0;
}

int dfsInit (int posX, int posY, int step) {
    if (step >= dp[posY][posX] && dp[posY][posX] != -1) {
        return 0;
    } else {
        dp[posY][posX] = step;
        if (posX - 1 >= 0 && map[posY][posX - 1] != 'X') {
            dfsInit (posX - 1, posY, step + 1);
        }
        if (posX + 1 < m && map[posY][posX + 1] != 'X') {
            dfsInit (posX + 1, posY, step + 1);
        }
        if (posY - 1 >= 0 && map[posY - 1][posX] != 'X') {
            dfsInit (posX, posY - 1, step + 1);
        }
        if (posY + 1 < n && map[posY + 1][posX] != 'X') {
            dfsInit (posX, posY + 1, step + 1);
        }
    }
    return 0;
}

int main() {
	// your code goes here
	bool visited[6] = {0};
	hiders.push_back(make_pair(-1,-1));
	cin >> n >> m >> t;
	for (int x = 0; x < n; x++) {
	    for (int i = 0; i < m; i++) {
	        cin >> map[x][i];
	        if (map[x][i] == 'G') {
	            sx = i;
	            sy = x;
	        } else if (map[x][i] == 'H') {
	            hiders.push_back(make_pair(i, x));
	        }
	    }
	}
	memset(dp, -1, sizeof(int)*21*21);
	dfsInit(sx, sy, 0);
	for (int x = 1; x <= t; x++) {
	   shortestPath[0][x] = dp[hiders[x].second][hiders[x].first];
	}
	for (int x = 1; x <= t; x++) {
	    memset(dp, -1, sizeof(int)*21*21);
	    dfsInit(hiders[x].first, hiders[x].second, 0);
	    for (int i = 1; i <= t; i++) {
	        shortestPath[x][i] = dp[hiders[i].second][hiders[i].first];
	    }
	}
	memset(visited, 0, sizeof(bool)*6);
	solve (visited, 0, 0);
	cout << least << endl;
	return 0;
}
