#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int n,k;
int val[55],coin[55];
int dp[55][1010];

int solve(int in,int rem){
    if(rem<0) return 0;
    if(in==n){
        if(rem==0) return 1;
        else return 0;
    }
    if(dp[in][rem]!=-1) return dp[in][rem];
    int ans=0;
    for(int i=0;i<=coin[in];i++){
        ans=(ans%mod + solve(in+1,rem-(i*val[in]))%mod)%mod;
    }
    dp[in][rem]=ans;
    return ans;
}
int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) cin>>coin[i];

        int ans=solve(0,k);
        cout<<"Case "<<++no<<": "<<ans<<endl;
    }
}

/*
2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1
*/
