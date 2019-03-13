#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <iomanip>
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

double r, rpwr[200001], pp, seg[200001*4] = {0}, pVal[200001] = {0};
int n, pr, qidx[200001], sz[200001*4] = {0}, pre[200001];
vector < pair <double, int> > q;
vector < pair <double, int> > v;

void update (int pos, int l, int r, int tl, int tr, double val, bool del) {
    if (l > r || l > tr || r < tl) {
        return;
    } else if (l >= tl && r <= tr) {
        seg[pos] = val;
        if (del) {
            sz[pos] = 0;
        } else {
            sz[pos] = 1;
        }
    } else {
        int mid = (l+r)/2;
        update (2*pos, l, mid, tl, tr, val, del);
        update (2*pos+1, mid+1, r, tl, tr, val, del);
        seg[pos] = seg[2*pos+1] + rpwr[sz[2*pos+1]]*seg[2*pos];
        sz[pos] = sz[2*pos] + sz[2*pos+1];
    }
}

int main () {
    CL (pre, -1);
    fastCin;
    cin >> r >> n;
    rpwr[0] = 1;
    FORI (x,1,n) {
        rpwr[x] = rpwr[x-1]*r;
    }
    REP (x, n) {
        cin >> pr >> pp;
        q.pb (mp (pp, pr));
        v.pb (mp (pp, x));
    }
    sort (v.begin(), v.end());
    REP (x, n) {
        qidx[v[x].pS] = x;
    }
    REP (x, n) {
        int pr = q[x].pS;
        double pp = q[x].pF;
        if (pp > pVal[pr]) {
            if (pre[pr] != -1) {
                update (1,0,n-1,qidx[pre[pr]],qidx[pre[pr]], 0, true);
            }
            pVal[pr] = pp;
            pre[pr] = x;
            update (1,0,n-1,qidx[x],qidx[x], pp, false);
            
        }
        cout << setprecision(9) << seg[1] << "\n";
    }
}
