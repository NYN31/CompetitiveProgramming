/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

/***
void solve() {
      ll n ; cin >> n ;
      ll val = n & (n - 1) ;
      if(val != 0) cout << "YES" << nl ;
      else cout << "NO" << nl ;
}
***/
void solve() {
      ll n ; cin >> n ;
      ll lg = log2(n) ;
      if((1LL << lg) == n) cout << "NO" << nl ;
      else cout << "YES" << nl ;
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
