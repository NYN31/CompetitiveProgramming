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
string str[sz];
ll dp[sz][sz],n;
 
ll solve(int i,int j) {
    if(i>=0 && i<n && j>=0 && j<n && str[i][j]!='*') {
        if(i==n-1 && j==n-1 && str[i][j]=='?')
            return 1LL;
        if(dp[i][j] != -1) return dp[i][j];
        ll ans = 0;
        ans = (solve(i+1,j)%mod+solve(i,j+1)%mod)%mod;
        dp[i][j]=ans;
        return ans;
    }
    else return 0LL;
}
 
int main()
{
    BeatMeScanf;
    cin>>n;
    for(int i=0;i<n;i++) cin>>str[i];
    if(str[0][0]=='*' || str[n-1][n-1]=='*') {
        cout<<0<<endl;
        return 0;
    }
    str[n-1][n-1]='?';
    memset(dp,-1,sizeof dp);
    ll ans = solve(0,0);
    cout<<ans<<endl;
    return 0;
}
