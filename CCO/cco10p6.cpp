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
#define GCD(a,b) __gcd((a),(b))
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

int cyc[100] = {0}, tot = 0, m[100] = {0}, fin[100] = {0};
bool imp[100] = {0};
vector < vi > c(101);

int main () {
    fastCin;
    char cur;
    int s = (int)'A', e = (int)'Z', N;
    FORI (x, s, e) {
        imp[x] = true;
    }
    imp['_'] = true;
    FORI (x, s, e) {
        cin >> cur;
        m[x] = (int)cur;
    }
    cin >> cur;
    m['_'] = (int)cur;
    FORI (x, s, 100) {
        if (!imp[x]) {
            continue;
        }
        if (cyc[x] == 0) {
            tot++;
            int pos = x;
            while (cyc[pos] == 0) {
                c[tot].pb (pos);
                cyc[pos] = tot;
                pos = m[pos];
            }
        }
    }
    cin >> N;
    FORI (x, s, 100) {
        if (!imp[x]) {
            continue;
        }
        int sz = c[cyc[x]].size(), pos, rem = N%sz;
        REP (i, sz) {
            if (c[cyc[x]][i] == x) {
                pos = i;
                break;
            }
        }
        while (rem > 0) {
            pos++;
            rem--;
            if (pos >= sz) {
                pos = 0;
            }
        }
        fin[x] = c[cyc[x]][pos];
    }
    string tmp;
    cin >> tmp;
    REP (x, (int)tmp.length()) {
        cout << (char)fin[(int)tmp[x]];
    }
}
