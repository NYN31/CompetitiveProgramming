#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

ll const mod = 1e9+7 ;
int no;

ll bigmod(ll a, ll p) {
    if(p == 0) return 1LL ;
    else if(p&1) {
        ll ret = bigmod(a, p-1) ;
        return (a * ret) % mod ;
    }else{
        ll ret = bigmod(a, p/2) ;
        return (ret * ret) % mod ;
    }
}

void solve() {
        ll n ; cin >> n ;
        ll ans = ((((n%mod) * (n+1 % mod)) %mod) * ((n+2)%mod)) %mod ;
        ans = (2 * ( (ans * bigmod(6, mod-2)) ) % mod) % mod ;
        cout << "Case " << ++no << ": " << ans << nl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int t = 1, no = 0;
        cin >> t ;
        while(t--) {
                solve();
        }
