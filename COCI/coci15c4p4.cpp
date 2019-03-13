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

int main () {
    ll n, k, q, a, b;
    sl (n); sl (k); sl (q);
    ll pwr[52], lvl[52] = {0}, up;
    pwr[0] = 1;
    if (k>1) {
        FORI (x, 1, 51) {
            if (longLIMIT::max()/k >= pwr[x-1]) {
                pwr[x] = pwr[x-1]*k;
                up = x;
            } else {
                pwr[x] = -1;
                break;
            }
        }
        lvl[0] = pwr[0];
        FORI (x, 1, up) {
            if (longLIMIT::max()-pwr[x] >= lvl[x-1]) {
                lvl[x] = lvl[x-1] + pwr[x];
            } else {
                lvl[x] = -1;
                break;
            } 
        }
    }
    ll dp[52] = {0}, pos[52] = {0}, lvlA, curPos, lvlB, steps;
    while (q--) {
        sl (a); sl (b);
        if (k==1) {
            printf ("%lld\n", abs(a-b));
        } else {
            CL (dp, -1);
            CL (pos, -1);
            steps = 0;
            FORI (x, 0, up) {
                if (lvl[x] >= a && (x==0 || lvl[x-1] < a)) {
                    lvlA = x;
                    dp[lvlA] = 0;
                    if (x==0) {
                        pos[lvlA] = 1;
                    } else {
                        pos[lvlA] = (a-lvl[lvlA-1]);
                    }
                    break;
                }
            }
            curPos = pos[lvlA]/k;
            if (pos[lvlA]%k!=0) {
                curPos++;
            }
            lvlA--;
            while (lvlA >= 0) {
                dp[lvlA] = dp[lvlA+1]+1;
                pos[lvlA] = curPos;
                if (curPos%k != 0) {
                    curPos = curPos/k + 1;
                } else {
                    curPos = curPos/k;
                }
                lvlA--;
            }
            bool done = false;
            FORI (x, 0, up) {
                if (lvl[x] >= b && (x==0 || lvl[x-1] < b)) {
                    lvlB = x;
                    if (x==0) {
                        curPos = 1;
                    } else {
                        curPos = (b-lvl[lvlB-1]);
                    }
                    if (curPos == pos[lvlB]) {
                        printf ("%lld\n", steps + dp[lvlB]);
                        done = true;
                    }
                    break;
                }
            }
            if (!done) {
                while (lvlB >= 0) {
                    if (curPos == pos[lvlB]) {
                        printf ("%lld\n", steps + dp[lvlB]);
                        break;
                    } else {
                        if (curPos%k==0) {
                            curPos /= k;
                        } else {
                            curPos = curPos/k+1;
                        }
                        lvlB--;
                        steps++;
                    }
                }
            }
        }
    }
}
