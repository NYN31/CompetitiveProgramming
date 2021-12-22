/// Solution 1 : O(n) solution

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, diff = 0 ; 
    cin >> n ;
    vector <int> arr(n + 1) ;
    vector <int> arr_min(n + 1) ;
    for(int i=1; i<=n; i++) cin >> arr[i] ;
    int mn = arr[1] ;
    for(int i=1; i<=n; i++) {
        arr_min[i] = min(mn, arr[i]) ;
        mn = arr_min[i] ;
    }
    for(int i=1; i<=n; i++) {
        if(diff < arr[i] - arr_min[i]) {
            diff = arr[i] - arr_min[i] ;
        }
    }
    cout << diff << endl ;
}  
int main() {
    int t = 1, no = 0;
    while(t--) {
        solve();
    }
    return 0;
}

