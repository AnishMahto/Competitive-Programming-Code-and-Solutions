#include <iostream>
#include <cstdio>
using namespace std;

int main () {
  string temp;
  cin >> temp;
  for (int x = temp.length()-1; x >= 0; x--) {
    if (temp[x] <= 'm') {
      temp[x] = 'a';
      break;
    } else {
      temp[x] = 'a';
      if (x > 0 && temp[x-1] != 'z') {
        temp[x-1] = (char)((int)temp[x-1]+1);
        break;
      } else if (x == 0) {
        cout << "a";
        break;
      }
    }
  }
  cout << temp << endl;
}
