#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// your code goes here
	int i;
	cin >> i;
	
	float sum = 0;
	float current;
	for (int x = 0; x < i; x++) {
		cin >> current;
		sum += current;
	}
	
	int n;
	cin >> n;
	int students = i;
	for (int x = 0; x < n; x++) {
		cin >> current;
		sum += current;
		students++;
		cout << setprecision(5) << sum / students << endl;
	}
	
	return 0;
}
