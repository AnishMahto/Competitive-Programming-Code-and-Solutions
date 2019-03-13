#include <iostream>
#include <cstdio>
using namespace std;

char winner = '*';
int n;
char board[101][101];

void hor (int y, int x) {
  int count = 0;
  int pos = x;
  while (pos >= 0) {
    if (board[y][x] == board[y][pos]) {
      count++;
      pos--;
    } else {
      break;
    }
  }
  pos = x;
  while (pos < n) {
    if (board[y][x] == board[y][pos]) {
      count++;
      pos++;
    } else {
      break;
    }
  }
  if (count >= 4) {
    winner = board[y][x];
  }
}
void ver (int y, int x) {
  int count = 0;
  int pos = y;
  while (pos >= 0) {
    if (board[y][x] == board[pos][x]) {
      count++;
      pos--;
    } else {
      break;
    }
  }
  pos = y;
  while (pos < n) {
    if (board[y][x] == board[pos][x]) {
      count++;
      pos++;
    } else {
      break;
    }
  }
  if (count >= 4) {
    winner = board[y][x];
  }
}
void diagU (int y, int x) {
  int count = 0;
  int px = x, py = y;
  while (px < n && py >= 0) {
    if (board[py][px] == board[y][x]) {
      count++;
      px++;
      py--;
    } else {
      break;
    }
  }
  px = x;
  py = y;
  while (px >= 0 && py < n) {
    if (board[py][px] == board[y][x]) {
      count++;
      px--;
      py++;
    } else {
      break;
    }
  }
  if (count >= 4) {
    winner = board[y][x];
  }
}
void diagD (int y, int x) {
  int count = 0;
  int px = x, py = y;
  while (px < n && py < n) {
    if (board[py][px] == board[y][x]) {
      count++;
      px++;
      py++;
    } else {
      break;
    }
  }
  px = x;
  py = y;
  while (px >= 0 && py >= 0) {
    if (board[py][px] == board[y][x]) {
      count++;
      px--;
      py--;
    } else {
      break;
    }
  }
  if (count >= 4) {
    winner = board[y][x];
  }
}

int main () {
  cin >> n;
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < n; i++) {
      cin >> board[x][i];
    }
  }
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < n; i++) {
      if (board[x][i] != '.') {
        ver(x, i);
        hor(x, i);
        diagD(x, i);
        diagU(x, i);
      }
      if (winner != '*' && winner != '.') {
        cout << winner << endl;
        return 0;
      }
    }
  }
  cout << "ongoing" << endl;
}
