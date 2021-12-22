#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int const N = 505;
int const M = 62650;
int const mod = 1e9+7;
 
int n,tot;
int dp[N][M];
 
int call(int i, int sum) {
    if(i == n) return sum == tot;
    int &ret = dp[i][sum];
    if(ret != -1) return ret;
    int ans = 0;
    if(sum+i<=tot) ans = call(i+1, sum+i);
    ans += call(i+1,sum);
    ans %= mod;
    ret = ans;
    return ret;
}
 
 
int main(){
    cin>>n;
    tot = n*(n+1)/2;
    if(tot & 1) cout<<"0\n";
    else{
        tot /= 2;
        memset(dp,-1,sizeof dp);
        int ans = call(1,0);
        //if(ans<0) ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}
