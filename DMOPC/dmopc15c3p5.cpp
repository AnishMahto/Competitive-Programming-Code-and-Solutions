#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
using namespace std;

vector <long long> nums;
map <long long, int> sums;
long long ans = 0;
int n, m;

void genSum (int pos, int end, long long sum, bool empty) {
    if (pos==end+1) {
        if (empty) {
            return;
        }
        //cout << sum << "!" << endl;
        if (sum==0) {
            ans++;
        }
        map<long long, int>::iterator it = sums.find(sum);
        if (it != sums.end()) {
            it->second++;
        } else {
            sums.insert (make_pair(sum, 1));
        }
    } else {
        genSum (pos+1, end, sum, empty);
        genSum (pos+1, end, sum+nums[pos], false);
    }
}

void genSum2 (int pos, int end, long long sum, bool empty) {
    if (pos==end+1) {
        if (empty) {
            return;
        }
        if (sum==0) {
            ans++;
        }
        map<long long, int>::iterator it = sums.find(-sum);
        if (it != sums.end()) {
            ans += it->second;
        }
    } else {
        genSum2 (pos+1, end, sum, empty);
        genSum2 (pos+1, end, sum+nums[pos], false);
    }
}

int main () {
    int cur;
    scanf ("%d %d", &n, &m);
    for (int x = 0; x < n; x++) {
        scanf ("%d", &cur);
        nums.push_back(cur);
    }
    for (int x = 0; x < m; x++) {
        scanf ("%d", &cur);
        nums.push_back(-cur);
    }
    genSum (0, (n+m-1)/2, 0, true);
    genSum2 ((n+m-1)/2+1, n+m-1, 0, true);
    cout << ans << endl;
}
