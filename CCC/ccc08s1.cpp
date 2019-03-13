#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string city;
	int weather;
	int least = 300;
	string name;
	cin >> city;
	while (city != "Waterloo") {
	    cin >> weather;
	    if (weather < least) {
	        least = weather;
	        name = city;
	    }
	    cin >> city;
	}
	cin >> weather;
	if (weather < least) {
	   least = weather;
	   name = "Waterloo";
	}
	cout << name << endl;
	
	return 0;
}
