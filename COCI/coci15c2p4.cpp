#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <math.h>
using namespace std;

unordered_map <int, int> dp;

//hash[i] = hash[i-1]*seed + s[i]
//to get the hash value of the substring: hash[j] - hash[i]*seed^(length of substring)

long long seed = 131;

int main()
{
    unordered_map<int, int>::iterator it;
    int ans = 0;
    int seedPower[2000001] = {0};
    seedPower[0] = 1;
    for (int x = 1; x <= 2000000; x++) {
        seedPower[x] = seedPower[x-1]*seed;
    }
    int n;
    string cur;
    cin >> n;
    int h[2000001] = {0};
    for (int i = 0; i < n; i++) {
        int curAns = 0;
        cin >> cur;
        int len = cur.length();
        h[0] = (int)cur[0];
        for (int x = 1; x < cur.length(); x++) {
            h[x] = h[x-1]*seed + (int)cur[x];
        }
        for (int x = 0; x < cur.length(); x++) {
            if (h[x] == h[cur.length()-1] - h[cur.length()-1-(x+1)]*seedPower[x+1]) {
                it = dp.find(h[x]);
                if (it!=dp.end()) {
                    curAns = max(it->second, curAns);
                }
            }
        }
        dp.erase(h[cur.length()-1]);
        dp.insert (make_pair(h[cur.length()-1], curAns+1));
        ans = max (ans, curAns+1);
    }
    cout << ans << endl;
    return 0;
}
