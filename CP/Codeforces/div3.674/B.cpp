#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


void solve() {
    int n, m, cnt = 0 ; cin >> n >> m ;
    int mat[2][2] ;
    bool flag = false ;
    for(int i=0; i<n; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                cin >> mat[j][k] ;
            }
        }
        if(mat[0][1] == mat[1][0]) {
            flag = true ;
            cnt += 1 ;
        }
    }
    if(flag && m % 2 == 0) cout << "YES" << endl ;
    else cout << "NO" << endl ;
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

