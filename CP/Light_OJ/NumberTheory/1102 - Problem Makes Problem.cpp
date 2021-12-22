/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 2e6+5;
const ll mod = 1e9+7;
ll inv[lm+5], fact[lm+5];
int no = 0 ;

ll bigmod(ll a, ll p) {
    if(p == 0) return 1%mod;
    else if(p&1) {
        ll ret = bigmod(a, p-1) ;
        return (a * ret) % mod ;
    }else {
        ll ret = bigmod(a, p/2) ;
        return (ret * ret) % mod ;
    }
}

void precal() {
    fact[0] = 1;
    for(ll i=1; i<=lm; i++) fact[i] = (fact[i-1] * i) % mod ;
    inv[lm] = bigmod(fact[lm], mod-2) ;
    for(int i=lm-1; i>=0; --i) inv[i] = (inv[i+1] * (i+1)) % mod ;
}
inline ll nCr(ll n, ll r) {
    if(r >= n) return (n == r) ;
    else return (((fact[n] * inv[n-r]) % mod) * inv[r] ) % mod ;
}

void solve() {
    ll n, r ; cin >> n >> r ;
    ll ans = nCr(n+r-1, r-1) ;
    cout << "Case " << ++no << ": " << ans << nl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int t = 1;
        cin >> t ;
        precal() ;
        while(t--) {
                solve();
        }
        return 0;
}
