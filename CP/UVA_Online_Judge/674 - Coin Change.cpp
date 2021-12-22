/// REcursive Way

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
int n,k;
int dp[10][7500];
int coin[]={1,5,10,25,50};

int solve(int i,int rem){
    //cout<<i<<" "<<rem<<endl;
    if(i>=5){
        if(rem==0) return 1;
        else return 0;
    }
    if(dp[i][rem]!=-1) return dp[i][rem];
    int ans1=0,ans2=0;
    if(rem-coin[i]>=0) ans1=solve(i,rem-coin[i]);
    ans2=solve(i+1,rem);
    dp[i][rem]=(ans1+ans2);
    return dp[i][rem];
}

int main(){
    memset(dp,-1,sizeof dp);
    while(cin>>k){
        int ans=solve(0,k);
        cout<<ans<<endl;
    }
    return 0;
}


///Iterative Process

// Light OJ Coin Change problem (II)

#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int n,k;
int coin[110],way[110][10100];

int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>coin[i];
        memset(way,0,sizeof way);
        way[0]=1;

        for(int j=0;j<n;j++){
            for(int i=1;i<=k;i++){
                if(i>=coin[j]){
                    way[i]=(way[i]+way[i-coin[j]])%mod;
                }
            }
        }
        cout<<"Case "<<++no<<": "<<way[k]<<endl;
    }
}
