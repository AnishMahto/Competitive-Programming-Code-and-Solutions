#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int antenna, eyes;
	cin >> antenna >> eyes;
	if (antenna >= 3 && eyes <= 4) {
	    cout << "TroyMartian" << endl;
	} 
	if (antenna <= 6 && eyes >= 2) {
	    cout << "VladSaturnian" << endl;
	}
	if (antenna <= 2 && eyes <= 3) {
	    cout << "GraemeMercurian" << endl;
	}
	return 0;
}
