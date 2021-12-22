#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1 << 28
#define sz 65

string s1;
ll dp[sz][sz];

ll solve(ll i,ll j){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans=0;
    ans=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
    if(s1[i]==s1[j]) ans+=solve(i+1,j-1)+1;
    dp[i][j]=ans;
    return ans;
}

int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>s1;
        int n=s1.size()-1;
        memset(dp,-1,sizeof dp);
        ll ans=solve(0,n);
        cout<<"Case "<<++no<<": "<<ans<<endl;
    }

    return 0;
}
