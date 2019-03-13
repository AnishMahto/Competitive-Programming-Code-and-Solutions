#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> medians;
  for (int x = 0; x < n; x++) {
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    sort (nums.begin(), nums.end());
    medians.push_back(nums[(n+1)/2 - 1]);
  }
  sort (medians.begin(), medians.end());
  cout << medians[(n+1)/2 - 1] << endl;
}
