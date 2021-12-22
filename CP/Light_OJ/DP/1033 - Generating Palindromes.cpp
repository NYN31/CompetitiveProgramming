/*
If i>j then return 0
if i==j then return 1
if str[i]==str[j] then return fn(i+1,j-1)+2 // thats mean we include first and last character
if str[i]!=str[j] then ruturn max(fn(i+1,j),fn(i,j-1))
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 150
ll dp[sz][sz],n;
string str;

int solve(int i,int j){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    else if(str[i]==str[j])
        dp[i][j]=solve(i+1,j-1)+2;
    else if(str[i]!=str[j])
        dp[i][j]=max(solve(i+1,j),solve(i,j-1));
    return dp[i][j];
}

int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>str;
        memset(dp,-1,sizeof dp);
        int n=str.size();
        int ans=solve(0,n-1);
        cout<<"Case "<<++no<<": "<<n-ans<<endl;
    }
}
