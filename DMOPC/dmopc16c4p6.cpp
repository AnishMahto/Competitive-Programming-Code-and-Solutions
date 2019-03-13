#include <iostream>
#include <cstdio>
#include <deque>
#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;


//as we go left, end of range is less than current
//as we go right, end of range is less than or equal to current
//this takes care of duplicate heights

deque <int> vals, pos;
int n, q, nums[1000001];
long long psum[1000001] = {0};
int closeLeft[1000001] = {0}, closeRight[1000001] = {0};

int main () {
  int a, b;
  scan(n); scan(q);
  nums[0] = 100000001;
  for (int x = 1; x <= n; x++) {
    scan(nums[x]);
    
    while (vals.size() > 0 && nums[x] <= vals.back()) {
      vals.pop_back();
      pos.pop_back();
    }
    if (vals.size() == 0) {
      closeLeft[x] = 0;
    } else {
      closeLeft[x] = pos.back();
    }
    vals.push_back(nums[x]);
    pos.push_back(x);
  }
  pos.clear();
  vals.clear();
  for (int x = n; x >= 1; x--) {
    while (vals.size() > 0 && nums[x] <= vals.back()) {
      vals.pop_back();
      pos.pop_back();
    }
    if (vals.size() == 0) {
      closeRight[x] = 0;
    } else {
      closeRight[x] = pos.back();
    }
    vals.push_back(nums[x]);
    pos.push_back(x);
  }
  
  for (int x = 1; x <= n; x++) {
    long long right = closeRight[x], left = closeLeft[x];
    if (right == 0) { right = n+1; }
    psum[nums[x]] += (x-left)*(right-x);
  }
  for (int x = 2; x <= 1000000; x++) {
    psum[x] += psum[x-1];
  }
  for (int x = 0; x < q; x++) {
    scan(a); scan(b);
    printf ("%lld\n", (psum[b]-psum[a-1]));
  }
}
