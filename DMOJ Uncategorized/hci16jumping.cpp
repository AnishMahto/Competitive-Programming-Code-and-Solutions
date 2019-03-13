#include <iostream>
#include <cstring>
#include <queue>
#define maxn 2002
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define s(x) ((x)*(x))
using namespace std;
ll n,c,dp[maxn][maxn],ans;
string rock[maxn];
inline double slope(pll a,pll b){
    return (double)(a.second-b.second)/(double)(a.first-b.first);
}
int main(){
    cin.tie(0);cin.sync_with_stdio(0);
    memset(dp,0x3f,sizeof dp);memset(&ans,0x3f,sizeof ans);
    cin>>n>>c;
    for(ll i=1;i<=c;i++){
        cin>>rock[i];
    }
    for(ll i=1;i<=c;i++){
        if(rock[i][0]=='1'){
            dp[0][i]=0;
        }
    }
    if(n==1){
        cout<<"0\n";return 0;
    }
    for(ll i=1;i<n;i++){
        deque<pll>mono;
        for(ll k=1;k<=c;k++){
            if(rock[k][i-1]=='1'){
                pll cur=mp(k,k*k + dp[i-1][k]);
                while(mono.size() >= 2 && slope(cur, mono.back()) < slope (mono[mono.size()-2], mono.back())) {
                    mono.pop_back();
                }
                mono.push_back(cur);
            }
        }
        for(ll k=1;k<=c;k++){
            if(rock[k][i]=='1'){
                while (mono.size() >= 2 && slope(mono.front(), mono[1]) <= 2*k) {
                    mono.pop_front();
                }
                dp[i][k] = mono.front().second-s(mono.front().first) + s(k-mono.front().first);
            }
        }
    }
    for(ll i=1;i<=c;i++){
        if(rock[i][n-1]=='1'){
            ans=min(ans,dp[n-1][i]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
