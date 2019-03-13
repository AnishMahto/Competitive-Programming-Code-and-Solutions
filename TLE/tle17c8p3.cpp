#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <set>
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

vll pals;
set <ll> found;
set <ll>::iterator it;
ll p[11] = {0};
ll k, a, b;

ll conv (string cur) {
    ll sum = 0;
    REP (x, (int)cur.length()) {
        sum += ((int)cur[x] - (int)'0')*p[(int)cur.length()-x-1];
    }
    return sum;
}

void add (string cur) {
    ll num = conv (cur);
    if (num > 0 && num%k == 0) {
        it = found.find (num);
        if (it == found.end()) {
            found.insert (num);
            pals.pb (num);
        }
    }
}

void genPal (int n, string cur) {
    if (cur.length() == n/2) {
        string suf = "";
        for (int x = cur.length()-1; x >= 0; x--) {
            suf += cur[x];
        }
        if ((int)cur.length()*2 == n) {
            add (cur + suf);
        } else {
            FORI (x, 0, 9) {
                add (cur + (char)(x+'0') + suf);
            }
        }
    } else {
        FORI (x, 0, 9) {
            if (x==0 && cur.length() == 0) {
                continue;
            }
            genPal (n, cur + (char)(x+'0'));
        }
    }
}

int main () {
    vll::iterator it, it2;
    REP (x, 11) {
        if (x==0) {
            p[x] = 1;
        } else {
            p[x] = p[x-1]*10;
        }
    }
    int q;
    si (q); sl (k);
    FORI (x, 1, 10) {
        genPal (x, "");
    }
    REP (x, q) {
        sl (a); sl (b);
        it = lower_bound (pals.begin(), pals.end(), a);
        it2 = upper_bound (pals.begin(), pals.end(), b);
        if (it == pals.end()) {
            printf ("0\n");
        } else if (it2 == pals.end()) {
            printf ("%lld\n", (int)pals.size() - (it-pals.begin()));
        } else {
            printf ("%lld\n", (it2-pals.begin()) - (it-pals.begin()));
        }
    }
}
