#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 10300

ll n,arr[sz];
ll dp[sz];

ll solve(int in){
    if(in >= n) return 0;
    if(dp[in] != -1) return dp[in];
    ll p,q;
    p=arr[in]+solve(in+2);
    q=solve(in+1);
    dp[in]=max(p,q);
    return dp[in];
}


int main()
{
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        ll ans=solve(0);
        cout<<"Case "<<++no<<": "<<ans<<endl;
    }
    return 0;
}


/*
10
5
1 2 3 4 5
4
1 2 3 4
8
1 2 3 4 5 6 7 8
4
1 2 3 4

9
6
20
6
*/
