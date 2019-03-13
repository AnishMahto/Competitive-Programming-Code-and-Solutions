#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int seg[100001*4] = {0};

int query (int pos, int l, int r, int tl, int tr) {
  if (l > r || l > tr || r < tl) {
    return 0;
  } else if (l >= tl && r <= tr) {
    return seg[pos];
  } else {
    int mid = (l+r)/2;
    return max (query(2*pos, l, mid, tl, tr), query (2*pos+1, mid+1, r, tl, tr));
  }
}

int modify (int pos, int l, int r, int tl, int tr, int val) {
  if (l > r) {
    return 0;
  } else if (l > tr || r < tl) {
    return seg[pos];
  } else if (l >= tl && r <= tr) {
    seg[pos] = max (seg[pos], val);
  } else {
    int mid = (l+r)/2;
    seg[pos] = max (modify(2*pos, l, mid, tl, tr, val), modify (2*pos+1, mid+1, r, tl, tr, val));
  }
  return seg[pos];
}

int main() {
  vector < pair <int, int> > box, boxes;
  int n, a, b;
  scanf ("%d", &n);
  for (int x = 0; x < n; x++) {
    scanf ("%d %d", &a, &b);
    box.push_back(make_pair(a, b));
  }
  sort (box.begin(), box.end());
  for (int x = 0; x < box.size(); x++) {
    if (x==0 || box[x] != box[x-1]) {
      boxes.push_back(box[x]);
    }
  }
  int pos = 0;
  int processed[100001] = {0};
  processed[boxes.size()-1]=-1;
  while (processed[boxes.size()-1] == -1) {
    for (int ptr = pos; ptr <= boxes.size(); ptr++) {
      if (boxes[pos].first != boxes[ptr].first || ptr == boxes.size()) {
        for (int x = pos; x < ptr; x++) {
          modify (1, 1, 100000, boxes[x].second, boxes[x].second, processed[x]);
        }
        pos = ptr;
        break;
      } else {
        processed[ptr] = query (1, 1, 100000, 0, boxes[ptr].second-1) + 1; 
      }
    }
  }
  cout << seg[1] << endl;
}
