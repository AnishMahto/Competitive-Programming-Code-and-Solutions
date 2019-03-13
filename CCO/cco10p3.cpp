#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int id[10000001] = {0}, r[10000001] = {0}, getStuByRating[10000001] = {0};
vector <int> peeps;
vector <int>::iterator it;

void modify (int pos, int val) {
  while (pos <= 1000000) {
    r[pos] += val;
    pos += pos & (-pos);
  }
}

int query (int pos) {
  int sum = 0;
  while (pos > 0) {
    sum += r[pos];
    pos -= pos & (-pos);
  }
  return sum;
}

int solve (int k) {
  int low = 1, up = 1000000, mid;
  while (low != up) {
    mid = low + (up-low)/2;
    if (query(mid) >= k) {
      up = mid;
    } else {
      low = mid + 1;
    }
  }
  return mid;
}

int main () {
  int n, a, b, total = 0;
  scanint(n);
  char cmd;
  int order[n][3];
  
  for (int x = 0; x < n; x++) {
    scanf (" %c", &cmd);
    if (cmd == 'N') {
      order[x][0] = 1;
      scanint(order[x][1]); scanint(order[x][2]);
      peeps.push_back(order[x][2]);
    } else if (cmd == 'M') {
      order[x][0] = 2;
      scanint(order[x][1]); scanint(order[x][2]);
      peeps.push_back(order[x][2]);
    } else {
      order[x][0] = 3;
      scanint(order[x][1]);
    }
  }
  
  peeps.push_back(-1);
  sort (peeps.begin(), peeps.end());
  for (int x = 0; x < n; x++) {
    if (order[x][0] == 1) {
      total++;
      id[order[x][1]] = order[x][2];
      it = lower_bound(peeps.begin(), peeps.end(), order[x][2]);
      modify ((it - peeps.begin()), 1);
      getStuByRating[(it-peeps.begin())] = order[x][1];
      
    } else if (order[x][0] == 2) {
      it = lower_bound(peeps.begin(), peeps.end(), id[order[x][1]]);
      modify ((it - peeps.begin()), -1);
      getStuByRating[it-peeps.begin()] = 0;
      id[order[x][1]] = order[x][2];
      it = lower_bound(peeps.begin(), peeps.end(), order[x][2]);
      getStuByRating[it-peeps.begin()] = order[x][1];
      modify ((it - peeps.begin()), 1);
    } else {
      if (query (solve (total - order[x][1]+1)) != total - order[x][1]+1) {
        printf ("%d\n", getStuByRating[solve (total - order[x][1]+1)+1]);
      } else {
        printf ("%d\n", getStuByRating[solve (total - order[x][1]+1)]);
      }
    }
  }
}
