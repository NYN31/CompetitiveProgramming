#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n' 

void solve() {
    int n, lo=-1, hi=-1, k=1 ; cin >> n ;
    vector <int> arr(n) ;
    for(int i=0; i<n; i++) {
        cin >> arr[i] ;
        if(arr[i] == 1 && k) lo = i, k = 0 ;
    }
    for(int i=n-1; i>=0; i--) {
        if(arr[i] == 1) {
            hi = i ;
            break ;
        }
    }
    if(lo == -1 && hi == -1) cout << 0 << nl ;
    else {
        int gap = 0 ;
        for(int i=lo; i<=hi; i++) {
            if(arr[i] == 0) gap += 1 ;
        }
        cout << gap << nl ;
    }
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

