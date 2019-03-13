#include <iostream>
#include <math.h>
using namespace std;

long long bs (long long low, long long up, long long target) {
  long long mid = low + (up-low)/2;
  int power = 1, count = 0;
  while (pow(5, power) <= mid) {
    count += mid/pow(5, power);
    power++;
  }
  if (up == low) {
    return mid;
  }
  if (count > target) {
    return bs (low, mid, target);
  } else {
    return bs (mid+1, up, target);
  }
}

long long bslb (long long low, long long up, long long target) {
  long long mid = low + (up-low)/2;
  int power = 1, count = 0;
  while (pow(5, power) <= mid) {
    count += mid/pow(5, power);
    power++;
  }
  if (up == low) {
    return mid;
  }
  if (count >= target) {
    return bslb (low, mid, target);
  } else {
    return bslb (mid+1, up, target);
  }
}

int main () {
  long long low = 1, up = 10000000001, a, b;
  cin >> a >> b;
  cout << bs (low, up, b) - bslb (low, up, a) << endl;
}
