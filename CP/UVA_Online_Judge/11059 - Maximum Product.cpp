#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const ll lm = 20, inf = 1e18 ;
ll n ;
ll arr[lm+2] ;

void solve(ll no) {
    for(int i=0; i<n; i++) cin >> arr[i] ;
    bool flag = false ;
    ll mx = 0 ;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) flag = true ;
        for(int j=i; j<n; j++) {
            ll mult = 1 ;
            for(int k=i; k<=j; k++) mult *= arr[k] ;
            mx = max(mx, mult) ;
        }
    }
    cout << "Case #" << no << ": The maximum product is " << mx << "." << nl << nl ;
}


int main() {
    int t = 1, no = 1;
    while(cin >> n) {
        solve(no) ;
        no += 1 ;
    }
    return 0;
}

/*
3
2 4 -3
5
2 5 -1 2 -1
*/

