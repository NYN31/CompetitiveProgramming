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
ll arr[2010],dp[2010][2010];

ll call(int i,int j,int cnt) {
    if(i>j) return INT_MAX;
    if(i==j) return arr[i]*cnt;
    ll &ret = dp[i][j];
    if(ret != -1) return ret;
    ll x1,x2;
    x1 = call(i,j-1,cnt+1)+arr[j]*cnt;
    x2 = call(i+1,j,cnt+1)+arr[i]*cnt;
    ret = min(x1,x2);
    dp[i][j]=ret;
    return ret;
}

int main()
{
    BeatMeScanf;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    ll ans = call(1,n,1);
    cout<<ans<<endl;
    return 0;
}
