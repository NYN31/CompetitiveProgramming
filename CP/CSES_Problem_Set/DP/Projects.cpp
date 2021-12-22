#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

const ll l = 200005 ;
vector <pair<ll, pair<ll, ll> > > arr ;
ll finish[l+5] ;
ll dp[l+5], n ;

ll call(ll pos) {
    if(pos >= n) return 0LL ;
    ll &ret = dp[pos] ;
    if(ret != -1) return ret ;
    ll d1, d2, pf, nxt ;
    d2 = arr[pos].ff, d1 = arr[pos].ss.ff, pf = arr[pos].ss.ss ;
    nxt = upper_bound(finish, finish+n, d2) - finish ;
    return ret = max(call(pos + 1), call(nxt) + pf) ;
}

void solve() {
    cin >> n ;
    for(int i=1; i<=n; i++) {
        ll a, b, c ; cin >> a >> b >> c ;
        arr.pb({a, {b, c}}) ;
    }
    sort(arr.begin(), arr.end()) ;
    for(int i=0; i<arr.size(); i++) {
        swap(arr[i].ff, arr[i].ss.ff) ;
        finish[i] = arr[i].ss.ff ;
    }

    memset(dp, -1, sizeof dp) ;
    ll ans = call(0) ;
    cout << ans << nl ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


