#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1000100
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
const int mod = 1e9+7;
ll dp[sz];
ll n;
 
ll solve(ll n) {
    if(n==0) return 1;
    if(n<0) return 0;
    ll &ret = dp[n];
    if(ret != -1) return ret;
    ll ans=0;
    for(int i=1;i<=6;i++) {
        if(n<i) continue;
        ans =(ans + solve(n-i) )%mod;
    }
    dp[n]=ans;
    return ans;
}
 
int main()
{
    BeatMeScanf;
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll ans = solve(n);
    cout<<ans<<endl;
    return 0;
}
