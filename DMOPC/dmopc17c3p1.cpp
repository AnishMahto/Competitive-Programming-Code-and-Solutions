#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  int n;
  long long least = 1000000000000, cur;
  scanf ("%d", &n);
  for (int x = 0; x < n; x++) {
    scanf ("%lld", &cur);
    least = min (least, cur);
  }
  cout << least << endl;
}
