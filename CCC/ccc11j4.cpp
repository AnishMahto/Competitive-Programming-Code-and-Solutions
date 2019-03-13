#include <iostream>
using namespace std;

int grid[402][402] = {0};
//let 200 be the mid point (0). Anything below 200 is negative, anything above 200 is positive

bool check (int posX, int posY) {
    if (posY <= 0 || posY >= 201 || posX < 0 || posX > 400) {
        cout << posX - 200 << " " << posY * -1 << " DANGER" << endl;
        return false;
    }
    return true;
}

int main() {
	// your code goes here
	grid[1][200] = grid[2][200] = grid[3][200] = -1;
	grid[3][201] = grid[3][202] = grid[3][203] = -1;
	grid[4][203] = grid[5][203] = -1;
	grid[5][204] = grid[5][205] = -1;
	grid[4][205] = grid[3][205] = -1;
	grid[3][206] = grid[3][207] = -1;
	grid[4][207] = grid[5][207] = grid[6][207] = grid[7][207] = -1;
	grid[7][206] = grid[7][205] = grid[7][204] = grid[7][203] = grid[7][202] = grid[7][201] = grid[7][200] = grid[7][199] = -1;
	grid[6][199] = grid[5][199] = -1;
	
	char command;
	cin >> command;
	
	int posX = 199, posY = 5, steps;
	
	while (command != 'q') {
	    cin >> steps;
	    
	    if (command == 'l') {
	        if (check(posX - steps, posY)) {
	            for (int x = posX - 1; x >= posX - steps; x--) {
	                if (grid[posY][x] == -1) {
	                    cout << (posX - steps) - 200 << " " << posY * -1 << " DANGER" << endl;
	                    return 0;
	                }
	                grid[posY][x] = -1;
	            }
	            cout << (posX - steps) - 200 << " " << posY * -1 << " safe" << endl;
	        } else {
	            return 0;
	            break;
	        }
	        posX -= steps;
	    } else if (command == 'r') {
	        if (check(posX + steps, posY)) {
	            for (int x = posX + 1; x <= posX + steps; x++) {
	                if (grid[posY][x] == -1) {
	                    cout << (posX + steps) - 200 << " " << posY * -1 << " DANGER" << endl;
	                    return 0;
	                }
	                grid[posY][x] = -1;
	            }
	            cout << (posX + steps) - 200 << " " << posY * -1 << " safe" << endl;
	        } else {
	            return 0;
	            break;
	        }
	        posX += steps;
	    } else if (command == 'u') {
	        if (check(posX, posY - steps)) {
	            for (int y = posY - 1; y >= posY - steps; y--) {
	                if (grid[y][posX] == -1) {
	                    cout << posX - 200 << " " << (posY - steps) * -1 << " DANGER" << endl;
	                    return 0;
	                }
	                grid[y][posX] = -1;
	            }
	            cout << posX - 200 << " " << (posY - steps) * -1 << " safe" << endl;
	        } else {
	            return 0;
	            break;
	        }
	        posY -= steps;
	    } else if (command == 'd') {
	        if (check(posX, posY + steps)) {
	            for (int y = posY + 1; y <= posY + steps; y++) {
	                if (grid[y][posX] == -1) {
	                    cout << posX - 200 << " " << (posY + steps) * -1 << " DANGER" << endl;
	                    return 0;
	                }
	                grid[y][posX] = -1;
	            }
	            cout << posX - 200 << " " << (posY + steps) * -1 << " safe" << endl;
	        } else {
	            return 0;
	            break;
	        }
	        posY += steps;
	    }
	    cin >> command;
	}
	
	
	return 0;
}
