#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
    ll n ; cin >> n ;
    vector <ll> arr;
    for(int i=0; i<n; i++) {
        ll a ; cin >> a;
        arr.pb(a) ;
    }
    reverse(arr.begin(), arr.end()) ;
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
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