#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin >> n;
	
	int year, month, day;
	
	for (int x = 0; x < n; x++) {
	    cin >> year;
	    cin >> month;
	    cin >> day;
	    
	    if (2007 - year > 18) {
	        cout << "Yes" << endl;
	    } else if (2007 - year == 18) {
	        
	        if (month < 2) {
	            cout << "Yes" << endl;
	        } else if (month == 2) {
	            if (day <= 27) {
	                cout << "Yes" << endl;
	            } else {
	                cout << "No" << endl;
	            }
	        } else {
	            cout << "No" << endl;
	        }
	        
	    } else {
	        cout << "No" << endl;
	    }
	    
	}
	
	
	return 0;
}
