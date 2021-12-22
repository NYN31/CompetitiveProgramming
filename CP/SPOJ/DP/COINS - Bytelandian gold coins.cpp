#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 1000000
#define sz 1010
 
map<ll,ll>mp;
 
ll solve(ll n){
    if(n==0) return 0;
    if(mp[n]!=0) return mp[n];
    ll ans=n;
    ll ans2;
    ans2=solve(n/2)+solve(n/3)+solve(n/4);
    ans=max(ans,ans2);
    mp[n]=ans;
    return ans;
}
 
int main()
{
    BeatMeScanf;
    ll n;
    while(cin>>n){
        ll ans=solve(n);
        cout<<ans<<endl;
    }
    return 0;
}
 
