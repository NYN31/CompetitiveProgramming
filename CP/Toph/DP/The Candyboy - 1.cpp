#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[110];

ll solve(ll n,ll flag=false) {
   // if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n] != -1) return dp[n];
    ll ans=1;
    for(ll i=1;i<=n;i++) {
        if(n-i<0) continue;
        if(n!=i || (n==i && flag))
            ans = max(ans, i*solve(n-i,true));
    }
    dp[n] = ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        memset(dp,-1,sizeof dp);
        ll ans = solve(n);
        cout<<ans<<endl;
    }
    return 0;
}
