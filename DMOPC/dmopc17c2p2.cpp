#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main () {
  string temp;
  cin >> temp;
  vector <char> stack;
  for (int x = 0; x < temp.length(); x++) {
    if (stack.size()==0) {
      stack.push_back(temp[x]);
    } else {
      if (temp[x] == ')' && stack.back() == '(') {
        stack.pop_back();
      } else {
        stack.push_back(temp[x]);
      }
    }
  }
  if (stack.size()==0) {
    cout << "YES" << endl;
  } else if (stack.size() > 2) {
    cout << "NO" << endl;
  } else if (stack[0] == '(') {
    cout << "YES" << endl;
  } else if (stack[0] == ')' && stack[1] == ')') {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
