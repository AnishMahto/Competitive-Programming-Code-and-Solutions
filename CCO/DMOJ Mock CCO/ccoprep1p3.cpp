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
#define GCD(a,b) __gcd((a),(b))
#define dbl(x) (double)(x)
#define vi vector <int>
#define vii vector < pair <int, int> >
#define vll vector <long long>
#define fastCin cin.sync_with_stdio(0);cin.tie(0)
#define scanUnsigned(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define printArr(a,l) cout<<#a<<": ";for(int i=0;i<(l);i++){cout<<a[i]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(int i=0;i<(r);i++){for(int j=0;j<(c);j++){cout<<a[i][j]<<" ";}cout<<endl;}
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less
using namespace __gnu_pbds;
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> BST;

int sz[100001] = {0}, rnk[100001] = {0}, rnkToStu[100001];
BST bst[100001];
int dsu[100001] = {0};

int find (int pos) {
    if (dsu[pos] != pos) {
        dsu[pos] = find (dsu[pos]);
    }
    return dsu[pos];
}

void comb (int a, int b) {
    //add bst b into bst a
    REP (x, sz[b]) {
        bst[a].insert (*bst[b].find_by_order(x));
    }
    sz[a] += sz[b];
    sz[b] = 0;
}

void merge (int a, int b) {
    if (find (a) == find (b)) {
        return;
    }
    if (sz[find(a)] >= sz[find(b)]) {
        comb (find(a), find(b));
        dsu[find(b)] = find(a); 
    } else {
        comb (find(b), find(a));
        dsu[find (a)] = find (b);
    }
}

int main () {
    int n, m, a, b, q;
    char cmd;
    si (n); si (m);
    FORI (x, 1, n) {
        si (rnk[x]);
        dsu[x] = x;
        sz[x] = 1;
        bst[x].insert (rnk[x]);
        rnkToStu[rnk[x]] = x;
    }
    REP (x, m) {
        si (a); si (b);
        merge (a, b);
    }
    si (q);
    REP (x, q) {
        scanf (" %c", &cmd); si (a); si (b);
        if (cmd == 'B') {
            merge (a, b);
        } else {
            if (b > sz[find(a)]) {
                printf ("-1\n");
                continue;
            }
            printf ("%d\n", rnkToStu[*bst[find (a)].find_by_order(b-1)]);
        }
    }
}
