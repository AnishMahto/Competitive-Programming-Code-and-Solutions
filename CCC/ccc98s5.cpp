#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int field[26][26] = {0}, n, neutral, dp[26][26] = {0};

int solve (int posX, int posY, int oxygen) {
    if (dp[posY][posX] != -1 && oxygen >= dp[posY][posX]) {
        return 0;
    } else {
        dp[posY][posX] = oxygen;
        if (posX > 1 && abs(field[posY][posX] - field[posY][posX - 1]) <= 2) {
            if (field[posY][posX] > neutral || field[posY][posX - 1] > neutral) {
                solve (posX - 1, posY, oxygen + 1);
            } else {
                solve (posX - 1, posY, oxygen);
            }
        }
        if (posX < n && abs(field[posY][posX] - field[posY][posX + 1]) <= 2) {
            if (field[posY][posX] > neutral || field[posY][posX + 1] > neutral) {
                solve (posX + 1, posY, oxygen + 1);
            } else {
                solve (posX + 1, posY, oxygen);
            }
        }
        if (posY > 1 && abs(field[posY][posX] - field[posY - 1][posX]) <= 2) {
            if (field[posY][posX] > neutral || field[posY - 1][posX] > neutral) {
                solve (posX, posY - 1, oxygen + 1);
            } else {
                solve (posX, posY - 1, oxygen);
            }
        }
        if (posY < n && abs(field[posY][posX] - field[posY + 1][posX]) <= 2) {
            if (field[posY][posX] > neutral || field[posY + 1][posX] > neutral) {
                solve (posX, posY + 1, oxygen + 1);
            } else {
                solve (posX, posY + 1, oxygen);
            }
        }
    }
    return 0;
}

int main() {
	// your code goes here
	int t;
	scanint(t);
	for (int a = 0; a < t; a++) {
	    scanint(n);
	    memset(field, -1, sizeof(int)*26*26);
	    memset(dp, -1, sizeof(int)*26*26);
	    for (int x = 1; x <= n; x++) {
	        for (int i = 1; i <= n; i++) {
	            scanint(field[x][i]);
	        }
	    }
	    neutral = field[1][1];
	    solve (1, 1, 0);
	    if (dp[n][n] == -1) {
	        cout << "CANNOT MAKE THE TRIP" << endl << endl;
	    } else {
	        cout << dp[n][n] << endl << endl;
	    }
	}
	return 0;
}
