
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const ll lm = 55, inf = 1e18 ;
ll len, points ;
ll cuts[lm+5], dp[lm+5][lm+5];

ll go(ll idx, ll jdx, ll l, ll r) {
    if(idx < 0 || jdx >= points || idx > jdx) return 0 ;
    if(idx == jdx) return (r - l) ;
    ll &ret = dp[idx][jdx] ;
    if(ret != -1) return ret ;
    ll ans = inf ;
    for(ll i=idx; i<=jdx; i++) {
        ans = min(ans, (r - l) + go(idx, i-1, l, cuts[i])  + go(i+1, jdx, cuts[i], r)) ;
    }
    ret = ans ; return ret ;
}

void solve() {
    cin >> points ;
    for(int i=0; i<points; i++) cin >> cuts[i] ;
    sort(cuts, cuts+points) ;
    memset(dp, -1, sizeof dp) ;
    ll ans = go(0, points-1, 0, len) ;
    cout << "The minimum cutting is " << ans << "." << nl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin >> t;
    while(cin >> len && len != 0) {
        solve() ;
    }
    return 0;
}

