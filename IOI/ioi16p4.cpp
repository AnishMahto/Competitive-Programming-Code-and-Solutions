#include <iostream>
using namespace std;

int dp[200001][101] = {0}, psum[200001] = {0}, psumW[200001] = {0}, segs[101], n;
int B[200002] = {0}, W[200002] = {0};
char str[200002];

int inline solve (int pos, int K) {
    if (dp[pos][K] != 0) {
        return dp[pos][K];
    } else if (pos==0 && K==0) {
        dp[pos][K] = 1;
        return dp[pos][K];
    } else if (pos==0 && K != 0) {
        dp[pos][K] = -1;
        return dp[pos][K];
    } else {
        dp[pos][K] = -1;
        bool end = false;
        int canColour = -1, canSkip = -1;
        
        if (str[pos]!='X') {
            canSkip = solve (pos-1, K);
        }
        if (canSkip==1) {
            W[pos]++;
        }
        
        if (K > 0 && segs[K] <= pos && psumW[pos] - psumW[pos-segs[K]]==0 && str[pos-segs[K]] != 'X') {
            if (pos-segs[K] != 0) {
                //there must be at least one white space right after painting a segment
                canColour = solve (pos-segs[K]-1, K-1);
            } else {
                end = true;
                canColour = solve (pos-segs[K], K-1);
            }
        }
        if (canColour == 1) {
            B[pos-segs[K]+1]++;
            B[pos+1]--;
            if (!end) {
                W[pos-segs[K]]++;
            }
        }
        dp[pos][K] = max (canColour, canSkip);
        return dp[pos][K];
    }
}

string solve_puzzle(string s, int k, int c[]) {
    n = s.length();
    for (int x = 1; x <= k; x++) {
        segs[x] = c[x-1];
    }
    str[0] = '.';
    str[1] = s[0];
    if (s[0]=='X') {
        psum[1] = 1;
    } else if (s[0]=='_') {
        psumW[1] = 1;
    }
    for (int x = 2; x <= n; x++) {
        str[x] = s[x-1];
        if (s[x-1]=='X') { 
            psum[x]++;
        } else if (s[x-1]=='_') {
            psumW[x]++;
        }
        psumW[x] += psumW[x-1];
        psum[x] += psum[x-1];
    }
    solve (n, k);
    int ctr = B[0];
    string ans = "";
    bool possibleB, possibleW;
    for (int x = 1; x <= n; x++) {
        possibleB = false;
        possibleW = false;
        ctr += B[x];
        if (ctr > 0) {
            possibleB = true;
        }
        if (W[x] > 0) {
            possibleW = true;
        }
        if (possibleW && possibleB) {
            ans += '?';
        } else if (possibleB) {
            ans += 'X';
        } else {
            ans += '_';
        }
    }
    return ans;
}
