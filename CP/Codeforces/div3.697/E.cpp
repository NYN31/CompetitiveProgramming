/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 1e3 + 9, p = 1e9 + 7 ;
ll fact[lm+1], inv[lm+1], n, k;

ll bigmod (ll a, ll b) {
    ll res = 1 % p, x = a % p;
    while ( b ) {
        if ( b & 1 ) res = ( res * x ) % p;
        x = ( x * x ) % p;
        b >>= 1;
    }
    return res;
}

void preCal(ll n){
    fact[0] = 1 ;
    for(ll i=1; i<=n; i++) fact[i] = (fact[i-1] * i) % p ;
    inv[n] = bigmod(fact[n], p-2) ;
    for(ll i=n-1; i>=0; i--) inv[i] = (inv[i+1] * (i+1)) % p ;
}

inline ll nCr(ll n, ll r){
    if(r>=n) return (n==r) ;
    return (((fact[n]*inv[n-r]) % p)*inv[r]) % p ;
}

void solve() {
      cin >> n >> k;
      preCal(n) ;
      vector <int> arr(n) ;
      for(int i=0; i<n; i++) cin >> arr[i] ;
      sort(arr.rbegin(), arr.rend()) ;
      int last = arr[k-1] ;
      int x = 0, y = 0 ;
      for(int i=0; i<n; i++) {
            if(arr[i] == last) x += 1 ;
            if(arr[i] == last && i < k) y += 1 ;
      }
      cout << nCr(x, y) << endl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int tt = 1, no = 0;
        cin >> tt ;
        while(tt--) {
                solve();
        }
        return 0;
}
