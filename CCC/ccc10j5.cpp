#include <iostream>
#include <string.h>
using namespace std;

int dp[9][9] = {0};

int startX, startY, endX, endY;

bool upLeft (int posX, int posY, int step) {
    if (posX - 1 >= 1 && posY - 2 >= 1) {
        if (step + 1 < dp[posY - 2][posX - 1] || dp[posY - 2][posX - 1] == -1) {
            dp[posY - 2][posX - 1] = step + 1;
            return true;
        }
    }
    return false;
}
bool upRight (int posX, int posY, int step) {
    if (posX + 1 <= 8 && posY - 2 >= 1) {
        if (step + 1 < dp[posY - 2][posX + 1] || dp[posY - 2][posX + 1] == -1) {
            dp[posY - 2][posX + 1] = step + 1;
            return true;
        }
    }
    return false;
}
bool downLeft (int posX, int posY, int step) {
    if (posX - 1 >= 1 && posY + 2 <= 8) {
        if (step + 1 < dp[posY + 2][posX - 1] || dp[posY + 2][posX - 1] == -1) {
            dp[posY + 2][posX - 1] = step + 1;
            return true;
        }
    }
    return false;
}
bool downRight (int posX, int posY, int step) {
    if (posX + 1 <= 8 && posY + 2 <= 8) {
        if (step + 1 < dp[posY + 2][posX + 1] || dp[posY + 2][posX + 1] == -1) {
            dp[posY + 2][posX + 1] = step + 1;
            return true;
        }
    }
    return false;
}
bool leftUp (int posX, int posY, int step) {
    if (posX - 2 >= 1 && posY - 1 >= 1) {
        if (step + 1 < dp[posY - 1][posX - 2] || dp[posY - 1][posX - 2] == -1) {
            dp[posY - 1][posX - 2] = step + 1;
            return true;
        }
    }
    return false;
}
bool leftDown (int posX, int posY, int step) {
    if (posX - 2 >= 1 && posY + 1 <= 8) {
        if (step + 1 < dp[posY + 1][posX - 2] || dp[posY + 1][posX - 2] == -1) {
            dp[posY + 1][posX - 2] = step + 1;
            return true;
        }
    }
    return false;
}
bool rightUp (int posX, int posY, int step) {
    if (posX + 2 <= 8 && posY - 1 >= 1) {
        if (step + 1 < dp[posY - 1][posX + 2] || dp[posY - 1][posX + 2] == -1) {
            dp[posY - 1][posX + 2] = step + 1;
            return true;
        }
    }
    return false;
}
bool rightDown (int posX, int posY, int step) {
    if (posX + 2 <= 8 && posY + 1 <= 8) {
        if (step + 1 < dp[posY + 1][posX + 2] || dp[posY + 1][posX + 2] == -1) {
            dp[posY + 1][posX + 2] = step + 1;
            return true;
        }
    }
    return false;
}

int bfs (int posX, int posY, int step) {
    
    if (posX == endX && posY == endY) {
        return 0;
    } else {
    
        if (upLeft(posX, posY, step)) {
            bfs (posX - 1, posY - 2, step + 1);
        }
        if (upRight(posX, posY, step)) {
            bfs (posX + 1, posY - 2, step + 1);
        }
        if (downLeft(posX, posY, step)) {
            bfs (posX - 1, posY + 2, step + 1);
        }
        if (downRight(posX, posY, step)) {
            bfs (posX + 1, posY + 2, step + 1);
        }
        if (leftDown(posX, posY, step)) {
            bfs (posX - 2, posY + 1, step + 1);
        }
        if (leftUp(posX, posY, step)) {
            bfs (posX - 2, posY - 1, step + 1);
        }
        if (rightDown(posX, posY, step)) {
            bfs (posX + 2, posY + 1, step + 1);
        }
        if (rightUp(posX, posY, step)) {
            bfs (posX + 2, posY - 1, step + 1);
        }
    
    }
}

int main() {
	// your code goes here
	memset(dp, -1, sizeof(int)*9*9);
	cin >> startX >> startY >> endX >> endY;
	dp[startY][startX] = 0;
	bfs(startX, startY, 0);
	cout << dp[endY][endX] << endl;
	
	return 0;
}
