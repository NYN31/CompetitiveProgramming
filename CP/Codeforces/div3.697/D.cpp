/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

void solve() {
      ll n, m; cin >> n >> m ;
      vector <ll> a(n), b[3], scum[3] ;
      for(int i=0; i<n; i++) cin >> a[i] ;
      for(int i=0; i<n; i++) {
            int x ; cin >> x ;
            b[x].pb(a[i]) ;
      }
      for(int i=1; i<=2; i++) {
            sort(b[i].rbegin(), b[i].rend()) ;
            ll s = 0;
            scum[i].pb(0) ;
            for(int j=0; j<b[i].size(); j++) {
                  s += b[i][j] ;
                  scum[i].pb(s) ;
            }
      }
      ll ans = 5 * n ;
      for(int i=0; i<scum[1].size(); i++) {
            int j = lower_bound(scum[2].begin(), scum[2].end(), m-scum[1][i]) - scum[2].begin() ;
            if(j < scum[2].size()) {
                  ans = min(ans, i + 2LL*j) ;
            }
      }
      if(ans == 5 * n) ans = -1 ;
      cout << ans << endl ;
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
