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
ll arr[5010],dp[5010][5010];
 
ll call(int i,int j,int cnt) {
    if(i>j) return INT_MIN;
    if(i==j) {
        if(cnt%2==0) return 0;
        else return arr[j];
    }
    ll &ret = dp[i][j];
    if(ret != -1) return ret;
    ll x1,x2;
    if(cnt%2==1) {
        x1 = call(i,j-1,cnt+1)+arr[j];
        x2 = call(i+1,j,cnt+1)+arr[i];
        ret = max(x1,x2);
    }else{
        x1 = call(i,j-1,cnt+1);
        x2 = call(i+1,j,cnt+1);
        ret = min(x1,x2);
    }
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
