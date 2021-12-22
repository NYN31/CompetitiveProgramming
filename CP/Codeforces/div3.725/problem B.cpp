/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
    int n ; cin >> n ;
    vector <ll> arr;
    ll sum = 0 ;
    for(int i=0; i<n; i++) {
        ll a; cin >> a ;
        arr.pb(a) ;
        sum += a ;
    }
    if(sum % n != 0) cout << -1 << endl ;
    else {
        ll eq = sum / n ;
        ll total = n ;
        for(int i=0; i<n; i++) {
            if(arr[i] <= eq) total -= 1 ;
        }
        cout << total << endl ;
    }
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

