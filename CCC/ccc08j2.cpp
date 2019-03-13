#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <char> list;

int one () {
    list.push_back(list[0]);
    list.erase(list.begin() + 0);
}

int two () {
    list.insert(list.begin() + 0, list[4]);
    list.erase(list.begin() + 5);
}

int three () {
    swap (list[0], list[1]);
}

int four () {
    for (int x = 0; x < list.size(); x++) {
        cout << list[x] << " ";
    } cout << endl;
}

int main() {
	// your code goes here
	list.push_back('A');
	list.push_back('B');
	list.push_back('C');
	list.push_back('D');
	list.push_back('E');
	int b, n;
	cin >> b >> n;
	while (b != 4 || n != 1) {
	    
	    for (int x = 0; x < n; x++) {
	        if (b == 1) {
	            one();
	        } else if (b == 2) {
	            two();
	        } else if (b == 3) {
	            three();
	        } else if (b == 4) {
	            four();
	        }
	    }
	    
	    cin >> b >> n;
	}
	
	four ();
	
	return 0;
}
