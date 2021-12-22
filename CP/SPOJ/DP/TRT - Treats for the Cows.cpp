#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int const N = 2005;
ll n, arr[N+5];
ll dp[N+5][N+5];

ll go(int i, int j, int cnt=1) {
    if(i>j) return 0;
    ll &ret = dp[i][j];
    if(ret != -1) return ret;
    ll ans = 0;
    ans = go(i+1, j, cnt+1) + arr[i]*cnt;
    if(i!=j) ans = max(ans, go(i, j-1, cnt+1) + arr[j]*cnt);
    ret = ans; return ret;
}

int main() {
    BeatMeScanf;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp, -1, sizeof dp);
    ll ans = go(0,n-1);
    cout<<ans<<endl;
    return 0;
}

/*
5
1 3 1 5 2
*/
