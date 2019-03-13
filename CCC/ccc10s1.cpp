#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	//bool flick = false;
	int comps;
	cin >> comps;
 
	string name;
	int ram;
	int cpu;
	int dd;
 
	int top[2] = {0, 0};
 
	string greatest;
	string second;
	int current;
 
	for (int x = 0; x < comps; x++) {
		cin >> name;
		cin >> ram;
		cin >> cpu;
		cin >> dd;
		current = (2 * ram) + (3 * cpu) + dd;
		if (current > top[0]) {
			top[1] = top[0];
			second = greatest;
			top[0] = current;
			greatest = name;
		} else if (current > top[1]) {
			top[1] = current;
			second = name;
		}
	}
    
    if (top[0] == top[1]) {
        for (int x = 0; x < greatest.length(); x++) {
            if (greatest[x] < second[x]) {
                cout << greatest << endl << second << endl;
                x = greatest.length();
            } else if (second[x] < greatest[x]) {
                cout << second << endl << greatest << endl;
                x = greatest.length();
            } else if (x = greatest.length() - 1) {
                cout << greatest << endl << second << endl;
            }
        }
    } else {
	    cout << greatest << endl;
	    cout << second << endl;
    }
    
	return 0;
}
