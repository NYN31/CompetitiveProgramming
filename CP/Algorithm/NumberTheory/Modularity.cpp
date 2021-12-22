


/****
    Problem: find a^b using Big Mod for very big number
            of a and b with complexity O(log(n)).
***/


ll bigmod(ll a, ll p, ll mod) {
    if(p == 0) return 1LL ;
    else if(p % 2 == 0) {
        ll ret = bigmod(a, p/2, mod) ;
        return (ret * ret) % mod ;
    }
    else {
        ll ret = bigmod(a, p-1, mod) ;
        return (ret * a) % mod ;
    }
}

/***
    problem: multiplication via addition using Big Mod algorithm with
            complexity O(log(n)).
    suppose you have two number which are 10^12 and 10^12. You have to
    find out the multiplication of these two number. (mod with 10^15).

***/
ll bigmod(ll a, ll p, ll mod) {
    if(p == 0) return 1LL ;
    else if(p % 2 == 0) {
        ll ret = bigmod(a, p/2, mod) ;
        return (ret * ret) % mod ;
    }
    else {
        ll ret = bigmod(a, p-1, mod) ;
        return (ret * a) % mod ;
    }
}

ll bigmul(ll ab, ll cd, ll m) {
    if(cd == 0) return 0LL ;
    else if(cd % 2 == 0) {
        ll ret = bigmul(ab, cd / 2 , m) ;
        return (ret + ret) % m ;
    }
    else {
        ll ret = bigmul(ab, cd - 1, m) ;
        return (ret + ab) % m ;
    }
}
void solve() {
    ll a, b, c, d, m, ans;
    cin >> a >> b >> c >> d >> m ;
    ll ab = bigmod(a, b, m) ;
    ll cd = bigmod(c, d, m) ;
    cout << ab << " " << cd << endl ;
    ans = bigmul(ab, cd, m) ;
    cout << ans << endl ;
}
