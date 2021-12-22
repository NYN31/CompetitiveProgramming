
/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
      ll n, d, r ; cin >> n ;
      d = n / 2020 ;
      r = n % 2020 ;
      if(d >= r) cout << "YES" << nl ;
      else cout << "NO" << nl ;
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
