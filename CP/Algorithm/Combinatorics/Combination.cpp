/*
    ---> Finding nCr with different constraints
    problem 0:
    problem 1: n <= 10^3, r <= 10^3, p(prime or not prime)
    problem 2: n <= 10^5, r <= 10^5, p(prime)
    problem 3: n <= 10^9, r <= 10^5, p(prime)
    problem 4: n <= 10^9, r <= 10^9, p <= 10^7 (prime)

*/


/***
      problem 0: an efficient algorithm to find nCr
***/

ll nCr(int n, int r) {
      if(n - r < r) r = n - r ;
      ll p = 1, k = 1 ;
      if(r == 0) return 1 ;
      else {
            while(r != 0) {
                  p *= n, k *= r ;
                  ll g = __gcd(p, k) ;
                  p /= g, k /= g ;
                  n -= 1, r -= 1 ;
            }
            return p ;
      }
}

/*
    problem 1: n <= 10^3, r <= 10^3, p(prime or not prime)
               Its simple DP problem.
*/
ll const lm = 1005 ;
ll dp[lm][lm] , p;

ll nCr(ll n, ll r ) {
    if(r == 0 || r == n) return 1 ;
    ll &ret = dp[n][r] ;
    if(ret != -1) return ret ;
    return ret = (nCr(n-1, r-1) % p + nCr(n-1, r) % p ) % p ;
}

int main() {
    ll n, r ;
    cin >> n >> r >> p ;
    memset(dp, -1, sizeof dp) ;
    ll ans = nCr(n, r) ;
    cout << ans << endl ;
    return 0;
}

/*
    problem 2: n <= 10^5, r <= 10^5, p(prime)


*/

ll const lm = 1e5+5;
ll fact[lm], inv[lm], p ;

ll bigmod ( ll a, ll b) {
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
    return (((fact[n]*inv[n-r]) % p)*inv[r]) % p ; // nCr = n!/( (n-r)!*r! )
}

void solve() {
    ll n , r, ans ;
    cin >> n >> r >> p ;
    preCal(n) ;
    ans = nCr(n, r) ;
    cout << ans << endl ;
}

/*
    problem 3: n <= 10^9, r <= 10^5, p(prime)

            formula = n! / (r! * (n - r)!)
                    = (1 * 2 * 3 * ... * (n-r) * (n-r+1) * (n-r+2) *...* n) /
                      ( (1 * 2 * 3 *...* r) * (1 * 2 * 3 *...* (n - r)) )
                    = ( (n-r+1) * (n-r+2) *...* n ) / (1 * 2 * 3 *...* r)
*/

ll const lm = 1e5+5;
ll fact[lm], inv[lm], p ;

ll bigmod ( ll a, ll b) {
    ll res = 1 % p, x = a % p;
    while ( b ) {
        if ( b & 1 ) res = ( res * x ) % p ;
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

void solve() {
    ll n , r, ans = 1;
    cin >> n >> r >> p ;
    preCal(n) ;
    for(ll i=n-r+1; i<=n; i++) {
        ans = (ans * i) % p ;
    }
    ans = (ans * inv[r]) % p ;
    cout << ans << endl ;
}


/*
    problem 4: n <= 10^9, r <= 10^9, p <= 10^6 (prime)

        Here, first we have to reform n and r in base p.
        Then we can find out nCr of n and r modulus p.

        Example: n = 31, r = 5

*/


void solve() {
    ll n , r, ans = 1;
    cin >> n >> r >> p ;
    preCal(n) ;
    ll n1 = n, r1 = r ;
    vector <int> arrn, arrr ;
    while(n1) {
        arrn.pb(n1 % p) ;
        n1 /= p ;
    }
    while(r1) {
        arrr.pb(r1 % p) ;
        r1 /= p ;
    }
    for(int i=0; i<min(arrn.size(), arrr.size()); i++) {
        ans = (ans * nCr(arrn[i], arrr[i])) % p;
    }
    cout << ans << endl ;
}
