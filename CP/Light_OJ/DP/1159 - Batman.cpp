#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1 << 28
#define sz 55

string s1,s2,s3;
int dp[sz][sz][sz];

int solve(int i,int j,int k){
    if(s1[i]=='\0' || s2[j]=='\0' || s3[k]=='\0')
        return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(s1[i]==s2[j] && s2[j]==s3[k] && s3[k]==s1[i])
        return dp[i][j][k]=solve(i+1,j+1,k+1)+1;
    else return dp[i][j][k]=max({solve(i+1,j,k),solve(i,j+1,k),solve(i,j,k+1)});
}

int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>s1>>s2>>s3;
        memset(dp,-1,sizeof dp);
        int ans=solve(0,0,0);
        cout<<"Case "<<++no<<": "<<ans<<endl;
    }

    return 0;
}
