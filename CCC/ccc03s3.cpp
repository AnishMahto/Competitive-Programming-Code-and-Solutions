#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	vector <int> rooms;
	int wood, r, c, totalWood = 0;
	char current;
	cin >> wood >> r >> c;
	int map[r][c];
	for (int x = 0; x < r; x++) {
	    for (int i = 0; i < c; i++) {
	        cin >> current;
	        if (current == 'I') {
	            map[x][i] = -1;
	        } else if (current == '.') {
	            map[x][i] = 0;
	        }
	    }
	}
	queue < pair <int, int> > temp;
	int currentWood = 0;
	
	for (int a = 0; a < r; a++) {
	    for (int b = 0; b < c; b++) {
	        
	        if (map[a][b] == 0) {
	            temp.push(make_pair(a, b));
	            currentWood = 0;
	            
	            while (temp.size() != 0) {
	                
	                    if (map[temp.front().first][temp.front().second] == 0) {
	                        currentWood++;
	                        totalWood++;
	                        map[temp.front().first][temp.front().second] = 1;
	                        
	                        if (temp.front().first - 1 >= 0 && map[temp.front().first - 1][temp.front().second] == 0) {
	                            temp.push(make_pair(temp.front().first - 1, temp.front().second));
	                        }
	                        if (temp.front().second + 1 < c && map[temp.front().first][temp.front().second + 1] == 0) {
	                            temp.push(make_pair(temp.front().first, temp.front().second + 1));
	                        } 
	                        if (temp.front().first + 1 < r && map[temp.front().first + 1][temp.front().second] == 0) {
	                            temp.push(make_pair(temp.front().first + 1, temp.front().second));
	                        }
	                        if (temp.front().second - 1 >= 0 && map[temp.front().first][temp.front().second - 1] == 0) {
	                            temp.push(make_pair(temp.front().first, temp.front().second - 1));
	                        }
	                        
	                    }
	                    temp.pop();
	                
	            }
	            rooms.push_back(currentWood);
	            
	        }
	        
	    }
	}
	
	sort (rooms.begin(), rooms.end());
	
	int cover = 0;
	
	for (int x = rooms.size() - 1; x >= 0; x--) {
	    if (wood - rooms[x] >= 0) {
	        wood -= rooms[x];
	        cover++;
	    } else {
	        x = -1;
	    }
	} 
	
	if (cover != 1) {
	    cout << cover << " rooms, " << wood << " square metre(s) left over" << endl;
	} else {
	    cout << cover << " room, " << wood << " square metre(s) left over" << endl;
	}
	
	return 0;
}
