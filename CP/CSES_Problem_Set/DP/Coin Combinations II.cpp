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
 
int main()
{
    BeatMeScanf;
    int n,x;
    cin>>n>>x;
    int coins[n+5];
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins,coins+n);
    int dp[x+5];
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for(int i=0;i<n;i++) {
        for(int j=coins[i];j<=x;j++) {
            dp[j]=(dp[j]+dp[j-coins[i]])%mod;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
