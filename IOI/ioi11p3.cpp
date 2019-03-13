#include <iostream>
using namespace std;

long long psum[100001];

long long inline sum (int l, int r) {
    if (l==0) {
        return psum[r];
    } else {
        return psum[r] - psum[l-1];
    }
}

int besthub(int R, int L, int X[], long long B) {
    for (int x = 0; x < R; x++) {
        psum[x] = X[x];
        if (x > 0) {
            psum[x] += psum[x-1];
        }
    }
    long long greatest = 0;
    for (int x = 0; x < R; x++) {
        long long lo = 0, hi = R-1-x, mid, median, idx;
        while (lo < hi) {
            mid = (lo+hi)/2;
            if ((mid+1)%2==0) {
                median = (X[x+mid/2] + X[x+mid/2+1])/2;
            } else {
                median = X[x+mid/2];
            }
            idx = x+mid/2;
            if ((idx-x+1)*median-sum(x, idx) + sum (idx+1, x+mid) - (x+mid-(idx+1)+1) * median <= B) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        
        
        if ((lo+1)%2==0) {
            median = (X[x+lo/2] + X[x+lo/2+1])/2;
        } else {
            median = X[x+lo/2];
        }
        idx = x+lo/2;
        if ((idx-x+1)*median-sum(x, idx) + sum (idx+1, x+lo) - (x+lo-(idx+1)+1) * median <= B) {
            lo = lo;
        } else {
            lo--;
        }
        
        greatest = max (greatest, lo+1);
    }
    return (int)greatest;
}

int main() {
    return 0;
}
