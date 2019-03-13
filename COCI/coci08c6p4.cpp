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
    int n, cur;
    si (n);
    vector < vi > rem (3);
    deque <int> ans;
    REP (x, n) {
        si (cur);
        rem[cur%3].pb (cur);
    }
    if (rem[0].size() == 0) {
        if (rem[1].size() != 0 && rem[2].size() != 0) {
            cout << "impossible\n";
        } else {
            REP (x, (int)rem[1].size()) {
                cout << rem[1][x] << " ";
            }
            REP (x, (int)rem[2].size()) {
                cout << rem[2][x] << " ";
            }
        }
    } else if (rem[0].size()==1) {
        REP (x, (int)rem[1].size()) {
            cout << rem[1][x] << " ";
        }
        cout << rem[0][0] << " ";
        REP (x, (int)rem[2].size()) {
            cout << rem[2][x] << " ";
        }
    } else {
        REP (x, (int)rem[0].size()) {
            if (x==0) {
                if (rem[1].size() > 0) {
                    ans.pb (rem[1].back());
                    rem[1].pop_back();
                    ans.pb (rem[0][x]);
                } else {
                    ans.pb (rem[0][x]);
                }
            } else if (x==1 && rem[2].size() > 0) {
                if (rem[2].size() > 0) {
                    ans.pb (rem[2].back());
                    rem[2].pop_back();
                    ans.pb (rem[0][x]);
                }
            } else {
                if (rem[1].size() > 0) {
                    ans.pb (rem[1].back());
                    rem[1].pop_back();
                    ans.pb (rem[0][x]);
                } else if (rem[2].size() > 0) {
                    ans.pb (rem[2].back());
                    rem[2].pop_back();
                    ans.pb (rem[0][x]);
                } else {
                    if (ans.front()%3 != 0) {
                        ans.push_front(rem[0][x]);
                    } else {
                        cout << "impossible\n";
                        return 0;
                    }
                }
            }
        }
        int tot = 0;
        REP (x, (int)ans.size()) {
            if (ans[x]%3 == 1) {
                while (rem[1].size() > 0) {
                    cout << rem[1].back() << " ";
                    rem[1].pop_back();
                    tot++;
                }
            } else if (ans[x]%3 == 2) {
                while (rem[2].size() > 0) {
                    cout << rem[2].back() << " ";
                    rem[2].pop_back();
                    tot++;
                }
            }
            tot++;
            cout << ans[x] << " ";
        } pnl;
    }
    
}
