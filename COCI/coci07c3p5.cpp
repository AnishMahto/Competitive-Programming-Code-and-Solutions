#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#define SET(x,y) x |= (1 << y)
#define CLEAR(x,y) x &= ~(1<< y)
#define READ(x,y) ((0u == (x & (1<<y)))?0u:1u)
#define TOGGLE(x,y) (x ^= (1<<y))
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pF first
#define pS second
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORI(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define CL(a,b) memset(a,b,sizeof(a))
#define sqr(x) ((x)*(x))
#define intLIMIT numeric_limits<int>
#define longLIMIT numeric_limits<long long>
#define dbl(x) (double)(x)
#define vi vector <int>
#define vii vector < pair <int, int> >
#define vll vector <long long>
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

string num;
ll dp[16][136][2] = {0};

ll solve (int d, int rem, bool less) {
    if (dp[d][rem][less] != -1) {
        return dp[d][rem][less];
    } else if (rem == 0) {
        dp[d][rem][less] = 1;
        return dp[d][rem][less];
    } else if (d == 0) {
        dp[d][rem][less] = 0;
        return dp[d][rem][less];
    } else {
        dp[d][rem][less] = 0;
        if (less) {
            FORI (x, 0, min(9, rem)) {
                dp[d][rem][less] += solve (d-1, rem-x, less);
            }
        } else {
            int curDigit = (int)num[d-1] - '0';
            FORI (x, 0, min(curDigit, rem)) {
                if (x==curDigit) {
                    dp[d][rem][less] += solve (d-1, rem-x, less);
                } else {
                    dp[d][rem][less] += solve (d-1, rem-x, true);
                }
            }
        }
    }
    return dp[d][rem][less];
}

ll helper (ll n, int s) {
    int len, curDigit;
    ll tmp = 0;
    CL (dp, -1);
    num = to_string (n);
    reverse (num.begin(), num.end());
    len = (int)num.length();
    curDigit = (int)num[len-1] - '0';
    FORI (x, 0, min (curDigit, s)) {
        if (x==curDigit) {
            tmp += solve (len-1, s-x, false);
        } else {
            tmp += solve (len-1, s-x, true);
        }
    }
    return tmp;
}

int main () {
    ll ansB = 0, ansA = 0, a, b;
    int s, curD;
    cin >> a >> b >> s;
    ansB = helper (b, s);
    ansA = helper (a-1, s);
    cout << ansB - ansA << endl;
    string ans2 = to_string(a);
    int rem = s, len = (int)ans2.length();
    REP (x, len) {
        rem -= (int)ans2[x] - '0';
    }
    if (rem > 0) {
        for (int x = len-1; x >= 0; x--) {
            curD = (int)ans2[x] - '0';
            if (9-curD <= rem) {
                rem -= 9 - curD;
                ans2[x] = (char)(9 + (int)'0');
            } else {
                ans2[x] = (char)(curD + rem + '0');
                rem = 0;
                break;
            }
        }
        string lead = "";
        while (rem - 9 >= 0) {
            rem -= 9;
            lead += (char)(9 + (int)'0');
        }
        if (rem > 0) {
            lead += (char)(rem + (int)'0');
        }
        if ((int)lead.length() > 0) {
            reverse (lead.begin(), lead.end());
            cout << lead;
        }
        cout << ans2 << endl;
    } else {
        deque <char> curNum;
        REP (x, len) {
            curNum.push_front (num[x]);
        }
        while (rem < 0) {
            rem--;
            REP (x, (int)curNum.size()) {
                curD = (int)curNum[x] - '0';
                if (rem + curD <= 0) {
                    rem += curD;
                    curNum[x] = '0';
                } else {
                    curNum[x] = (char)((curD - rem) + '0');
                    rem = 0;
                }
                if (rem == 0) {
                    break;
                }
            }
            curNum.push_front (1);
            REP (x, (int)curNum.size()) {
                cout << curNum[x];
            } cout << endl;
        }
    }
}
