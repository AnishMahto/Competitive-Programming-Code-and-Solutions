#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[651][651] = {0};

int main () {
  int n;
  scanf ("%d", &n);
  vector < pair <int, int> > c(n);
  for (int x = 0; x < n; x++) {
    scanf ("%d %d", &c[x].first, &c[x].second);
    arr[c[x].first][c[x].second]++;
  }
  for (int x = 0; x <= 650; x++) {
    for (int i = 0; i <= 650; i++) {
      if (i != 0) {
        arr[x][i] += arr[x][i-1];
      }
    }
  }
  for (int x = 0; x <= 650; x++) {
    for (int i = 0; i <= 650; i++) {
      if (x!=0) {
        arr[x][i] += arr[x-1][i];
      }
    }
  }
  for (int x = 0; x < n; x++) {
    int worse = arr[max(0, c[x].first-1)][max(0, c[x].second-1)]; //ppl who score worse than you on both contests
    if (c[x].first==0 || c[x].second==0) {
      worse = 0;
    }
    printf ("%d ", (arr[650][650] - arr[650][c[x].second] - arr[c[x].first][650] + arr[c[x].first][c[x].second])+1);
    
    if (c[x].first==650) {
      worse += arr[0][c[x].second];
      if (c[x].second > 0) {
        worse -= arr[0][c[x].second-1];
      }
    }
    if (c[x].second==650) {
      worse += arr[c[x].first][0];
      if (c[x].first > 0) {
        worse -= arr[c[x].first-1][0];
      }
    }
    printf ("%d\n", n-worse);
  }
}
