#include <iostream>
#include <cstdio>
#include <math.h>
#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;

const int rt = (int)sqrt (200000.0)+1;
int startB[200001], endB[200001], idx[200001], divs[rt][200001] = {0}, nums[200001];

void add (int pos, int val) {
    for (int x = 1; x <= sqrt(val); x++) {
        if (val%x==0) {
            if (val/x == x) {
                divs[idx[pos]][x]++;
            } else {
                divs[idx[pos]][x]++;
                divs[idx[pos]][val/x]++;
            }
        }
    }
    nums[pos] = val;
}
void rem (int pos) {
    int val = nums[pos];
    for (int x = 1; x <= sqrt(val); x++) {
        if (val%x==0) {
            if (val/x == x) {
                divs[idx[pos]][x]--;
            } else {
                divs[idx[pos]][x]--;
                divs[idx[pos]][val/x]--;
            }
        }
    }
}

int query (int l, int r, int v) {
    int ans = 0;
    for (int x = idx[l]+1; x <= idx[r]-1; x++) {
        ans += divs[x][v];
    }
    if (idx[l] != idx[r]) {
        for (int x = l; x <= endB[l]; x++) {
            if (nums[x]%v==0) {
                ans++;
            }
        }
        for (int x = r; x >= startB[r]; x--) {
            if (nums[x]%v==0) {
                ans++;
            }
        }
    } else {
        for (int x = l; x <= r; x++) {
            if (nums[x]%v==0) {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int n, q, t, a, b, v;
    scan (n); scan(q);
    for (int x = 1; x <= n; x++) {
        idx[x] = x/rt;
        if (x==1) {
            startB[x] = x;
        } else if (idx[x] == idx[x-1]) {
            startB[x] = startB[x-1];
        } else {
            startB[x] = x;
        }
        scan (nums[x]);
        add (x, nums[x]);
    }
    for (int x = n; x >= 1; x--) {
        if (x==n) {
            endB[x] = x;
        } else if (idx[x] == idx[x+1]) {
            endB[x] = endB[x+1];
        } else {
            endB[x] = x;
        }
    }
    while (q--) {
        scan (t);
        if (t==2) {
            scan (a); scan (b);
            rem (a);
            add (a, b);
        } else {
            scan (a); scan (b); scan(v);
            printf ("%d\n", query (a, b, v));
        }
    }
    return 0;
}
