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
int n,q,k;
int arr[110];
int dp[110][110][1030];

int call(int pos, int rem, int xr) {
    if(rem == 0) return xr;
    if(pos==n+1) {
        if(rem==0) return xr;
        else return INT_MAX;
    }
    int &ret = dp[pos][rem][xr];
    if(ret != -1) return ret;
    ret = min(call(pos+1,rem,xr), call(pos+1,rem-1,xr^arr[pos]));
    return ret;
}

int main()
{
    BeatMeScanf;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    while(q--){
        cin>>k;
        //memset(dp,-1,sizeof dp);
        int ans = call(1,k,0);
        cout<<ans<<endl;
    }
    return 0;
}
