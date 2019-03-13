#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

int n, k, arr[3*100001];

bool check (double avg) {
    deque <double> dq;
    double runningSum = 0, smallestPreSum = 0;
    for (int x = 1; x <= k-1; x++) {
        runningSum += arr[x];
        runningSum -= avg;
        dq.push_back(runningSum);
    }
    for (int x = k; x <= n; x++) {
        runningSum += arr[x];
        runningSum -= avg;
        dq.push_back(runningSum);
        if (runningSum - smallestPreSum >= 0) {
            return true;
        } else {
            smallestPreSum = min (smallestPreSum, dq[x-k]);
        }
    }
    return false;
}

int main() {
    scanf ("%d %d", &n, &k);
    for (int x = 1; x <= n; x++) {
        scanf ("%d", &arr[x]);
    }
    int lo = 1, hi = 1e6, mid, curAns;
    while (lo < hi) {
        mid = (lo+hi)/2;
        if (check (mid)) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    curAns = lo-1;
    int maxDecimals = 1000000;
    lo = 0; hi = maxDecimals;
    while (lo < hi) {
        mid = (lo+hi)/2;
        double realMid = (double)mid/(double)maxDecimals + curAns;
        if (check (realMid)) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    printf ("%d.", curAns);
    for (int x = 0; x < 6-to_string(lo-1).length(); x++) {
        printf ("0");
    }
    printf ("%d\n", lo-1);
    return 0;
}
