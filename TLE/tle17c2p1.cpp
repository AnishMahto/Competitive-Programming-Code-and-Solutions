#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main () {
  string temp;
  getline (cin, temp);
  vector < bool> t;
  for (int x = 0; x < temp.length(); x++) {
    if (temp[x]=='a') {
      t.push_back(true);
    } else if (temp[x] == 'd') {
      t.push_back(false);
    }
  }
  int c = 0;
  for (int x = 0; x < t.size(); x++) {
    printf ("(");
    if (t[x]) {
      printf ("car ");
      c++;
    } else {
      c++;
      printf ("cdr ");
    }
  }
  printf ("x");
  for (int x = 0; x < c; x++) {
    printf (")");
  }
}
