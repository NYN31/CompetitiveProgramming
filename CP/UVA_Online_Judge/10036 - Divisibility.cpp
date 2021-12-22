#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const ll lm = 10005 ;
const ll lm2 = 105 ;
ll arr[lm + 5], n, k, dp[lm + 5][lm2 + 5][2] ;
vector <ll> dv ;
ll go(ll pos, ll mod, ll sign) {
    if(pos >= n) {
        if(mod == 0) return 1LL ;
        else return 0LL ;
    }
    ll &ret = dp[pos][mod][sign] ;
    if(ret != -1) return ret ;
    ret = go(pos + 1, (mod + arr[pos]) % k, 1) ;
    ret |= go(pos + 1, (mod - arr[pos]%k) % k, 0) ;
    return ret ;
}

void solve() {
    cin >> n >> k ;
    for(int i=0; i<n; i++) cin >> arr[i] ;
    memset(dp, -1, sizeof dp) ;
    ll ans = go(1, arr[0] % k, 1) ;
    if(ans == 1) cout << "Divisible" << endl ;
    else cout << "Not divisible" << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
