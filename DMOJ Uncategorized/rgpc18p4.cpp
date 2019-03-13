#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

bool composite[(int)1e6+1] = {0};
long long nums[1000001], seg[4*1000001] = {0}, lazy[4*1000001] = {0};

void build (int pos, int l, int r) {
    if (l==r) {
        seg[pos] = nums[l];
    } else if (l > r) {
        return;
    } else {
        int mid = (l+r)/2;
        build (2*pos, l, mid);
        build (2*pos+1, mid+1, r);
        seg[pos] += seg[2*pos] + seg[2*pos+1];
    }
}

long long update (int pos, int l, int r, int tl, int tr, long long val) {
    if (l <= r) {
        seg[pos] += (lazy[pos])*(long long)(r-l+1);
        if (l != r) {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (l > r || l > tr || r < tl) {
        if (r >= l) {
            return seg[pos];
        } else {
            return 0;
        }
    } else if (l >= tl && r <= tr) {
        seg[pos] += val*(long long)(r-l+1);
        if (l != r) {
            lazy[2*pos] += val;
            lazy[2*pos+1] += val;
        }
        return seg[pos];
    } else {
        int mid = (l+r)/2;
        seg[pos] = update (2*pos, l, mid, tl, tr, val) + update (2*pos+1, mid+1, r, tl, tr, val);
    }
    return seg[pos];
}

long long query (int pos, int l, int r, int tl, int tr) {
    if (l <= r) {
        seg[pos] += (lazy[pos])*(long long)(r-l+1);
        if (l != r) {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (l > r || l > tr || r < tl) {
        return 0;
    } else if (l >= tl && r <= tr) {
        return seg[pos];
    } else {
        int mid = (l+r)/2;
        return query (2*pos, l, mid, tl, tr) + query (2*pos+1, mid+1, r, tl, tr);
    }
}

int main() {
    composite[1] = true;
    for (int x = 2; x <= 1000000; x++) {
        if (!composite[x]) {
            for (int i = x*2; i <= 1000000; i += x) {
                composite[i] = true;
            }
        }
    }
    long long n, t, cur, a, b, k;
    scanf ("%lld %lld", &n, &t);
    for (int x = 1; x <= n; x++) {
        scanf ("%lld", &nums[x]);
    }
    build (1, 1, n);
    long long leastCost = numeric_limits<long long>::max();
    for (long long x = 1; x <= t; x++) {
        scanf ("%lld %lld %lld", &a, &b, &k);
        if (!composite[x]) {
            if (leastCost==-1) {
                leastCost = x*(query (1, 1, n, a, b) + k);
            } else {
                leastCost = min (leastCost, x*(query (1, 1, n, a, b) + k));
            }
        } else {
            update (1, 1, n, a, b, k);
        }
    }
    printf ("%lld\n", leastCost);
    return 0;
}
