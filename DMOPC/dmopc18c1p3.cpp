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

int main () {
    int n;
    cin >> n;
    int nums[101];
    bool v[101] = {0};
    FORI (x, 1, n) {
        cin >> nums[x];
    }
    vector < vector <int> > steps;
    vector <int> endPoints, vals;
    FORI (x, 1, n) {
        if (!v[x]) {
            v[x] = true;
            int pos = x, start = x;
            while (nums[pos] != start) {
                v[nums[pos]] = true;
                pos = nums[pos];
            }
            endPoints.pb (pos);
            vals.pb (nums[pos]);
        }
    }
    if (endPoints.size() > 1) {
    steps.pb (endPoints);
        FORI (x, 1, endPoints.size()) {
            nums[endPoints[x]] = vals[x-1];
        }
        nums[endPoints[0]] = vals[endPoints.size()-1];
    }
    FORI (x, 1, n) {
        if (nums[x] != x) {
            vector <int> tmp;
            int pos = x, start = x;
            tmp.pb (pos);
            while (nums[pos] != start) {
                tmp.pb (nums[pos]);
                pos = nums[pos];
            }
            steps.pb (tmp);
            REP (i, (int)tmp.size()) {
                nums[tmp[i]] = tmp[i];
            }
        }
    }
    cout << steps.size() << endl;
    REP (x, (int)steps.size()) {
        cout << steps[x].size() << " ";
        REP (i, (int)steps[x].size()) {
            cout << steps[x][i] << " ";
        } cout << "\n";
    } 
}
