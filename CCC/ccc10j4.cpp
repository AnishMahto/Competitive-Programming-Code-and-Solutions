#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	vector <int> changes;
	int n, prev, current;
	cin >> n;
	while (n != 0) {
	    if (n == 1) {
	        cout << 0 << endl;
	        for (int x = 0; x < n; x++) {
	            cin >> current;
	        }
	    } else {
	        changes.clear();
	        int length = 1;
	        
	        for (int x = 0; x < n; x++) {
	            cin >> current;
	            if (x == 0) {
	                prev = current;
	            } else {
	                changes.push_back(current - prev);
	            }
	            prev = current;
	        }
	        
	        bool done = false;
	        
	        while (done == false) {
	            done = true;
	            for (int x = 0; x < changes.size() - length; x++) {
	                if (x + length < changes.size() && changes[x] != changes[x + length]) {
	                    done = false;
	                    break;
	                }
	            }
	            if (done == true) {
	                cout << length << endl;
	            } else if (length >= changes.size()) {
	                cout << changes.size() << endl;
	                done = true;
	            }
	            length++;
	        }
	        
	    }
	    
	    cin >> n;
	}
	
	return 0;
}
