#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
int n, k = 2;
long long seed = 131, seedPower[200001], h[200001] = {0};
unordered_map <long long, int> dp;

bool inline check (int len) {
    dp.clear();
    unordered_map <long long, int>::iterator it;
    int count = 0;
    for (int x = len; x <= n; x++) {
        long long hash = h[x] - h[x-len]*seedPower[len];
        it = dp.find (hash);
        if (it != dp.end()) {
            it->second++;
            count = max (count, it->second);
        } else {
            count = max (count, 1);
            dp.insert (make_pair(hash, 1));
        }
    }
    if (count >= k) {
        return true;
    }
    return false;
}

int main() {
    seedPower[0] = 1;
    for (int x = 1; x < 200001; x++) {
        seedPower[x] = seedPower[x-1]*seed;
    }
    scanf ("%d", &n);
    char tmp;
    for (int x = 1; x <= n; x++) {
        scanf ("%c", &tmp);
        h[x] = h[x-1]*seed + (int)tmp;
    }
    int lo = 1, hi = n-1;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (check (mid)) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    printf ("%d\n", max(0, lo-1));
    return 0;
}
