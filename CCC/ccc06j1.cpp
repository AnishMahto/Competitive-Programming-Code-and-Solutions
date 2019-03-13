#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int burgers[5] = {0, 461, 431, 420, 0};
	int drinks[5] = {0, 130, 160, 118, 0};
	int sides[5] = {0, 100, 57, 70, 0};
	int desserts[5] = {0,167, 266, 75, 0};
 
	int bChoice;
	cin >> bChoice;
	int sChoice;
	cin >> sChoice;
	int dChoice;
	cin >> dChoice;
	int dtChoice;
	cin >> dtChoice;
 
	int calories = burgers[bChoice] + drinks[dChoice] + sides[sChoice] + desserts[dtChoice];
	cout << "Your total Calorie count is " << calories << ".";
 
	return 0;
}
