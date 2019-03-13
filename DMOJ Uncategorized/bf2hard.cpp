#include <stdio.h>
#include <iostream>
using namespace std;

int seed = 131, k;
int seedPower[1000001] = {0}, h[1000001] = {0};

int getSubstringHash (int s, int e) {
    s--;
    if (s < 0) {
        return h[e];
    }
    return h[e] - h[s]*seedPower[e-s];
}

bool check (int pos1, int pos2, int len) {
    
    if (getSubstringHash (pos1, pos1+len-1) == getSubstringHash (pos2, pos2+len-1)) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int posLeast = 0;
    string cur;
    cin >> cur;
    cin >> k;
    seedPower[0] = 1;
    for (int x = 1; x < 1000001; x++) {
        seedPower[x] = seedPower[x-1]*131;
    }
    h[0] = (int)cur[0];
    for (int x = 1; x < cur.length(); x++) {
        h[x] = h[x-1]*seed + (int)cur[x];
    }
    for (int x = 1; x <= cur.length()-k; x++) {
        int lo = 1, hi = k;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (check (posLeast, x, mid)) {
                lo=mid+1;
            } else {
                hi=mid;
            }
        }
        if (cur[x+lo-1] < cur[posLeast+lo-1]) {
            posLeast = x;
        }
    }
    for (int x = posLeast; x <= posLeast+k-1; x++) {
        cout << cur[x]; 
    } cout << endl;
    return 0;
}
