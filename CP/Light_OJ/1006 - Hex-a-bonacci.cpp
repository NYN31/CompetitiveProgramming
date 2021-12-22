#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define mod 10000007
#define sz 10050
int dp[sz];
int a,b,c,d,e,f,total;
int fn(int n){
    if(n==0) return a%mod;
    if(n==1) return b%mod;
    if(n==2) return c%mod;
    if(n==3) return d%mod;
    if(n==4) return e%mod;
    if(n==5) return f%mod;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    total=(fn(n-1)%mod+fn(n-2)%mod+fn(n-3)%mod+fn(n-4)%mod+fn(n-5)%mod+fn(n-6)%mod)%mod;
    dp[n]=total;
    return dp[n];
}
int main() {
    int n,no=0,t;
    cin>>t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c>>d>>e>>f>>n;
        printf("Case %d: %d\n",++no,fn(n)%mod);
    }
    return 0;
}
 
