#include <iostream>
#include <cstdio>
using namespace std;

int n, m;

bool palindrome (string temp) {
  int len = temp.length()/2;
  for (int x = 0; x < len; x++) {
    if (temp[x]!=temp[temp.length()-1-x]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  int dist = 0, ans;
  for (int x = n; x <= m; x++) {
    if (palindrome(to_string(x))) {
      if (min (x-n, m-x) >= dist) {
        dist = min (x-n, m-x);
        ans = x;
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
