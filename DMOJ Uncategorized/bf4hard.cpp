#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  string S, T;
  getline (cin, S);
  getline (cin, T);
  int lp[T.length()] = {0}, i = 0, j = 1, len = 0;
  while (j < T.length()) {
    if (T[j] == T[i]) {
      lp[j] = i+1;
      i++;
      j++;
    } else {
      if (i==0) {
        j++;
      } else {
        i = lp[i-1];
      }
    }
  }
  i = j = 0;
  while (j < S.length()) {
    if (S[j]==T[i]) {
      if (i==T.length()-1) {
        cout << j-i << endl;
        return 0;
      }
      j++;
      i++;
    } else {
      if (i==0) {
        j++;
      } else {
        i = lp[i-1];
      }
    }
  }
  cout << -1 << endl;
}
