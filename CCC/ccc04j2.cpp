#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int current;
	cin >> current;
	int future;
	cin >> future;
 
	int all = current;
 
	while (all <= future) {
		cout << "All positions change in year " << all << endl;
		all += 60;
	}
	return 0;
}
