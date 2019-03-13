#include <iostream>
#include <cstdio>
using namespace std;

int firstCol[100001*4] = {0}, lazyFirst[100001*4] = {0}, cakePerCol[100001*4] = {0}, lazyCake[100001*4] = {0}, lastCol[100001*4] = {0}, lazyLast[100001*4] = {0};

void updateF (int pos, int l, int r, int tl, int tr, int val) {
  if (lazyFirst[pos] != 1000000000) {
    firstCol[pos] = min (firstCol[pos], lazyFirst[pos]);
    if (l != r) {
      lazyFirst[2*pos] = min (lazyFirst[2*pos], lazyFirst[pos]);
      lazyFirst[2*pos+1] = min (lazyFirst[2*pos+1], lazyFirst[pos]);
    }
    lazyFirst[pos] = 1000000000;
  }
  if (l > r || l > tr || r < tl) {
    return;
  } else if (l >= tl && r <= tr) {
    firstCol[pos] = min (firstCol[pos], val);
    if (l != r) {
      lazyFirst[2*pos] = min (lazyFirst[2*pos], val);
      lazyFirst[2*pos+1] = min (lazyFirst[2*pos+1], val);
    }
    return;
  }
  int mid = l + (r-l)/2;
  updateF(2*pos, l, mid, tl, tr, val);
  updateF(2*pos+1, mid+1, r, tl, tr, val);
}
int qF (int pos, int l, int r, int tl, int tr) {
  if (lazyFirst[pos] != 1000000000) {
    firstCol[pos] = min (firstCol[pos], lazyFirst[pos]);
    if (l != r) {
      lazyFirst[2*pos] = min (lazyFirst[2*pos], lazyFirst[pos]);
      lazyFirst[2*pos+1] = min (lazyFirst[2*pos+1], lazyFirst[pos]);
    }
    lazyFirst[pos] = 1000000000;
  }
  if (l > r || l > tr || r < tl) {
    return 1000000000;
  } else if (l >= tl && r <= tr) {
    return firstCol[pos];
  } else {
    int mid = l + (r-l)/2;
    return min (qF(2*pos, l, mid, tl, tr), qF(2*pos+1, mid+1, r, tl, tr));
  }
}
void updateL (int pos, int l, int r, int tl, int tr, int val) {
  if (lazyLast[pos] != 0) {
    lastCol[pos] = max (lastCol[pos], lazyLast[pos]);
    if (l != r) {
      lazyLast[2*pos] = max (lazyLast[2*pos], lazyLast[pos]);
      lazyLast[2*pos+1] = max (lazyLast[2*pos+1], lazyLast[pos]);
    }
    lazyLast[pos] = 0;
  }
  if (l > r || l > tr || r < tl) {
    return;
  } else if (l >= tl && r <= tr) {
    lastCol[pos] = max (lastCol[pos], val);
    if (l != r) {
      lazyLast[2*pos] = max (lazyLast[2*pos], val);
      lazyLast[2*pos+1] = max (lazyLast[2*pos+1], val);
    }
    return;
  }
  int mid = l + (r-l)/2;
  updateL(2*pos, l, mid, tl, tr, val);
  updateL(2*pos+1, mid+1, r, tl, tr, val);
}
int qL (int pos, int l, int r, int tl, int tr) {
  if (lazyLast[pos] != 0) {
    lastCol[pos] = max (lastCol[pos], lazyLast[pos]);
    if (l != r) {
      lazyLast[2*pos] = max (lazyLast[2*pos], lazyLast[pos]);
      lazyLast[2*pos+1] = max (lazyLast[2*pos+1], lazyLast[pos]);
    }
    lazyLast[pos] = 0;
  }
  if (l > r || l > tr || r < tl) {
    return 0;
  } else if (l >= tl && r <= tr) {
    return lastCol[pos];
  } else {
    int mid = l + (r-l)/2;
    return max (qL(2*pos, l, mid, tl, tr), qL(2*pos+1, mid+1, r, tl, tr));
  }
}

int main () {
  int r, c, a, b, prevA, prevB, rowCmd[100001][2];
  scanf ("%d %d", &r, &c);
  for (int x = 0; x <= c*4; x++) {
    firstCol[x] = lazyFirst[x] = 1000000000;
  }
  bool unconnected = false;
  for (int x = 1; x <= r; x++) {
    scanf ("%d %d", &a, &b);
    rowCmd[x][0] = a;
    rowCmd[x][1] = b;
    updateF (1, 1, c, a, b, x);
    updateL (1, 1, c, a, b, x);
    cakePerCol[a]++;
    cakePerCol[b+1]--;
    if (x > 1 && !(a <= prevB && a >= prevA) && !(b <= prevB && b >= prevA) && !(prevA <= b && prevA >= a) && !(prevB <= b && prevB >= a)) {
      //check if current segment is contained in previous segment, or if previous segment is contained in current segment
      unconnected = true;
    }
    prevA = a;
    prevB = b;
  }
  for (int x = 1; x <= c; x++) {
    cakePerCol[x] += cakePerCol[x-1];
  }
  for (int x = 1; x <= c; x++) {
    scanf ("%d %d", &a, &b);
    if (a != qF(1, 1, c, x, x) || b != qL(1, 1, c, x, x) || cakePerCol[x] != b-a+1) {
      printf ("nonsense\n");
      for (int i = 1; i <= r; i++) {
        if (i >= a && i <= b) {
          //there should be cake at this pos
          if (rowCmd[i][0] > x || rowCmd[i][1] < x) {
            printf ("%d %d\n", i, x);
            return 0;
          }
        } else {
          //there shouldn't be cake at this pos
          if (rowCmd[i][0] <= x && rowCmd[i][1] >= x) {
            printf ("%d %d\n", i, x);
            return 0;
          }
        }
      }
    } 
  }
  if (unconnected) {
    printf ("nonsense\nunconnected\n");
    return 0;
  }
  printf ("sense\n");
}
