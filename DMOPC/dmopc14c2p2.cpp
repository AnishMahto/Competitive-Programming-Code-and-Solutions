#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	bool prevWasX = false;
	
	int n;
	cin >> n;
	
	int numberOfX = 0;
	
	vector < vector <char> > logs;
	vector <char> temp;
	
	char current;
	for (int x = 0; x < n; x++) {
	    cin >> current;
	    if (current == 'X') {
	        prevWasX = true;
	        numberOfX++;
	    } else {
	        if (prevWasX == false || temp.size() == 0) {
	            temp.push_back(current);
	        } else {
	            if (temp.size() > 0) {
	                logs.push_back(temp);
	                temp.clear();
	                temp.push_back(current);
	            }
	        }
	        prevWasX = false;
	    }
	    if (x == n - 1) {
	       logs.push_back(temp);
	    }
	}
	
	if (numberOfX == n) {
	    cout << 0;
	} else {
	    cout << logs.size() << endl;
	    for (int x = 0; x < logs.size(); x++) {
	        for (int i = 0; i < logs[x].size(); i++) {
	            cout << logs[x][i];
	        } cout << endl;
	    }
	}
	
	return 0;
}
