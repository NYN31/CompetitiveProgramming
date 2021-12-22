// Coin change problem

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10100
ll binpow(ll n, ll p) {if(p==0) return 1LL;if(p%2==0){ll res=binpow(n,p/2);return res*res;}return n*binpow(n,p-1);}

int coin[30];
ll dp[30][sz];

ll solve(int in, int rem){
    if(rem<=0){
        if(rem==0) return 1;
        else return 0;
    }
    if(dp[in][rem]!=-1) return dp[in][rem];
    ll ans=0;
    for(int i=in;i<=21;i++){
        ans+=solve(i,rem-coin[i]);
    }
    dp[in][rem]=ans;
    return ans;
}
int main(){
    for(int i=1;i<=21;i++) coin[i]=binpow(i,3);
    int n;
    
    while(cin>>n){
        memset(dp,-1,sizeof dp);
        ll ans=solve(1,n);
        cout<<ans<<endl;
    }
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10100
ll binpow(ll n, ll p) {if(p==0) return 1LL;if(p%2==0){ll res=binpow(n,p/2);return res*res;}return n*binpow(n,p-1);}

int coin[30];
ll dp[sz][sz];

ll solve(int in, int rem){
    if(in>21){
        if(rem==0) return 1;
        else return 0;
    }
    if(dp[in][rem]!=-1) return dp[in][rem];
    ll ans=0;
    if(rem-coin[in]>=0) ans+=solve(in,rem-coin[in]);
    ans+=solve(in+1,rem);
    dp[in][rem]=ans;
    return ans;
}
int main(){
    for(int i=1;i<=22;i++) coin[i]=binpow(i,3);
    int n;
    memset(dp,-1,sizeof dp);
    while(cin>>n){
        ll ans=solve(1,n);
        cout<<ans<<endl;
    }
    return 0;
}

*/
