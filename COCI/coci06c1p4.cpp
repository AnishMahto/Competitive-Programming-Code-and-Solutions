#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <bitset>
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

int r, c, sp[52][52][2550], f[52][52], ex, ey, sx, sy;
bool rk[52][52] = {0};
deque < pii > q;
deque < pair <int, pii > > q2;


int main () {
    char cur;
    CL (sp, -1);
    CL (f, -1);
    si (r); si (c);
    FORI (x, 1, r) {
        FORI (i, 1, c) {
            scanf (" %c", &cur);
            if (cur == 'D') {
                ey = x;
                ex = i;
            } else if (cur == 'S') {
                REP (z, 2550) {
                    sp[x][i][z] = 0;
                }
                sy = x;
                sx = i;
            } else if (cur == '*') {
                f[x][i] = 0;
                q.pb (mp (x, i));
            } else if (cur == 'X') {
                rk[x][i] = true;
            }
        }
    }
    while (!q.empty()) {
        int px = q.front().pS, py = q.front().pF;
        q.pop_front();
        if (px+1 <= c && f[py][px+1] == -1 && !rk[py][px+1] && (py != ey || px+1 != ex)) {
            f[py][px+1] = f[py][px] + 1;
            q.pb (mp (py, px+1));
        }
        if (px-1 >= 1 && f[py][px-1] == -1 && !rk[py][px-1] && (py != ey || px-1 != ex)) {
            f[py][px-1] = f[py][px] + 1;
            q.pb (mp (py, px-1));
        }
        if (py+1 <= r && f[py+1][px] == -1 && !rk[py+1][px] && (py+1 != ey || px != ex)) {
            f[py+1][px] = f[py][px] + 1;
            q.pb (mp (py+1, px));
        }
        if (py-1 >= 1 && f[py-1][px] == -1 && !rk[py-1][px] && (py-1 != ey || px != ex)) {
            f[py-1][px] = f[py][px] + 1;
            q.pb (mp (py-1, px));
        }
    }
    if (f[sy][sx] != 0) {
        q2.pb (mp (0, mp (sy, sx)));
    }
    while (!q2.empty()) {
        int t = q2.front().pF, py = q2.front().pS.pF, px = q2.front().pS.pS;
        q2.pop_front();
        if (t > 2502 || px < 1 || px > c || py < 1 || py > r) {
            continue;
        }
        if (px+1 <= c && sp[py][px+1][t+1] == -1 && !rk[py][px+1] && (f[py][px+1] > t+1 || f[py][px+1] == -1)) {
            sp[py][px+1][t+1] = sp[py][px][t] + 1;
            q2.pb (mp (t+1, mp (py, px+1)));
        }
        if (px-1 >= 1 && sp[py][px-1][t+1] == -1 && !rk[py][px-1] && (f[py][px-1] > t+1 || f[py][px-1] == -1)) {
            sp[py][px-1][t+1] = sp[py][px][t] + 1;
            q2.pb (mp (t+1, mp (py, px-1)));
        }
        if (py+1 <= r && sp[py+1][px][t+1] == -1 && !rk[py+1][px] && (f[py+1][px] > t+1 || f[py+1][px] == -1)) {
            sp[py+1][px][t+1] = sp[py][px][t] + 1;
            q2.pb (mp (t+1, mp (py+1, px)));
        }
        if (py-1 >= 1 && sp[py-1][px][t+1] == -1 && !rk[py-1][px] && (f[py-1][px] > t+1 || f[py-1][px] == -1)) {
            sp[py-1][px][t+1] = sp[py][px][t] + 1;
            q2.pb (mp (t+1, mp (py-1, px)));
        }
    }
    REP (x, 2502) {
        if (sp[ey][ex][x] != -1) {
            cout << x << "\n";
            return 0;
        }
    }
    cout << "KAKTUS\n";
}
