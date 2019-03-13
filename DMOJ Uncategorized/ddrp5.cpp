#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n, q, f, s[1001] = {0}, e[1001] = {0}, segMax[1000001*4][2], segMin[1000001*4][2], nums[1000001];

void build (int pos, int l, int r) {
    if (l > r) {
        for (int x = 0; x < 2; x++) {
            segMax[pos][x] = -1;
            segMin[pos][x] = (int)1e9+1;
        }
        return;
    } else if (l==r) {
        segMax[pos][0] = segMin[pos][0] = nums[l];
        segMin[pos][1] = (int)1e9+1;
        segMax[pos][1] = -1;
    } else {
        int mid = (l+r)/2;
        build (2*pos, l, mid);
        build (2*pos+1, mid+1, r);
        
        segMax[pos][0] = max (segMax[2*pos][0], segMax[2*pos+1][0]);
        segMax[pos][1] = max(max(segMax[2*pos][1], segMax[2*pos+1][1]), min(segMax[2*pos][0], segMax[2*pos+1][0]));
        
        segMin[pos][0] = min (segMin[2*pos][0], segMin[2*pos+1][0]);
        segMin[pos][1] = min (min(segMin[2*pos][1], segMin[2*pos+1][1]),  max(segMin[2*pos][0], segMin[2*pos+1][0]));
        
    }
}

pair <int, int> query (int pos, int l, int r, int tl, int tr, bool g) {
    if (l > r || r < tl || l > tr) {
        if (g) {
            return make_pair (-1, -1);
        } else {
            return make_pair ((int)1e9+1, (int)1e9+1);
        }
    } else if (l >= tl && r <= tr) {
        if (g) {
            return make_pair (segMax[pos][0], segMax[pos][1]);
        } else {
            return make_pair (segMin[pos][0], segMin[pos][1]);
        }
    } else {
        int mid = (l+r)/2;
        pair <int, int> L = query (2*pos, l, mid, tl, tr, g), R = query (2*pos+1, mid+1, r, tl, tr, g), ans;
        if (g) {
            ans = make_pair(-1, -1);
            ans.first = max (L.first, R.first);
            ans.second = max(max(L.second, R.second), min(L.first, R.first));
        } else {
            ans = make_pair ((int)1e9+1, (int)1e9+1);
            ans.first = min (L.first, R.first);
            ans.second = min (min(L.second, R.second),  max(L.first, R.first));
        }
        return ans;
    }
}

void update (int pos, int l, int r, int tl, int tr, int val) {
    if (l > r || l > tr || r < tl) {
        return;
    } else if (l >= tl && r <= tr) {
        segMax[pos][0] = segMin[pos][0] = val;
    } else {
        int mid = (l+r)/2;
        update (2*pos, l, mid, tl, tr, val);
        update (2*pos+1, mid+1, r, tl, tr, val);
        segMax[pos][0] = max (segMax[2*pos][0], segMax[2*pos+1][0]);
        segMax[pos][1] = max(max(segMax[2*pos][1], segMax[2*pos+1][1]), min(segMax[2*pos][0], segMax[2*pos+1][0]));
        
        segMin[pos][0] = min (segMin[2*pos][0], segMin[2*pos+1][0]);
        segMin[pos][1] = min (min(segMin[2*pos][1], segMin[2*pos+1][1]),  max(segMin[2*pos][0], segMin[2*pos+1][0]));
    }
}

int main () {
    int t, a, b;
    memset (segMin, -1, sizeof(segMin));
    memset (segMax, -1, sizeof(segMax));
    scanf ("%d %d", &n, &q);
    for (int x = 1; x <= n; x++) {
        scanf ("%d", &nums[x]);
        f = (int)ceil ((double)x/sqrt((double)n));
        if (s[f]==0) {
            s[f] = x;
        }
        e[f] = x;
    }
    build (1, 1, n);
    
    int prevAns = 0;
    pair <int, int> ans;
    for (int x = 0; x < q; x++) {
        scanf ("%d %d %d", &t, &a, &b);
        a ^= prevAns;
        b ^= prevAns;
        if (t==1) {
            update (1, 1, n, a, a, b);
            continue;
        } else if (t==2) {
            ans = query (1, 1, n, s[a], e[b], false);
        } else {
            ans = query (1, 1, n, s[a], e[b], true);
        }
        int sum = 0;
        if (ans.first != -1 && ans.first != (int)1e9+1) {
            sum += ans.first;
        }
        if (ans.second != -1 && ans.second != (int)1e9+1) {
            sum += ans.second;
        }
        printf ("%d\n", sum);
        prevAns = sum;
    }
}
