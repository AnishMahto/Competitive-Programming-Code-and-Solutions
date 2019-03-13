#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
  double K, P, X;
  cin >> K >> P >> X;
  double ans = -1;
  for (int x = 1; x <= P*K; x++) {
    if (ans == -1 || x*X+P*K/(double)x < ans) {
      ans = x*X+P*K/(double)x;
    }
  }
  int temp = round(ans * 1000.0);
  string tmp = to_string(temp);
  for (int x = 0; x < tmp.length()-3; x++) {
    cout << tmp[x];
  }
  cout << ".";
  for (int x = tmp.length()-3; x < tmp.length(); x++) {
    cout << tmp[x];
  } cout << endl;
}
