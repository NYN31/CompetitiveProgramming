#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

const ll lm = 2e5+5, inf = 1e18 ;
vector <pair<ll, ll> > arr ;
ll n, dp[lm + 5], start[lm + 5] ;

ll go(ll pos) {
    if(pos >= n) return 0 ;
    ll &ret = dp[pos] ;
    if(ret != -1) return ret ;
    ll nxt, f = arr[pos].ff, s = arr[pos].ss ;
    nxt = lower_bound(start, start+n, s) - start ;
    return ret = max(go(pos + 1), go(nxt) + 1) ;
}

void solve() {
    cin >> n ;
    for(int i=0; i<n; i++) {
        ll a, b ; cin >> a >> b ;
        arr.pb({a, b}) ;
    }
    sort(arr.begin(), arr.end()) ;
    for(int i=0; i<arr.size(); i++) start[i] = arr[i].ff ;

    memset(dp, -1, sizeof dp) ;
    ll ans = go(0) ;
    cout << ans << nl ;
}

int main() {
    int t = 1, no = 1;
    while(t--) {
        solve() ;
    }
    return 0;
}


