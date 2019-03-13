#include <iostream>
#include <vector>
using namespace std;

string d (char direction) {
    if (direction == 'L') {
        return "RIGHT";
    } else if (direction == 'R') {
        return "LEFT";
    }
}

int main() {
	// your code goes here
	char direction;
	vector <string> instructions;
	string street;
	string temp = "";

	cin >> direction;
	temp += "Turn ";
	temp += d(direction);
    temp += " into your HOME.";	
	instructions.push_back(temp);
	
	cin >> street;
	
	while (street != "SCHOOL") {
	    cin >> direction;
	    temp.clear();
	    temp += "Turn ";
	    temp += d(direction);
        temp += " onto ";
        temp += street;
        temp += " street.";
        instructions.push_back(temp);
	    cin >> street;
	}
	
	for (int x = instructions.size() - 1; x >= 0; x--) {
	    cout << instructions[x] << endl;
	}
	
	return 0;
}
