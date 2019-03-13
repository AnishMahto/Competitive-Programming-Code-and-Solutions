#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string S;
  int arr[200] = {0};
  cin >> S;
  for (int x = 0; x < S.length(); x++) {
    arr[(int)S[x]]++;
  }
  vector <int> letters;
  for (int x = 0; x <= 199; x++) {
    if (arr[x] > 0) {
      letters.push_back(arr[x]);
    }
  }
  sort (letters.begin(), letters.end());
  int total = 0, upTo = letters.size()-2;
  for (int x = 0; x < upTo; x++) {
    total += letters[x];
  }
  cout << total << endl;
}
