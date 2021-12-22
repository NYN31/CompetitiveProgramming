/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
    int n ; cin >> n ;
    vector <int> arr(n + 1) ;
    for(int i=1; i<=n; i++) cin >> arr[i]  ;
    ll mx = 0, mxp, mn = 10000000, mnp ;
    for(int i=1; i<=n; i++) {
        if(arr[i] > mx) {
            mx = arr[i] ;
            mxp = i ;
        }
        if(arr[i] < mn) {
            mn = arr[i] ;
            mnp = i;
        }
    }

    ll ans = 1000000000 ;
    ans = min(ans, max(mxp, mnp)) ;
    ans = min(ans, n - min(mxp, mnp) + 1) ;
    ans = min(ans, min(mxp, mnp) + (n - max(mxp, mnp) + 1)) ;
    cout << ans << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int test = 1, no = 0;
    cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}

