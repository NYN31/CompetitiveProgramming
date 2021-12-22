#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

void solve() {
    int n , k ; cin >> n >> k ;
    vector <ll> arr ;
    for(int i=0; i<(n*k); i++) {
        ll a ; cin >> a ;
        arr.pb(a) ;
    }
    ll pos = (n / 2), sum = 0 ;
    sort(arr.rbegin(), arr.rend()) ;

    for(int i=pos; i<arr.size() && k; i+=(pos+1)) {
        sum += arr[i] ; k -= 1 ;
    }
    cout << sum << endl ;
}

int main() {
    int t = 1, no = 0;
    cin >> t ;
    while(t--) {
        solve();
    }
    return 0;
}
