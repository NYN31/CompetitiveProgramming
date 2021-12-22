/***
        Online judge: Timus
***/

#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 550
ll dp[sz][sz],n;

ll solve(ll prev,ll rem){
    if(prev!=n && rem==0) return 1;
    if(prev>=rem) return 0;
    if(dp[prev][rem]!=-1) return dp[prev][rem];
    ll ans=0;
    for(ll i=prev+1;i<=rem;i++) ans+=solve(i,rem-i);
    dp[prev][rem]=ans;
    return ans;
}

int main(){
    BeatMeScanf;
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll ans=solve(0,n);
    cout<<ans<<endl;
    return 0;
}



#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

const int mod = 1e9+7;
ll n, dp[505][505];

ll staircase(ll rem, ll last) {
    if(rem<0) return 0;
    if(rem == 0) return 1;
    ll &ret = dp[rem][last];
    if(ret != -1) return ret;
    ll ans = 0;
    for(int i=1;i<rem;i++) {
        ans += staircase(rem-(last+i),last+i);
    }
    dp[rem][last]=ans;
    return ans;
}

int main()
{
    BeatMeScanf;
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll ans = staircase(n, 0);
    cout<<ans<<endl;
    return 0;
}

