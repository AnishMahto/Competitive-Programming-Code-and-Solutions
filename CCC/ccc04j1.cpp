#include <iostream>
#include <math.h>
using namespace std;
 
int main() {
	// your code goes here
 
	int tiles;
	cin >> tiles;
	cout << "The largest square has side length " << floor(sqrt(tiles)) << ".";
	return 0;
}
