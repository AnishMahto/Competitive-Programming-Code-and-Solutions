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

int val[11][11] = {0};
vector < pii > dep[11][11];

int convStrToInt (string str) {
    int sum = 0, digit;
    REP (x, (int)str.length()) {
        digit = (int)str[x] - (int)'0';
        sum += digit * pow (10, (int)str.length()-x-1);
    }
    return sum;
}

void cleanStr (string str, int y, int x) {
    if (str[0] >= '0' && str[0] <= '9') {
        val[y][x] = convStrToInt (str);
    } else {
        val[y][x] = -1;
        int pos = 0;
        while (pos < str.length()) {
            dep[y][x].pb (mp((int)str[pos]-(int)'A' + 1, (int)str[pos+1]-(int)'0'));
            pos += 3;
        }
    }
}

bool v[11][11] = {0}, cycle = false;

int solve (int y, int x) {
    if (cycle) {
        return -1;
    }
    if (val[y][x] != -1) {
        return val[y][x];
    } else {
        if (v[y][x]) {
            cycle = true;
            return -1;
        }
        v[y][x] = true;
        int sum = 0, tmp;
        REP (z, (int)dep[y][x].size()) {
            tmp = solve (dep[y][x][z].pF, dep[y][x][z].pS);
            if (tmp == -1) {
                return -1;
            }
            sum += tmp;
        }
        val[y][x] = sum;
        return sum;
    }
}

int main () {
    string cur;
    FORI (x, 1, 10) {
        FORI (i, 1, 9) {
            cin >> cur;
            cleanStr (cur, x, i);
        }
    }
    
    FORI (x, 1, 10) {
        FORI (i, 1, 9) {
            CL (v, 0);
            solve (x, i);
            if (cycle) {
                cout << "* ";
            } else {
                cout << val[x][i] << " ";
            }
            cycle = false;
        } pnl;
    }
}
