#include <iostream>
using namespace std;


int main () {
  int count = 0;
  string temp;
  getline(cin, temp);
  char last = ' ';
  for (int x = 0; x < temp.length(); x++) {
    if (temp[x + 1] == ' ') {
      if (x+2 < temp.length() && temp[x+2] != ' ' && (int)temp[x+2] < 97) {
        cout << temp[x] << ".";
        last = '.';
      } else {
        cout << temp[x];
        last = temp[x];
      }
    } else {
      cout << temp[x];
      last = temp[x];
    }
  }
  if (last != '.') {
    cout << ".";
  }
  cout << endl;
}
