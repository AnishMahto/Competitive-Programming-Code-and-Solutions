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
char _;
using namespace std;
void PRINT (int x, int y) { for (int i = y-1; i >= 0; i--) { cout << READ(x,i); } cout << endl; }

string ans = "";

void printAns () {
    if (ans.length()==0) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}

int main () {
    fastCin;
    int n, cnt[100001][27] = {0}, globalMin[27], ptr[100001] = {0}, len[100001];
    cin >> n;
    vector < string > str (n);
    REP (x, n) {
        cin >> str[x];
        len[x] = (int)str[x].length()-1;
        REP (i, (int)len[x]+1) {
            cnt[x][str[x][i] - (int)'a']++;
        }
    }
    while (true) {
        CL (globalMin, -1);
        REP (x, n) {
            if (ptr[x] > len[x]) {
                printAns();
                return 0;
            }
            FORI (i, 97, 122) {
                if (globalMin[i-97] == -1) {
                    globalMin[i-97] = cnt[x][i-97];
                } else {
                    globalMin[i-97] = min (globalMin[i-97], cnt[x][i-97]);
                }
            }
        }
        for (int i=122; i >= 97; i--) {
            if (globalMin[i-97] > 0) {
                REP (x, globalMin[i-97]) {
                    ans += (char)i;
                }
                REP (x, n) {
                    int tot = globalMin[i-97];
                    while (tot > 0) {
                        if ((int)str[x][ptr[x]] == i) {
                            tot--;
                        }
                        cnt[x][(int)str[x][ptr[x]] - (int)'a']--;
                        ptr[x]++;
                    }
                }
                break;
            } else if (i==97) {
                printAns();
                return 0;
            }
        }
    }
    printAns();
    return 0;
}
