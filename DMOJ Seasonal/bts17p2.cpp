#include <iostream>
using namespace std;


int main () {
  double odds = 1;
  int g;
  cin >> g;
  for (int x = 0; x < g; x++) {
    double evil, total;
    cin >> evil >> total;
    odds *= (total-evil)/total;
  }
  cout << odds << endl;
}
