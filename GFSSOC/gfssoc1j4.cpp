#include <iostream>
using namespace std;

int main () {
    char board[3][3];
    
    for (int x = 0; x < 3; x++) {
        for (int i = 0; i < 3; i++) {
            cin >> board[x][i];
        }
    }
    
    int ex = 0;
    int oh = 0;
    
    bool tim = false;
    bool griffy = false;
    
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x][y] == 'X') {
                ex++;
            } else if (board[x][y] == 'O') {
                oh++;
            }
            if (ex == 3) {
                tim = true;
            }
            if (oh == 3) {
                griffy = true;
            }
        }
        ex = 0;
        oh = 0;
    }
    ex = 0;
    oh = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (board[x][y] == 'X') {
                ex++;
            } else if (board[x][y] == 'O') {
                oh++;
            }
            if (ex == 3) {
                tim = true;
            }
            if (oh == 3) {
                griffy = true;
            }
        }
        ex = 0;
        oh = 0;
    }
    
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
        tim = true;
    } else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
        griffy = true;
    }
    
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
        tim = true;
    } else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
        griffy = true;
    }
    
    if (griffy == true && tim == true) {
        cout << "Error, redo";
    } else if (griffy == false && tim == false) {
        cout << "Tie";
    } else if (griffy) {
        cout << "Griffy";
    } else if (tim) {
        cout << "Timothy";
    }
    
}
