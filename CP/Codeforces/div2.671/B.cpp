#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
    ll n ; cin >> n ;
    ll twosPow , nC2 , ans = 0 ;
    for(int i=1; i<=30; i++) {
        twosPow = (1LL << i) - 1LL ;
        nC2 = twosPow * (twosPow + 1) / 2LL ;
        if(n - nC2 < 0) break ;
        ans += 1 ;
        n -= nC2 ;
    }
    cout << ans << '\n' ;
}  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

