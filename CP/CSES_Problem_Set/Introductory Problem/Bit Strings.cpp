#include<bits/stdc++.h>
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
 
ll bigmod(ll a,ll p,ll m) {
    if(p==0) return 1;
    if(p%2==0) {
        ll ret = bigmod(a,p/2,m);
        return (ret*ret)%m;
    }else{
        ll ret = bigmod(a,p-1,m);
        return (a*ret)%m;
    }
}
 
int main()
{
    BeatMeScanf;
    ll n;
    cin>>n;
    ll ans = bigmod(2,n,mod);
    cout<<ans<<endl;
    return 0;
}
