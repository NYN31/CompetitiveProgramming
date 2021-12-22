/***
      Solution details: https://titanwolf.org/Network/Articles/Article?AID=16f12b81-33d4-42ff-b620-d69182aa36ea#gsc.tab=0
      Topic: Caylay's Theorem
***/


/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

int cs ;
const ll m = 2000000011 ;

ll bigpow(ll a, ll p) {
      if(p == 0) return 1LL ;
      else if(p & 1) {
            ll ret = bigpow(a, p - 1) ;
            return (a * ret) % m ;
      }
      else {
            ll ret = bigpow(a, p / 2) ;
            return (ret * ret) % m ;
      }
}

void solve() {
     ll n ; cin >> n ;
     ll ans = (n == 1) ? 1 : bigpow(n, n-2) ;
     cout << "Case #" << ++cs << ": " << ans << endl ;
}

int main() {
      int test = 1;
      scanf("%d", &test) ;
      while(test--) {
            solve();
      }
      return 0;
}
