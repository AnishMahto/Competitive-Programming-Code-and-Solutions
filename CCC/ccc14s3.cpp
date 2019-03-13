#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	vector <int> lake, mountain, side;
	int t, n, current;
	cin >> t;
	while (t--) {
	    lake.clear();
	    mountain.clear();
	    side.clear();
	    cin >> n;
	    for (int x = 0; x < n; x++) {
	        cin >> current;
	        mountain.push_back(current);
	    }
	    while (lake.size() != n) {
	        if (lake.size() == 0 && mountain.back() == 1) {
	            lake.push_back(mountain.back());
	            mountain.pop_back();
	        } else if (lake.size() == 0) {
	            side.push_back(mountain.back());
	            mountain.pop_back();
	        } else {
	            
	            if (side.size() != 0 && side.back() == lake.back() + 1) {
	                lake.push_back(side.back());
	                side.pop_back();
	            } else if (mountain.size() != 0) {
	                
	                if (mountain.back() == lake.back() + 1) {
	                    lake.push_back(mountain.back());
	                    mountain.pop_back();
	                } else {
	                    side.push_back(mountain.back());
	                    mountain.pop_back();
	                }
	                
	            } else {
	                break;
	            }
	            
	        }
	    }
	    
	    if (lake.size() == n) {
	        cout << "Y" << endl;
	    } else {
	        cout << "N" << endl;
	    }
	    
	}
	return 0;
}
