#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

void solve() {
    int n ; cin >> n;
    vector <int> arr , brr ;
    for(int i=0; i<n ;i++) {
        int a ; cin >> a;
        arr.pb(a) ;
        brr.pb(a) ;
    }
    sort(brr.begin() , brr.end()) ;

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] != brr[i]) cnt += 1;
    }
    if(cnt <=2) cout << "YES" << endl;
    else cout << "NO" << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
