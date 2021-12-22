#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
    int n, k ; cin >> n >> k; 
    vector <int> arr(n) ;
    set <int> st ;
    for(int i=0; i<n; i++) {
        cin >> arr[i] ;
        st.insert( arr[i] ) ;
    }
    if(st.size() <= k) cout << 1 << '\n' ;
    else if(1 < st.size() && k == 1) cout << -1 << '\n' ;
    else {
        int ans = 1, diff = st.size() - k ;
        while( diff > 0 ) {
            ans += 1 ;
            diff = diff - k + 1 ;
        } 
        cout << ans << '\n' ;
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

