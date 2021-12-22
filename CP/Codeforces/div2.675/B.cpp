#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
 
void solve() {
    ll n , m, move = 0 ; cin >> n >> m ;
    ll mat[n+5][m+5], ans[n+5][m+5] ;
    memset(ans, 0, sizeof ans) ;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=m; j++) 
            cin >> mat[i][j] ;
 
    for(int i=1; i<=(n+1)/2; i++) {
        for(int j=1; j<=(m+1)/2; j++) {
            ll a, b, c , d, val ;
            a = mat[i][j], b = mat[i][m-j+1] ;
            c = mat[n-i+1][j], d = mat[n-i+1][m-j+1] ;
            vector <ll> x ;
            x.pb(a), x.pb(b), x.pb(c), x.pb(d) ;
            sort(x.begin(), x.end()) ;
            val = x[2] ;
            ans[i][j] = val, ans[i][m-j+1] = val ;
            ans[n-i+1][j] = val , ans[n-i+1][m-j+1] = val ;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            move += abs(mat[i][j] - ans[i][j]) ;
        }
    }
    cout << move << endl ;
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