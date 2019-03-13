#include <iostream>
using namespace std;

int main () {
  int n, count = 0;
  string temp;
  cin >> n;
  for (int x = 0; x < n; x++) {
    cin >> temp;
    if (temp.length() <= 10) {
      count++;
    }
  }
  cout << count << endl;
}
