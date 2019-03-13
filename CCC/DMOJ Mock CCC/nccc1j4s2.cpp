#include <iostream>
using namespace std;

int main() {
  int n, arr[37][37] = {0};
  char tmp;
  cin >> n;
  for (int x = 1; x <= n; x++) {
    for (int i = 1; i <= n; i++) {
      cin >> tmp;
      if ((int)tmp <= 57) {
        arr[x][i] = (int)tmp - 48;
      } else {
        arr[x][i] = (int)tmp - 55;
      }
    }
  }
  for (int x = 1; x <= n-1; x++) {
    //digit X
    int count = 0;
    for (int i = 1; i <= n; i++) {
      count = 0;
      for (int z = 1; z <= n; z++) {
        //for each column
        if (arr[i][z]==x) {
          count++;
        }
      }
      if (count != 1) {
        cout << "No" << endl;
        return 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      count = 0;
      for (int z = 1; z <= n; z++) {
        //for each row
        if (arr[z][i]==x) {
          count++;
        }
      }
      if (count != 1) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  //check sort top row
  for (int x = 2; x <= n; x++) {
    if (arr[1][x-1] > arr[1][x]) {
      cout << "Latin" << endl;
      return 0;
    }
  }
  //check sort left col
  for (int x = 2; x <= n; x++) {
    if (arr[x-1][1] > arr[x][1]) {
      cout << "Latin" << endl;
      return 0;
    }
  }
  cout << "Reduced" << endl;
}
