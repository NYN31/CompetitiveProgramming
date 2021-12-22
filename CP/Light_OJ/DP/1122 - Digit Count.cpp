/***
    Its a digit DP problem
***/

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
ll m,n;
vector<ll>s;
ll dp[12][12];

ll go(ll pos, ll prev) {
    if(pos == n) return 1;
    ll &ret = dp[pos][prev];
    if(ret != -1) return ret;
    ll ans = 0;
    for(int i=0;i<s.size();i++) {
        if(prev == 0 || abs(prev-s[i])<=2)
            ans += go(pos+1, s[i]);
    }
    ret = ans;
    return ret;
}

int main()
{
    BeatMeScanf;
    int t, no = 0;  cin>>t;
    while(t--) {
        cin>>m>>n;
        for(int i=0;i<m;i++) {
            ll a; cin>>a;
            s.pb(a);
        }
        ll ans = 0;
        memset(dp, -1, sizeof dp);
        ans = go(0, 0);
        cout<<"Case "<<++no<<": "<<ans<<endl;
        s.clear();
    }
    return 0;
}
