#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  int n;
  cin >> n;
  double half = (double)n/(double)2;
  cout << std::fixed;
  cout << std::setprecision(2);
  cout << "$" << half << " $" << half << endl;
}
