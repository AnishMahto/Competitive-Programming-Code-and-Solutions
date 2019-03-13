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

int n;
ll startMask = 0;
bool v[35*1000001] = {0};
deque < pair <ll, int> > q;
int ans = 0;

void check (ll mask, int cost) {
    int ctr = 0;
    ll tmpMask = mask;
    REP (x, n) {
        if (READ (mask, x)) {
            ctr++;
        } 
        if (x == n-1 || !READ (mask, x)) {
            if (ctr >= 4) {
                int i;
                if (!READ (mask, x)) {
                    i = x-1;
                } else {
                    i = x;
                }
                for (; i >= 0; i--) {
                    if (READ (mask, i)) {
                        TOGGLE (tmpMask, i);
                    } else {
                        break;
                    }
                }
            }
            ctr = 0;
        }
    }
    if (v[tmpMask] == false) {
        q.pb (mp(tmpMask, cost));
        v[tmpMask] = true;
    }
}

void bfs () {
    q.pb (mp(startMask, 0));
    v[startMask] = true;
    while (!q.empty()) {
        int cst = q.front().second;
        ll curMask = q.front().first;
        if (curMask == 0) {
            ans = cst;
            return;
        }
        q.pop_front();
        REP (x, n) {
            if (!READ (curMask, x)) {
                SET (curMask, x);
                check (curMask, cst+1);
                TOGGLE (curMask, x);
            }
        }
    }
}

int main () {
    int bit;
    si (n);
    REP (x, n) {
        si (bit);
        if (bit!=0) {
            SET (startMask, x);
        }
    }
    bfs();
    cout << ans << "\n";
}
