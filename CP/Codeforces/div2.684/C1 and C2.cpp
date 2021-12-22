#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

int const lm = 1000 ;
int const lm2 = 20000 ;
int arr[lm+2][lm+2], ans[lm2+2][8], n, m, op;

void update(int x1, int y1, int x2, int y2, int x3, int y3) {
    op += 1 ;
    ans[op][1] = x1, ans[op][2] = y1, ans[op][3] = x2;
    ans[op][4] = y2, ans[op][5] = x3, ans[op][6] = y3 ;
    arr[x1][y1] ^= 1 , arr[x2][y2] ^= 1 , arr[x3][y3] ^= 1 ;
}

void solve() {
    cin >> n >> m ; op = 0 ;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            char ch ; cin >> ch ;
            arr[i][j] = (int)(ch - '0') ;
        }
    }
    for(int j=1; j<=m-2; j++) {
        int i = 1 ;
        while(i <= n) {
            if(arr[i][j] == 0) {i++ ; continue ;}
            else if(i == n) update(i, j, i, j+1, i-1, j+1) ;
            else if(arr[i+1][j] == 1) update(i, j, i+1, j, i+1, j+1) , i += 2 ;
            else update(i, j, i, j+1, i+1, j+1) , i += 1 ;
        }
    }
    for(int i=1; i<=n-1; i++) {
        if(arr[i][m-1]==1 && arr[i][m]==1) update(i, m-1, i, m, i+1, m-1) ;
        else if(arr[i][m-1] == 1) update(i, m-1, i+1, m-1, i+1, m) ;
        else if(arr[i][m] == 1) update(i, m, i+1, m-1, i+1, m) ;
    }
    if (arr[n][m-1] == 1 && arr[n][m] == 1) {
        update(n, m, n-1, m-1, n-1, m);
        update(n-1, m, n, m-1, n-1, m-1);
    } else if (arr[n][m-1] == 1) {
        update(n, m-1, n-1, m-1, n-1, m);
        update(n, m, n-1, m, n, m-1);
        update(n, m-1, n-1, m-1, n, m);
    } else if (arr[n][m] == 1) {
        update(n, m, n-1, m, n, m-1);
        update(n, m, n, m-1, n-1, m-1);
        update(n, m, n-1, m, n-1, m-1);
    }
    cout << op << endl ;
    for(int i=1; i<=op; i++) {
        cout << ans[i][1] << " " << ans[i][2] << " " ;
        cout << ans[i][3] << " " << ans[i][4] << " " ;
        cout << ans[i][5] << " " << ans[i][6] << endl ;
    }
    memset(arr, 0, sizeof arr) ;
    memset(ans, 0, sizeof ans) ;
}

int main() {
    int t = 1, no = 0;
    cin >> t ;
    while(t--) {
        solve();
    }
    return 0;
}
