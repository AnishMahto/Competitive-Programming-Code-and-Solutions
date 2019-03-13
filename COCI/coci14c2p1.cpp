#include <iostream>
#include <cstdio>
using namespace std;

int main () {
  int c[200] = {0};
  c['a'] = c['b'] = c['c'] = 2;
  c['d'] = c['e'] = c['f'] = 3;
  c['g'] = c['h'] = c['i'] = 4;
  c['j'] = c['k'] = c['l'] = 5;
  c['m'] = c['n'] = c['o'] = 6;
  c['p'] = c['q'] = c['r'] = c['s'] = 7;
  c['t'] = c['u'] = c['v'] = 8;
  c['w'] = c['x'] = c['y'] = c['z'] = 9;
  int m[11] = {0};
  int t;
  for (int x = 1; x <= 9; x++) {
    cin >> t;
    m[t] = x;
  }
  string temp;
  cin >> temp;
  int prev = -1;
  for (int x = 0; x < temp.length(); x++) {
    
    int type = m[c[temp[x]]];
    
    if (type == prev) {
      cout << "#";
    }
    
    if (temp[x] == 'a') {
      cout << type;
    } else {
      int pos = temp[x];
      cout << type;
      while (c[pos] == c[pos-1]) {
        pos--;
        cout << type;
      }
      
    }
    
    prev = type;
  }
}
